#pragma once

#include "Memory_arena.hpp"
#include "utils.hpp"



#include <stdio.h>
#include <stdlib.h>

#ifdef _DEBUG
#define ECS_assert(condition, message)                                                                          \
do                                                                                                              \
{                                                                                                               \
   if (!(condition))                                                                                             \
   {                                                                                                            \
      fprintf(stderr, "Assertion [ %s ] failed in %s line %u : %s\n", #condition, __FILE__, __LINE__, message); \
      exit(1);                                                                                                  \
   }                                                                                                            \
} while(0)

#define ECS_dbg(expression) \
do                          \
{                           \
   expression;              \
} while (0) 


#else
#define ECS_assert(condition, message) \
do {} while(0)

#define ECS_dbg(expression) \
do {} while(0)


#endif


#ifdef ECS_DEBUG3
#define ECS_dbg3(expression)  \
do                            \
{                             \
   expression;                \
} while (0) 

#else
#define ECS_dbg3(expression) \
do {} while(0)
#endif





















#define PAGE_SIZE 1024 // increase for faster iteration at the cost of higher memory usage. different from OS pages
#define MAX_PAGE_AMOUNT 4096 //TODO(Johan) swap usage of size and amount

#define MAX_ENTITY_AMOUNT (PAGE_SIZE * MAX_PAGE_AMOUNT) // will crash going over MAX_ENTITY_AMOUNT

#define ENTITY_NULL MAX_ENTITY_AMOUNT


#define MAX_SYSTEM_TYPES 256 // per phase, can be more than 256 systems in total
#define MAX_COMPONENT_TYPES 256
#define MAX_EVENT_TYPES 256

#define MAX_EVENT_SUBS 64



typedef U64 Entity;



/**
 * non-owning view, only provides copies of components
 */
template<typename T>
struct View
{
    Usize size;
    Entity *entity_list;
    T *comparray;
};


/**
 * non-owning group, only provies copies of components
 */
struct Group
{
    Usize size;
    Usize *comp_sizes;
    Usize *comp_alignments;
    Entity *entity_list;
    void **comp_arrays;
};
    


namespace Ecs
{
    /**
     * @param group the group, which the array will be retrived from.
     * @param order_id the component's order in the group. starts at 0
     * @return pointer to component array
     */
    template<typename T>
    const T *get_comp_array(const Group *group, U64 order_id)
    {
        ECS_assert(group->comp_sizes[order_id] == sizeof(T) && group->comp_alignments[order_id] == alignof(T), "Component size/alignment mismatch, id order is probably incorrect");
        return (const T *)(group->comp_arrays[order_id]);
    }

} // namespace Ecs











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
        void init_component_bytes(Memory_arena *mm, Component_data *cdata, Usize compid, Usize comp_size, Usize comp_alignment);
        void *get_component_pool_raw(Component_data *cdata, Usize compid);
        void *init_page_raw(Memory_arena *mm, void *raw_pool, U32 page_id, Usize compsize);
        void *get_page_raw(Memory_arena *mm, void *raw_pool, U32 id, Usize compsize);
        void set_component_raw(Memory_arena *mm, Component_data *cdata, Entity e, void *raw_comp, Usize compid, Usize compsize);
        void *get_component_raw(Memory_arena *mm, Component_data *cdata, Entity e, Usize compid, Usize compsize);
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
        void init_component(Memory_arena *mm, Component_data *cdata)
        {
            init_component_bytes(mm, cdata, get_component_id<T>(cdata), sizeof(T), alignof(T));
        }

        template<typename T>
        Component_pool<T> *get_component_pool(Component_data *cdata)
        {
            return (Component_pool<T> *)get_component_pool_raw(cdata, get_component_id<T>(cdata));
        }


        template<typename T>
        Component_page<T> *init_page(Memory_arena *mm, Component_pool<T> *pool, U32 page_id)
        {
            return (Component_page<T> *)init_page_raw(mm, (void *)pool, page_id, sizeof(T));

            /* 
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
            */
        }


        template<typename T>
        Component_page<T> *get_page(Memory_arena *mm, Component_pool<T> *pool, U32 id)
        {
            return (Component_page<T> *)get_page_raw(mm, (void *)pool, id, sizeof(T));
            /*
            ECS_assert(id < MAX_PAGE_AMOUNT , "id must be lower than MAX_PAGE_AMOUNT");

            if (pool->component_pages[id] == nullptr)
            {
                pool->component_pages[id] = init_page<T>(mm, pool, id);
            }

            return pool->component_pages[id];
            */
        }


        template<typename T>
        void set_component(Memory_arena *mm, Component_data *cdata, Entity e, T *comp)
        {
            #if 1
            set_component_raw(mm, cdata, e, (void *)comp, get_component_id<T>(cdata), sizeof(T));
            #else
            ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
                ECS_assert(e < (MAX_ENTITY_AMOUNT - 1), "entity id out of bounds");

            U32 page_id = e / PAGE_SIZE;
            U32 page_entry = e % PAGE_SIZE;
            Component_pool<T> *pool = get_component_pool<T>(cdata);
            Component_page<T> *page = get_page<T>(mm, pool, page_id);

            page->sparse_array[page_entry] = page->entity_count;

            page->entity_list[page->entity_count] = e;

            page->dense_array[page->entity_count] = *comp;

            ++page->entity_count;
            ++pool->entity_count;
            #endif
        }

        template<typename T>
        Entity lookup_entity(Memory_arena *mm, Component_data *cdata, Entity e)
        {
            ECS_assert(false, "unimplemented");   
            U32 page_id = e / PAGE_SIZE;
            U32 page_entry = e % PAGE_SIZE;

            Component_page<T> *page = get_page<T>(mm, cdata, page_id);

            return page->sparse_array[page_entry];
        }

        
        template<typename T>
        void destroy_component(Component_data *cdata, Entity e)
        {
            ECS_assert(false, "not implemented");
            /*
            ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
            ECS_assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

            U32 page_id = e / PAGE_SIZE;
            U32 page_entry = e % PAGE_SIZE;

            Component_pool<T> *pool = get_component_pool<T>(cdata);
            Component_page<T> *page = get_page<T>(pool, page_id);
            ECS_assert(pool->size > 0, "pool size cannot be 0");

            Entity laste = pool->entity_list[pool->size - 1];

            pool->dense_array[pool->sparse_array[e]] = pool->dense_array[pool->sparse_array[laste]];
            pool->sparse_array[laste] = pool->sparse_array[e];
            
            pool->sparse_array[e] = ENTITY_NULL;
            --pool->size;
            */
        }
        

        template<typename T>
        T *get_component(Memory_arena *mm, Component_data *cdata, Entity e)
        {
            #if 1
            return (T *)get_component_raw(mm, cdata, e, get_component_id<T>(cdata), sizeof(T));
            #else
            kasdlö
            ECS_assert(e < ENTITY_NULL, "Entity outside scope");
            Component_pool<T> *pool = get_component_pool<T>(cdata);
            U32 page_id = e / PAGE_SIZE;
            U32 page_entry = e % PAGE_SIZE;
            Component_page<T> *page = get_page<T>(mm, pool, page_id);
            if (page->sparse_array[page_entry] == ENTITY_NULL)
            {
                return nullptr;
            }
            return &page->dense_array[page->sparse_array[page_entry]];
            #endif
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
        View<T1> *get_view(Memory_arena *view_mm, Component_data *cdata)
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

                Component_page<T1> *page = comp_pool->component_pages[page_id];
                view->comparray[i] = page->dense_array[page->sparse_array[page_entry]];
            }


            return view;
        }


        template<typename... T>
        Group *get_group(Memory_arena *view_mm, Component_data *cdata)
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


