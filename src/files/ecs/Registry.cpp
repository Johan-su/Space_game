#include "Registry.hpp"

using namespace Ecs;




void Event_functions::init(event_data *ed)
{
    memset(ed, 0, sizeof(*ed));
}


void Event_functions::run_events(event_data *ed, Memory_arena *event_mm, Iter *it)
{
    void *after_latest_event = event_mm->data;

    while (ed->events_in_buffer_count != 0)
    {
        Usize *event_id = (Usize *)after_latest_event;
        void *event = event_id + 1;
        ECS_assert(ed->event_init[*event_id], "event not initalized");
        void *after_latest_event_unaligned = (U8 *)event + ed->type_data[*event_id].size;

        after_latest_event = Utils::align_pointer(after_latest_event_unaligned, alignof(Usize));

        for (int i = 0; i < ed->listener_data[*event_id].event_sub_count; ++i)
        {
            it->event = event;
            ed->listener_data[*event_id].event_listeners[i](it);
        }
        --ed->events_in_buffer_count;
    }
    Arena::clear_arena(event_mm);
}








void Ecs::init(Registry *registry, Memory_arena *mm, Memory_arena *view_mm, Memory_arena *event_mm)
{
    ECS_assert(registry != nullptr, "Registry cannot be nullptr");




    registry->mm = mm;
    registry->view_mm = view_mm;
    registry->event_mm = event_mm;

    Arena::clear_arena(event_mm);


    registry->edata   = Arena::top_alloc<Entity_data>(registry->mm);
    registry->evdata  = Arena::top_alloc<event_data>(registry->mm);
    registry->sysdata = Arena::top_alloc<system_data>(registry->mm);
    registry->cdata   = Arena::top_alloc<Component_data>(registry->mm);

    Entity_functions::init(registry->edata);
    Event_functions::init(registry->evdata);
    System_functions::init(registry->sysdata);
    Component_functions::init(registry->cdata);
}


void Ecs::init_system(Registry *registry, Phase phase, SystemFunc *system_function)
{
    System_functions::init_system(registry->sysdata, phase, system_function);
}


void Ecs::progress_systems(Registry *registry, float Ts)
{
    Iter it = {
        .registry   = registry,
        .group      = nullptr,
        .view_arena = registry->view_mm,
        .event      = nullptr,
        .Ts         = Ts
    };
    Event_functions::run_events(registry->evdata, registry->event_mm, &it);
    System_functions::progess_systems(registry->sysdata, registry->view_mm, &it);
}


Entity Ecs::create_entity(Registry *registry)
{
    Entity e = Entity_functions::create_entity(registry->edata);

    return e;    
}


void Ecs::destroy_entity(Registry *registry, Entity e)
{
    Component_functions::destroy_entity(registry->cdata, e);
    Entity_functions::destroy_entity(registry->edata, e);
}


    

