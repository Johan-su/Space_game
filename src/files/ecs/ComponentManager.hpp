#pragma once
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"
#include "Entity.hpp"
#include "ecs_assert.hpp"
#include "View_Groups.hpp"

#include <stdio.h>


namespace Ecs
{
    template<typename T>
    struct Component_page // changing variables or order will affect componentManager functions
    {
        size_t size;
        Entity sparse_array[PAGE_SIZE];
        Entity entity_list[PAGE_SIZE];
        T dense_array[PAGE_SIZE];
    };


    template<typename T>
    struct Component_pool // changing variables or order will affect componentManager functions
    {
        size_t size;
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
        void clean(Memory_pool *mm, Component_data *cdata);

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
        void init_component(Memory_pool *mm, Component_data *cdata)
        {
            const size_t compid = get_component_id<T>(cdata);

            Component_pool<T> *comppool = (Component_pool<T>*)cdata->component_pools[compid];

            comppool = Memory::alloc<Component_pool<T>>(mm);

            comppool->size = 0;
            for(size_t i = 0; i < MAX_PAGE_AMOUNT; ++i)
            {
                comppool->component_pages[i] = NULL;
            }


            cdata->pool_init[compid]            = true;
            cdata->component_alignments[compid] = alignof(T);
            cdata->component_sizes[compid]      = sizeof(T);
            cdata->component_pools[compid]      = comppool;


            ECS_dbg(printf("sizeof array : %llu\n", sizeof(Component_pool<T>)));

        }

        template<typename T>
        Component_pool<T> *get_component_pool(Component_data *cdata)
        {
            const size_t compid = get_component_id<T>(cdata);
            ECS_assert(cdata->pool_init[compid], "Component_pool was not initalized");

            auto *comparray = (Component_pool<T>*) cdata->component_pools[compid];
            ECS_assert(comparray != nullptr, "Component_pool is null");

            return comparray;
        }


        template<typename T>
        Component_page<T> *init_page(Memory_pool *mm, Component_data *cdata, uint32_t page_id)
        {
            ECS_assert(page_id < MAX_PAGE_AMOUNT, "page_id outside legal scope");
            Component_page<T> *page = Memory::alloc<Component_page<T>>(mm);

            page->size = 0;
            for(size_t i = 0; i < PAGE_SIZE; ++i)
            {
                page->sparse_array[i] = ENTITY_NULL;
                page->entity_list[i]  = ENTITY_NULL;
            }
            Component_pool<T> *pool = get_component_pool<T>(cdata);
            ECS_assert(pool->size < MAX_PAGE_AMOUNT, "Maxium page amount reached");

            pool->component_pages[page_id] = page;

            ++pool->size;

            return page;
        }


        template<typename T>
        Component_page<T> *get_page(Memory_pool *mm, Component_data *cdata, uint32_t id)
        {
            ECS_assert(id < MAX_PAGE_AMOUNT , "id must be lower than MAX_PAGE_AMOUNT");
            Component_pool<T> *comp_pool = get_component_pool<T>(cdata);

            Component_page<T> *page = comp_pool->component_pages[id];

            if(!page)
            {
                page = init_page<T>(mm, cdata, id);
            }

            return page;
        }


        template<typename T>
        void set_component(Memory_pool *mm, Component_data *cdata, Entity e, T &comp)
        {
            ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
            ECS_assert(e < (MAX_ENTITY_AMOUNT - 1), "entity id out of bounds");

            uint32_t page_id = e / PAGE_SIZE;

            Component_page<T> *page = get_page<T>(mm, cdata, page_id);

            page->sparse_array[e] = page->size;

            page->entity_list[page->size] = e;

            page->dense_array[page->size] = comp;

            ++page->size;
        }

        template<typename T>
        Entity lookup_entity(Memory_pool *mm, Component_data *cdata, Entity e)
        {   

            uint32_t page_id = e / PAGE_SIZE;

            Component_page<T> *page = get_page<T>(mm, cdata, page_id);

            return page->sparse_array[e];
        }

