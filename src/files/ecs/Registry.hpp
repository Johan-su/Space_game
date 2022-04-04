#pragma once
#include "MemoryManager.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "View_Groups.hpp"
#include "EventManager.hpp"

#include <stdint.h>



#define ECS_ID(T) ECS_ID_EVENT##T
#define ECS_DECLARE_EVENT(T) static const size_t ECS_ID_EVENT##T = __COUNTER__; static_assert(sizeof(T) > 0, "cannot declare zero size types")
#define ECS_INIT_EVENT(registry, T) Ecs::init_event(registry, ECS_ID(T), sizeof(T), alignof(T))
#define ECS_BROADCAST_EVENT(registry, T, ...) Ecs::broadcast_event(registry, ECS_ID(T), sizeof(T), alignof(T), __VA_ARGS__)


struct Registry
{
    Memory_pool *mm;
    Entity_data *edata;
    event_data *evdata;
    Component_data *cdata;
            
};


namespace Ecs
{


    void init(Registry *registry, void (event_listener)(size_t, const void*));
    void clean(Registry *registry);


    Entity create_entity(Registry *registry);
    void destroy_entity(Registry *registry, Entity e);

    void init_event(Registry *registry, size_t event_id, size_t event_size, size_t event_alignment);
    void broadcast_event(Registry *registry, size_t event_id, size_t event_size, size_t event_alignment, const void *event);

}

namespace Ecs
{

    template<typename T>
    void init_component(Registry *registry)
    {
        auto *cdata = registry->cdata;
        auto *mm = registry->mm;


        Component_functions::init_component<T>(mm, cdata);        
    }


    template <typename T>
    void set_component(Registry *registry, Entity e, T& comp)
    {

        auto *cdata = registry->cdata;

        Component_functions::set_component<T>(cdata, e, comp);
    }


    template<typename T>
    Entity lookup_entity(Registry *registry, Entity e)
    {
        return Component_functions::lookup_entity<T>(registry->cdata, e);
    }

    template<typename T>
    T *get_component(Registry *registry, Entity e)
    {
        return Component_functions::get_component<T>(registry->cdata, e);
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
        return Component_functions::get_view<T1, Ts...>(registry->cdata);
    }
}

