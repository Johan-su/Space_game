#pragma once
#include "MemoryManager.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "EventManager.hpp"
#include "View_Groups.hpp"

#include <stdint.h>


namespace Ecs
{
    struct Registry
    {
        Memory_pool *mm;
        Entity_data *edata;
        event_data *evdata;
        Component_data *cdata;      
    };

    void init(Registry *registry);
    void clean(Registry *registry);

    Registry *create_registry();

    Entity create_entity(Registry *registry);
    void destroy_entity(Registry *registry, Entity e);


}

namespace Ecs
{

    template<typename Event, typename Return>
    void init_event(Registry *registry, Return (event_listener)(Event *))
    {
        Event_functions::init_event<Event, Return>(registry->evdata, event_listener);
    }


    template<typename EventT, typename ReturnT>
    ReturnT broadcast_event(Registry *registry, EventT *event)
    {
        return Event_functions::broadcast_event<EventT, ReturnT>(registry->evdata, event);
    }


    template<typename T>
    void init_component(Registry *registry)
    {
        auto *cdata = registry->cdata;
        auto *mm = registry->mm;


        Component_functions::init_component<T>(mm, cdata);        
    }


    template<typename T>
    void set_component(Registry *registry, Entity e, T& comp)
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
        
        auto *cdata = rdata->cdata;

        Component_functions::destroy_component<T>(cdata, e);
    }

    template<typename T1, typename... Ts>
    View<T1> get_view(Registry *registry)
    {
        return Component_functions::get_view<T1, Ts...>(registry->mm, registry->cdata);
    }
}

