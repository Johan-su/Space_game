#pragma once
#include "ecs_constants.hpp"
#include "../Memory_arena.hpp"
#include "Entity.hpp"
#include "ecs_assert.hpp"
#include "View_Groups.hpp"

#include <stdio.h>


namespace Ecs
{
    template<typename T>
    struct Component_page // changing variables or order will affect componentManager functions
    {
        size_t entity_count;
        Entity sparse_array[PAGE_SIZE];
        Entity entity_list[PAGE_SIZE];
        T dense_array[PAGE_SIZE];
    };


    template<typename T>
    struct Component_pool // changing variables or order will affect componentManager functions
    {
        size_t page_count;
        size_t entity_count;
        Component_page<T> *component_pages[MAX_PAGE_AMOUNT];
    };



    struct Component_data
    {
        void *component_pools[MAX_COMPONENT_TYPES];

        size_t component_sizes[MAX_COMPONENT_TYPES];
        size_t component_alignments[MAX_COMPONENT_TYPES];

        size_t componentTypesCount;

        bool pool_init[MAX_COMPONENT_TYPES];

    };



    namespace Component_functions 
    {
        void init(Component_data *cdata);

        void destroy_entity(Component_data *cdata, Entity e);

        size_t get_id();

    }


    namespace Component_functions
    {

        template<typename T>
        size_t get_component_id(Component_data *cdata)
        {
            static const size_t id = cdata->componentTypesCount++;
            return id;
        }


        template<typename T>
        void init_component(top_memory_arena *mm, Component_data *cdata)
        {
            const size_t compid = get_component_id<T>(cdata);

            Component_pool<T> *comp_pool = (Component_pool<T>*)cdata->component_pools[compid];

            comp_pool = Arena::top_alloc<Component_pool<T>>(mm);

            comp_pool->page_count = 0;
            comp_pool->entity_count = 0;
            for(size_t i = 0; i < MAX_PAGE_AMOUNT; ++i)
            {
                comp_pool->component_pages[i] = NULL;
            }


            cdata->pool_init[compid]            = true;
            cdata->component_alignments[compid] = alignof(T);
            cdata->component_sizes[compid]      = sizeof(T);
            cdata->component_pools[compid]      = comp_pool;

        }

        template<typename T>
        Component_pool<T> *get_component_pool(Component_data *cdata)
        {
            const size_t compid = get_component_id<T>(cdata);
            ECS_assert(cdata->pool_init[compid], "Component_pool was not initalized");

            Component_pool<T> *comp_pool = (Component_pool<T>*) cdata->component_pools[compid];
            ECS_assert(comp_pool != nullptr, "Component_pool is null");

            return comp_pool;
        }


        template<typename T>
        Component_page<T> *init_page(top_memory_arena *mm, Component_pool<T> *pool, uint32_t page_id)
        {
            ECS_assert(page_id < MAX_PAGE_AMOUNT, "page_id outside legal scope");
            Component_page<T> *page = Arena::top_alloc<Component_page<T>>(mm);

            page->entity_count = 0;
            for(size_t i = 0; i < PAGE_SIZE; ++i)
            {
                page->sparse_array[i] = ENTITY_NULL;
                page->entity_list[i]  = ENTITY_NULL;
            }
            ECS_assert(pool->page_count < MAX_PAGE_AMOUNT, "Maximum page amount reached");

            pool->component_pages[page_id] = page;

            ++pool->page_count;

            return page;
        }


        template<typename T>
        Component_page<T> *get_page(top_memory_arena *mm, Component_pool<T> *pool, uint32_t id)
        {
            ECS_assert(id < MAX_PAGE_AMOUNT , "id must be lower than MAX_PAGE_AMOUNT");

            if(pool->component_pages[id] == NULL)
            {
                pool->component_pages[id] = init_page<T>(mm, pool, id);
            }

            return pool->component_pages[id];
        }


        template<typename T>
        void set_component(top_memory_arena *mm, Component_data *cdata, Entity e, T &comp)
        {
            ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
            ECS_assert(e < (MAX_ENTITY_AMOUNT - 1), "entity id out of bounds");

            uint32_t page_id = e / PAGE_SIZE;
            uint32_t page_entry = e % PAGE_SIZE;
            Component_pool<T> *pool = get_component_pool<T>(cdata);
            Component_page<T> *page = get_page<T>(mm, pool, page_id);

            page->sparse_array[page_entry] = page->entity_count;

            page->entity_list[page->entity_count] = e;

            page->dense_array[page->entity_count] = comp;

            ++page->entity_count;
            ++pool->entity_count;
        }

        template<typename T>
        Entity lookup_entity(top_memory_arena *mm, Component_data *cdata, Entity e)
        {   

            uint32_t page_id = e / PAGE_SIZE;
            uint32_t page_entry = e % PAGE_SIZE;

            Component_page<T> *page = get_page<T>(mm, cdata, page_id);

            return page->sparse_array[page_entry];
        }

        
        template<typename T>
        void destroy_component(Component_data *cdata, Entity e)
        {
            ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
            ECS_assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

            uint32_t page_id = e / PAGE_SIZE;

            Component_pool<T> *pool = get_component_pool<T>(cdata);
            Component_page<T> *page = get_page<T>(mm, pool, page_id);
            ECS_assert(pool->size > 0, "pool size cannot be 0");

            Entity laste = pool->entity_list[pool->size - 1];

            pool->dense_array[pool->sparse_array[e]] = pool->dense_array[pool->sparse_array[laste]];
            pool->sparse_array[laste] = pool->sparse_array[e];
            
            pool->sparse_array[e] = ENTITY_NULL;
            --pool->size;
        }
        