enum Phase
{
    None,
    PreUpdate,
    OnUpdate,
    PostUpdate,
};


namespace Ecs
{
    struct Registry;
}


struct Iter 
{
    Ecs::Registry *registry;
    Group *group;
    Memory_arena *view_arena;
    void *event;
    float Ts;
};

namespace Ecs
{

    typedef void (SystemFunc)(Iter *);

    struct SystemPool
    {
        Usize count;
        SystemFunc *funcs[MAX_SYSTEM_TYPES];
    };

    
} // namespace Ecs



namespace Ecs
{
    struct Registry;
}

struct Group;
struct Memory_arena;










namespace Ecs
{
    typedef void (listener_func)(Iter *);

    struct event_listener_data
    {
        Usize event_sub_count;
        listener_func *event_listeners[MAX_EVENT_SUBS];
    };


    struct event_type_data
    {
        Usize size;
        Usize alignment;
    };


    struct event_data
    {
        Usize event_types_count;
        Usize events_in_buffer_count;
        bool event_init[MAX_EVENT_TYPES];
        event_listener_data listener_data[MAX_EVENT_TYPES];
        event_type_data type_data[MAX_EVENT_TYPES];
    };


    namespace Event_functions
    {
        void init(event_data *ed); 
        void run_events(event_data *ed, Memory_arena *event_mm, Iter *it);
    } // namespace Event_functions
    

