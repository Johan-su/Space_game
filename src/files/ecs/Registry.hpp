#pragma once
#include "EventManager.hpp"

#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"
#include "View_Groups.hpp"

#include "../Memory_arena.hpp"


namespace Ecs
{
    struct Registry
    {
        top_memory_arena *mm;
        top_memory_arena *view_mm;
        top_memory_arena *event_mm;
        Entity_data *edata;
        event_data *evdata;
        system_data *sysdata;
        Component_data *cdata;      
    };

    
    void init(Registry *registry, top_memory_arena *mm, top_memory_arena *view_mm, top_memory_arena *event_mm);
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

