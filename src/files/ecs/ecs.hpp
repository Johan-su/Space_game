#pragma once
#include "ecs_constants.hpp"
#include "Entity.hpp"


#include "View_Groups.hpp"

struct Registry;


#define ECS_ID(T) ECS_ID_EVENT##T
#define ECS_DECLARE_EVENT(T) static const size_t ECS_ID_EVENT##T = __COUNTER__; static_assert(sizeof(T) > 0, "cannot declare zero size types")
#define ECS_INIT_EVENT(registry, T) Ecs::init_event(registry, ECS_ID(T), sizeof(T), alignof(T))
#define ECS_BROADCAST_EVENT(registry, T, ...) Ecs::broadcast_event(registry, ECS_ID(T), sizeof(T), alignof(T), __VA_ARGS__)

namespace Ecs
{

    extern void init(Registry *registry, void (event_listener)(size_t, const void*));
    extern void clean(Registry *registry);
    extern Registry *create_registry();
    extern Entity create_entity(Registry *registry);
    extern void destroy_entity(Registry *registry, Entity e);
    extern void init_event(Registry *registry, size_t event_id, size_t event_size, size_t event_alignment);
    extern void broadcast_event(Registry *registry, size_t event_id, size_t event_size, size_t event_alignment, const void *event);


    template<typename T>
    extern void init_component(Registry *registry);

    template<typename T>
    extern void set_component(Registry *registry, Entity e, T& comp);

    template<typename T>
    extern Entity lookup_entity(Registry *registry, Entity e);

    template<typename T>
    T *get_component(Registry *registry, Entity e);

    template<typename T>
    extern void destroy_component(Registry *registry, Entity e);

    template<typename T1, typename... Ts>
    extern View<T1> get_view(Registry *registry);
}