#pragma once
#include "ecs_constants.hpp"
#include "../Memory_arena.hpp"
#include "Entity.hpp"
#include "ecs_assert.hpp"
#include "View_Groups.hpp"

namespace Ecs
{
    template<typename T>
    struct Component_page // changing variables or order will affect componentManager functions
    {
        Usize entity_count;
        Entity sparse_array[PAGE_SIZE];
        Entity entity_list[PAGE_SIZE];
        T dense_array[PAGE_SIZE];
    };


    template<typename T>
    struct Component_pool // changing variables or order will affect componentManager functions
    {
        Usize page_count;
        Usize entity_count;
        Component_page<T> *component_pages[MAX_PAGE_AMOUNT];
    };



    struct Component_data
    {
        void *component_pools[MAX_COMPONENT_TYPES];

        Usize component_sizes[MAX_COMPONENT_TYPES];
        Usize component_alignments[MAX_COMPONENT_TYPES];

        Usize componentTypesCount;

        bool pool_init[MAX_COMPONENT_TYPES];

    };



    namespace Component_functions 
    {
        void init(Component_data *cdata);
        void init_component_bytes(top_memory_arena *mm, Component_data *cdata, Usize compid, Usize comp_size, Usize comp_alignment);

        void destroy_entity(Component_data *cdata, Entity e);

        void fill_similar_entities(Component_data *cdata, Entity *entity_list, Usize *count, Usize *comp_ids, Usize min_id, Usize typeCount);
    }


    namespace Component_functions
    {

        template<typename T>
        Usize get_component_id(Component_data *cdata)
        {
            static const Usize id = cdata->componentTypesCount++;
            return id;
        }


        template<typename T>
        void init_component(top_memory_arena *mm, Component_data *cdata)
        {
            const Usize compid = get_component_id<T>(cdata);
            init_component_bytes(mm, cdata, compid, sizeof(T), alignof(T));
        }

        template<typename T>
        Component_pool<T> *get_component_pool(Component_data *cdata)
        {
            const Usize compid = get_component_id<T>(cdata);
            ECS_assert(cdata->pool_init[compid], "Component_pool was not initalized");

            Component_pool<T> *comp_pool = (Component_pool<T>*) cdata->component_pools[compid];
            ECS_assert(comp_pool != nullptr, "Component_pool is null");

            return comp_pool;
        }