        /*
        template<typename T>
        void destroy_component(Component_data *cdata, Entity e)
        {
            ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
            ECS_assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

            Component_pool<T> *comparray = get_component_pool<T>(cdata);
            ECS_assert(comparray->size > 0, "array size is 0");

            Entity laste = comparray->entity_list[comparray->size - 1];

            comparray->dense_array[comparray->sparse_array[e]] = comparray->dense_array[comparray->sparse_array[laste]];
            comparray->sparse_array[laste] = comparray->sparse_array[e];
            
            comparray->sparse_array[e] = ENTITY_NULL;
            --comparray->size;
        }
        */

        template<typename T>
        T *get_component(Memory_pool *mm, Component_data *cdata, Entity e)
        {
            ECS_assert(e <= ENTITY_NULL, "Entity outside scope");
            uint32_t page_id = e / PAGE_SIZE;
            auto *page = get_page<T>(mm, cdata, page_id);
            if(page->sparse_array[e] == ENTITY_NULL)
            {
                return NULL;
            }
            return &page->dense_array[page->sparse_array[e]];
        }


        // garbage function
        template<typename T1, typename... Ts>
        void _set_min_comp_array_size(Component_data *cdata, size_t &mincompid, size_t *compids, size_t &minsize, const size_t component_amount)
        {
            const size_t typeCount = 1 + sizeof...(Ts);
            const size_t compid = Component_functions::get_component_id<T1>(cdata);
            ECS_assert(cdata->pool_init[compid], "component pool not initalized");

            const auto *comparray = static_cast<Component_pool<T1>*>(cdata->component_pools[compid]);
            const size_t size = comparray->size;

            if(size < minsize)
            {
                minsize = size;
                mincompid = compid;
            }


            compids[component_amount - typeCount] = compid;

            if constexpr (typeCount - 1) // just works with constexpr
            {
                _set_min_comp_array_size<Ts...>(cdata, mincompid, compids, minsize, component_amount);
            }
        }
        


        template<typename T1, typename... Ts>
        View<T1> get_view(Component_data *cdata)
        {
            const size_t typeCount = 1 + sizeof...(Ts);

            size_t mincompid;
            size_t compids[typeCount];
            size_t minsize = SIZE_MAX;

            _set_min_comp_array_size<T1, Ts...>(cdata, mincompid, compids, minsize, typeCount);


            auto view = View<T1>();

            for(size_t i = 0; i < VIEW_SIZE; ++i)
            {
                view.entity_list[i] = ENTITY_NULL;
            }

            auto *comp_pool = get_component_pool<T1>(cdata);

            void *min_comp_pool = cdata->component_pools[mincompid]; // dangerous

            size_t *size_pointer = (size_t*)(min_comp_pool);
            void **component_pages = (void**)(size_pointer + 1); // almost three star programming


            for(size_t i = 0; i < MAX_PAGE_AMOUNT; ++i) //TODO(Johan) finish
            {
                void *page = component_pages[i];
                if(page == NULL)
                {
                    continue;
                }

                size_t *page_size_pointer    = (size_t*)page;
                Entity *sparse_array_pointer = (Entity*)(page_size_pointer + 1);
                Entity *entity_list_pointer  = (Entity*)(sparse_array_pointer + PAGE_SIZE);
                void *dense_array_pointer    = (void*)(entity_list_pointer + PAGE_SIZE);

                for(size_t k = 0; k < typeCount; ++k)
                {
                    void *curr_comp_pool = cdata->component_pools[compids[k]];

                    size_t *curr_size_pointer = (size_t*)(curr_comp_pool);
                    void **curr_component_pages = (void**)(curr_size_pointer + 1); // almost three star programming

                    void *curr_page = curr_component_pages[i];
                    if(curr_page == NULL)
                    {
                        goto continue_outer_loop;
                    }

                    for(size_t j = 0; j < PAGE_SIZE; ++j)
                    {
                        Entity min_e = entity_list_pointer[j];
                    }                    
                }


                continue_outer_loop:;
            }



            return view;
        }




    }
}