        template<typename T>
        T *get_component(top_memory_arena *mm, Component_data *cdata, Entity e)
        {
            ECS_assert(e <= ENTITY_NULL, "Entity outside scope");
            Component_pool<T> *pool = get_component_pool<T>(cdata);
            uint32_t page_id = e / PAGE_SIZE;
            uint32_t page_entry = e % PAGE_SIZE;
            Component_page<T> *page = get_page<T>(mm, pool, page_id);
            if(page->sparse_array[page_entry] == ENTITY_NULL)
            {
                return NULL;
            }
            return &page->dense_array[page->sparse_array[page_entry]];
        }


        // garbage function
        template<typename T1, typename... Ts>
        void _set_min_comp_array_size(Component_data *cdata, size_t &mincompid, size_t *compids, size_t &minsize, const size_t component_amount)
        {
            const size_t typeCount = 1 + sizeof...(Ts);
            const size_t compid = Component_functions::get_component_id<T1>(cdata);
            ECS_assert(cdata->pool_init[compid], "component pool not initalized");

            const Component_pool<T1>* comparray = static_cast<Component_pool<T1>*>(cdata->component_pools[compid]);
            const size_t entity_count = comparray->entity_count;

            if(entity_count < minsize)
            {
                minsize = entity_count;
                mincompid = compid;
            }


            compids[component_amount - typeCount] = compid;

            if constexpr (typeCount - 1) // just works with constexpr
            {
                _set_min_comp_array_size<Ts...>(cdata, mincompid, compids, minsize, component_amount);
            }
        }
        


        template<typename T1, typename... Ts>
        View<T1> get_view(top_memory_arena *mm, Component_data *cdata)
        {
            const size_t typeCount = 1 + sizeof...(Ts);

            size_t mincompid;
            size_t compids[typeCount];
            size_t minsize = SIZE_MAX;

            _set_min_comp_array_size<T1, Ts...>(cdata, mincompid, compids, minsize, typeCount);


            View<T1> view = View<T1>();
            view.size = 0;

            for(size_t i = 0; i < VIEW_SIZE; ++i)
            {
                view.entity_list[i] = ENTITY_NULL;
            }

            Component_pool<T1> *comp_pool = get_component_pool<T1>(cdata);

            void *min_comp_pool = cdata->component_pools[mincompid]; // dangerous

            size_t *page_count_pointer   = (size_t*)(min_comp_pool);
            size_t *entity_count_pointer = (size_t*)(page_count_pointer + 1);
            void **component_pages       = (void**)(entity_count_pointer + 1); // almost three star programming


            for(size_t i = 0; i < MAX_PAGE_AMOUNT; ++i)
            {
                void *page = component_pages[i];
                if(page == NULL)
                {
                    continue;
                }

                size_t *page_size_pointer    = (size_t*)page;
                Entity *sparse_array_pointer = (Entity*)(page_size_pointer + 1);
                Entity *entity_list_pointer  = (Entity*)(sparse_array_pointer + PAGE_SIZE);
            //  T1 *dense_array_pointer      = (T1*)(entity_list_pointer + PAGE_SIZE);

                for(size_t j = 0; j < *page_size_pointer; ++j)
                {
                    Entity min_e  = entity_list_pointer[j];
                    uint32_t page_entry_min_e = min_e % PAGE_SIZE;

                    for(size_t k = 0; k < typeCount; ++k)
                    {
                        void *curr_comp_pool = cdata->component_pools[compids[k]];

                        size_t *curr_page_count_pointer   = (size_t*)(curr_comp_pool);
                        size_t *curr_entity_count_pointer = (size_t*)(curr_page_count_pointer + 1);
                        void **curr_component_pages       = (void**)(curr_entity_count_pointer + 1); // almost three star programming

                        void *curr_page = curr_component_pages[i];
                        if(curr_page == NULL)
                        {
                            goto continue_page_loop;
                        }

                        size_t *curr_page_size_pointer    = (size_t*)curr_page;
                        Entity *curr_sparse_array_pointer = (Entity*)(curr_page_size_pointer + 1);
                    //  Entity *curr_entity_list_pointer  = (Entity*)(curr_sparse_array_pointer + PAGE_SIZE);

                        if(curr_sparse_array_pointer[page_entry_min_e] == ENTITY_NULL)
                        {
                            goto continue_entity_loop;
                        }

                    }

                    ECS_assert(min_e != ENTITY_NULL, "Entity to be added to view cannot be ENTITY_NULL");
                    view.entity_list[view.size++] = min_e;

                    continue_entity_loop:;
                }                    




                continue_page_loop:;
            }

            // add components to view
            ECS_assert(view.size < VIEW_SIZE, "View cannot be greater than max size");
            for(size_t i = 0; i < view.size; ++i)
            {
                Entity e = view.entity_list[i];
                ECS_assert(e != ENTITY_NULL, "Entity in view cannot be ENTITY_NULL");
                
                uint32_t page_id = e / PAGE_SIZE;
                uint32_t page_entry = e % PAGE_SIZE;

                Component_page<T1> *page = get_page<T1>(mm, comp_pool, page_id);
                view.comparray[i] = page->dense_array[page->sparse_array[page_entry]];
            }


            return view;
        }




    }
}