        template<typename T>
        Component_page<T> *init_page(top_memory_arena *mm, Component_pool<T> *pool, U32 page_id)
        {
            ECS_assert(page_id < MAX_PAGE_AMOUNT, "page_id outside legal scope");
            Component_page<T> *page = Arena::top_alloc<Component_page<T>>(mm);

            page->entity_count = 0;
            for(Usize i = 0; i < PAGE_SIZE; ++i)
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
        Component_page<T> *get_page(top_memory_arena *mm, Component_pool<T> *pool, U32 id)
        {
            ECS_assert(id < MAX_PAGE_AMOUNT , "id must be lower than MAX_PAGE_AMOUNT");

            if (pool->component_pages[id] == NULL)
            {
                pool->component_pages[id] = init_page<T>(mm, pool, id);
            }

            return pool->component_pages[id];
        }


        template<typename T>
        void set_component(top_memory_arena *mm, Component_data *cdata, Entity e, T comp)
        {
            ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
            ECS_assert(e < (MAX_ENTITY_AMOUNT - 1), "entity id out of bounds");

            U32 page_id = e / PAGE_SIZE;
            U32 page_entry = e % PAGE_SIZE;
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
            U32 page_id = e / PAGE_SIZE;
            U32 page_entry = e % PAGE_SIZE;

            Component_page<T> *page = get_page<T>(mm, cdata, page_id);

            return page->sparse_array[page_entry];
        }

        
        template<typename T>
        void destroy_component(Component_data *cdata, Entity e)
        {
            ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
            ECS_assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

            U32 page_id = e / PAGE_SIZE;

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
            ECS_assert(e < ENTITY_NULL, "Entity outside scope");
            Component_pool<T> *pool = get_component_pool<T>(cdata);
            U32 page_id = e / PAGE_SIZE;
            U32 page_entry = e % PAGE_SIZE;
            Component_page<T> *page = get_page<T>(mm, pool, page_id);
            if (page->sparse_array[page_entry] == ENTITY_NULL)
            {
                return NULL;
            }
            return &page->dense_array[page->sparse_array[page_entry]];
        }


        template<typename... T>
        void set_min_array_data(Component_data *cdata, Usize *compids, Usize *min_id, Usize *min_count)
        {
            Usize compid_count = 0;

            *min_id    = SIZE_MAX;
            *min_count = SIZE_MAX;

            ([&]()
            {
                Usize compid = Component_functions::get_component_id<T>(cdata);

                compids[compid_count++] = compid;

                ECS_assert(cdata->pool_init[compid], "Component_pool was not initalized");

                Component_pool<T> *comppool = (Component_pool<T> *)cdata->component_pools[compid];

                Usize entity_count = comppool->entity_count;

                if (entity_count < *min_count)
                {
                    *min_count = entity_count;
                    *min_id = compid;
                }

            }(), ...);
        }


        template<typename T1, typename... Ts>
        View<T1> *get_view(top_memory_arena *mm, top_memory_arena *view_mm, Component_data *cdata)
        {
            const Usize typeCount = 1 + sizeof...(Ts);


            Usize compids[typeCount];
            Usize mincompid;
            Usize minsize;
            set_min_array_data<T1, Ts...>(cdata, compids, &mincompid, &minsize);


            //TODO(Johan): allocation with minsize might waste a lot of memory.
            View<T1> *view = Arena::top_alloc<View<T1>>(view_mm); 
            view->entity_list = Arena::top_alloc<Entity>(view_mm, minsize);
            view->comparray = Arena::top_alloc<T1>(view_mm, minsize);
            view->size = 0;

            for (Usize i = 0; i < minsize; ++i)
            {
                view->entity_list[i] = ENTITY_NULL;
            }

            Component_pool<T1> *comp_pool = get_component_pool<T1>(cdata);

            fill_similar_entities(cdata, view->entity_list, &view->size, compids, mincompid, typeCount);

            // add components to view
            for (Usize i = 0; i < view->size; ++i)
            {
                Entity e = view->entity_list[i];
                ECS_assert(e != ENTITY_NULL, "Entity in view cannot be ENTITY_NULL");
                
                U32 page_id = e / PAGE_SIZE;
                U32 page_entry = e % PAGE_SIZE;

                Component_page<T1> *page = get_page<T1>(mm, comp_pool, page_id);
                view->comparray[i] = page->dense_array[page->sparse_array[page_entry]];
            }


            return view;
        }


        template<typename... T>
        Group *get_group(top_memory_arena *mm, top_memory_arena *view_mm, Component_data *cdata)
        {
            const Usize typeCount = sizeof...(T);

            Usize compids[typeCount];
            Usize mincompid;
            Usize min_count;

            set_min_array_data<T...>(cdata, compids, &mincompid, &min_count);


            Group *group = Arena::top_alloc<Group>(view_mm);

            group->comp_arrays     = Arena::top_alloc<void *>(view_mm, typeCount);
            group->comp_sizes      = Arena::top_alloc<Usize>(view_mm, typeCount);
            group->comp_alignments = Arena::top_alloc<Usize>(view_mm, typeCount);
            group->entity_list     = Arena::top_alloc<Entity>(view_mm, min_count);

            group->size = 0;

            for (Usize i = 0; i < typeCount; ++i)
            {
                Usize comp_alignment = cdata->component_alignments[compids[i]];
                Usize comp_size      = cdata->component_sizes[compids[i]];

                group->comp_alignments[i] = comp_alignment;
                group->comp_sizes[i]      = comp_size;

                group->comp_arrays[i] = Arena::top_alloc_bytes(view_mm,  min_count * comp_size, comp_alignment);
            }

            for (Usize i = 0; i < min_count; ++i)
            {
                group->entity_list[i] = ENTITY_NULL;
            }

            fill_similar_entities(cdata, group->entity_list, &group->size, compids, mincompid, typeCount);

            // add components to group
            for (Usize i = 0; i < group->size; ++i)
            {
                Entity e = group->entity_list[i];

                ECS_assert(e != ENTITY_NULL, "Entity in group cannot be ENTITY_NULL");
                
                U32 page_id = e / PAGE_SIZE;
                U32 page_entry = e % PAGE_SIZE;


                for (Usize j = 0; j < typeCount; ++j)
                {
                    Usize comp_size = cdata->component_sizes[compids[j]];


                    // not actually a pool of U8:s, it is used to read individual bytes.
                    Component_pool<U8> *comp_pool = (Component_pool<U8> *)cdata->component_pools[compids[j]];
                    Component_page<U8> *comp_page = comp_pool->component_pages[page_id];

                    Entity *sparse_array = comp_page->sparse_array;
                    U8 *dense_array = comp_page->dense_array;
                    
                    U8 *comp_array = (U8 *)group->comp_arrays[j];

                    memcpy(&comp_array[i * comp_size], &dense_array[sparse_array[page_entry] * comp_size], comp_size);
                }
            }

            return group;
        }

    }
}