    namespace Event_functions
    {
        template<typename T>
        Usize get_event_id(event_data *ed)
        {
            static const Usize id = ed->event_types_count++;
            return id;
        }

        template<typename T>
        void init_event(event_data *ed)
        {
            const Usize id = get_event_id<T>(ed);
            ECS_assert(id < MAX_EVENT_TYPES, "id must be lower than MAX_EVENT_TYPES");

            ed->event_init[id] = true;
            ed->type_data[id].size = sizeof(T);
            ed->type_data[id].alignment = alignof(T);
        }


        template<typename T>
        void init_event_listener(event_data *ed, void (*listener)(Iter *))
        {
            const Usize id = get_event_id<T>(ed);
            ECS_assert(ed->listener_data[id].event_sub_count < MAX_EVENT_SUBS, "cannot have more than MAX_EVENT_SUBS subs to a single event");

            ed->listener_data[id].event_listeners[ed->listener_data[id].event_sub_count] = listener;
            ++ed->listener_data[id].event_sub_count;
        }


        template<typename T>
        void push_event(event_data *ed, Memory_arena *event_mm, T *event)
        {
            const Usize id = get_event_id<T>(ed);
            ECS_assert(ed->event_init[id], "event must be initalized");

            Usize *id_b = (Usize *)Arena::top_alloc_bytes(event_mm, sizeof(Usize) + sizeof(T), alignof(Usize)); // id + event aligned as id
            *id_b = id;

            T *event_b = (T *)(id_b + 1);
            *event_b = *event;

            ++ed->events_in_buffer_count;
        }
        


    } // namespace Event_functions

} // namespace Ecs




namespace Ecs
{
    struct Registry
    {
        Memory_arena *mm;
        Memory_arena *view_mm;
        Memory_arena *event_mm;

        U64 entity_count;

        event_data *evdata;

        SystemPool pre_update_funcs;
        SystemPool on_update_funcs;
        SystemPool post_update_funcs;

        Component_data *cdata;      
    };

    
    void init(Registry *registry, Memory_arena *mm, Memory_arena *view_mm, Memory_arena *event_mm);
    void init_system(Registry *registry, Phase phase, SystemFunc *system_function);

    void progress_systems(Registry *registry, float Ts);

    Entity create_entity(Registry *registry);
    void destroy_entity(Registry *registry, Entity e);
}


namespace Ecs
{
    template<typename T>
    void init_event(Registry *registry)
    {
        Event_functions::init_event<T>(registry->evdata);
    }


    template<typename T>
    void push_event(Registry *registry, T *event)
    {
        Event_functions::push_event<T>(registry->evdata, registry->event_mm, event);
    }


    template<typename T>
    void init_event_listener(Registry *registry, void (*listener)(Iter *))
    {
        Event_functions::init_event_listener<T>(registry->evdata, listener);
    }


    template<typename T>
    void init_component(Registry *registry)
    {
        Component_functions::init_component<T>(registry->mm, registry->cdata);
    }


    template<typename T>
    void set_component(Registry *registry, Entity e, T comp)
    {

        Component_functions::set_component<T>(registry->mm, registry->cdata, e, &comp);
    }


    template<typename T>
    Entity lookup_entity(Registry *registry, Entity e)
    {
        return Component_functions::lookup_entity<T>(registry->cdata, e);
    }

    template<typename T>
    T *get_component(Registry *registry, Entity e)
    {
        return Component_functions::get_component<T>(registry->mm, registry->cdata, e);
    }


    template<typename T>
    void destroy_component(Registry *registry, Entity e) //TODO(Johan) add all necessary deletions
    {
        Component_functions::destroy_component<T>(registry->cdata, e);
    }

    template<typename T1, typename... Ts>
    View<T1> *get_view(Registry *registry)
    {
        return Component_functions::get_view<T1, Ts...>(registry->view_mm, registry->cdata);
    }


    template<typename... T>
    const Group *get_group(Registry *registry)
    {
        return Component_functions::get_group<T...>(registry->view_mm, registry->cdata);
    }
}

