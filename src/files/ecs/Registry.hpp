#pragma once


#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"
#include "View_Groups.hpp"

#include "../Memory_arena.hpp"

#include "../utils.hpp"

namespace Ecs
{
    struct Registry;
}

struct Group;
struct Memory_arena;



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
        Entity_data *edata;
        event_data *evdata;
        system_data *sysdata;
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

