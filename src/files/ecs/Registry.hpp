#pragma once

#include "../Memory_arena.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "EventManager.hpp"
#include "View_Groups.hpp"

#include <stdint.h>


namespace Ecs
{
    struct Registry
    {
        top_memory_arena *mm;
        Entity_data *edata;
        Component_data *cdata;      
    };

    void init(Registry *registry, top_memory_arena *mm);

    Entity create_entity(Registry *registry);
    void destroy_entity(Registry *registry, Entity e);


}

namespace Ecs
{

    template<typename T>
    void init_component(Registry *registry)
    {
        Component_functions::init_component<T>(registry->mm, registry->cdata);
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

