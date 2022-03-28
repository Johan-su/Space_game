#pragma once
#include "MemoryManager.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "View_Groups.hpp"
#include "EventManager.hpp"

#include <stdint.h>



#define ECS_ID(T) ECS_ID_EVENT##T
#define ECS_DECLARE_EVENT(T) static const size_t ECS_ID_EVENT##T = __COUNTER__; static_assert(sizeof(T) > 0, "cannot declare zero size types")
#define ECS_INIT_EVENT(registry, T) Registry_functions::init_event(registry, ECS_ID(T), sizeof(T), alignof(T))
#define ECS_BROADCAST_EVENT(registry, T, ...) Registry_functions::broadcast_event(registry, ECS_ID(T), sizeof(T), alignof(T), &(T)__VA_ARGS__)

struct Registry_data
{
    Memory_pool *mm;
    Entity_data *edata;
    event_data *evdata;
    Component_data *cdata;
};

namespace Registry_functions
{

    void init(Registry_data *rdata, void (event_listener)(size_t, const void*));
    void clean(Registry_data *rdata);

    Entity create_entity(Registry_data *rdata);
    void destroy_entity(Registry_data *rdata, Entity e);

    void init_event(Registry_data *rdata, size_t event_id, size_t event_size, size_t event_alignment);
    void broadcast_event(Registry_data *rdata, size_t event_id, size_t event_size, size_t event_alignment, const void *event);

}

namespace Registry_functions
{

    template<typename T>
    void init_component(Registry_data *rdata)
    {
        namespace C_F = Component_functions;

        auto *cdata = rdata->cdata;
        auto *mm = rdata->mm;


        C_F::init_component<T>(mm, cdata);        
    }

    template <typename T>
    void set_component(Registry_data *rdata, Entity e, T& comp)
    {
        namespace E_F = Entity_functions;
        namespace C_F = Component_functions;

        auto *cdata = rdata->cdata;

        C_F::set_component<T>(cdata, e, comp);
    }

    template<typename T>
    void destroy_component(Registry_data *rdata, Entity e) //TODO(Johan) add all necessary deletions
    {
        namespace C_F = Component_functions;
        
        auto *cdata = rdata->cdata;

        C_F::destroy_component<T>(cdata, e);
    }
}