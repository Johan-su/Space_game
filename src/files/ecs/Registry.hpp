#pragma once
#include "EventManager.hpp"

#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"
#include "View_Groups.hpp"

#include "../Memory_arena.hpp"


namespace Ecs
{
   // struct event_data;
    struct Registry
    {
        top_memory_arena *mm;
        top_memory_arena *view_mm;
        Entity_data *edata;
        event_data *evdata;
        system_data *sysdata;
        Component_data *cdata;      
    };

    void init(Registry *registry, top_memory_arena *mm, top_memory_arena *view_mm);
    void init_system(Registry *registry, Phase phase, SystemFunc *system_function);

    void progress_systems(Registry *registry, float Ts);

    Entity create_entity(Registry *registry);
    void destroy_entity(Registry *registry, Entity e);


}

namespace Ecs
{
    template<typename ReturnT, typename EventT>
    void init_event(Registry *registry, ReturnT (event_listener)(Iter *))
    {
        Event_functions::init_event<ReturnT, EventT>(registry->evdata, event_listener);
    }


    template<typename ReturnT, typename EventT> // TODO(Johan): very unsafe as EventT does not get auto deduced
    ReturnT broadcast_event(Registry *registry, Iter *iter)
    {
        return Event_functions::broadcast_event<ReturnT, EventT>(registry->evdata, iter);
    }


    template<typename T>
    void init_component(Registry *registry)
    {
        Component_functions::init_component<T>(registry->mm, registry->cdata);
    }


    template<typename T>
    void set_component(Registry *registry, Entity e, T comp)
    {

        Component_functions::set_component<T>(registry->mm, registry->cdata, e, comp);
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
        Component_functions::destroy_component<T>(rdata->cdata, e);
    }

    template<typename T1, typename... Ts>
    View<T1> *get_view(Registry *registry)
    {
        return Component_functions::get_view<T1, Ts...>(registry->mm, registry->view_mm, registry->cdata);
    }


    template<typename... T>
    Group *get_group(Registry *registry)
    {
        return Component_functions::get_group<T...>(registry->mm, registry->view_mm, registry->cdata);
    }
}

