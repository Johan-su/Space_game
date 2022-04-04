#include "Registry.hpp"



void Ecs::init(Registry *registry, void (event_listener)(size_t, const void*))
{
    ECS_assert(registry != nullptr, "Registry cannot be NULL");


    registry->mm = (Memory_pool*)malloc(sizeof(Memory_pool));

    registry->mm->m_MemoryActive = false;

    Memory::init(registry->mm);

    registry->edata  = Memory::alloc<Entity_data>(registry->mm);
    registry->evdata = Memory::alloc<event_data>(registry->mm);
    registry->cdata  = Memory::alloc<Component_data>(registry->mm);

    Entity_functions::init(registry->mm, registry->edata);
    Event_functions::init(registry->evdata, event_listener);
    Component_functions::init(registry->cdata);
}


void Ecs::clean(Registry *registry)
{
    auto &mm     = registry->mm;
    auto &edata  = registry->edata;
    auto &evdata = registry->evdata;
    auto &cdata  = registry->cdata;

    Component_functions::clean(mm, cdata);
    Event_functions::clean(mm, evdata);
    Entity_functions::clean(mm, edata);

    Memory::dealloc(mm, cdata, 1);
    Memory::dealloc(mm, evdata, 1);
    Memory::dealloc(mm, edata, 1);
    
    Memory::clean(mm);
    free(mm);

    mm      = nullptr;
    edata   = nullptr;
    cdata   = nullptr;
}


Entity Ecs::create_entity(Registry *registry)
{
    auto *edata = registry->edata;

    Entity e = Entity_functions::create_entity(edata);

    return e;    
}


void Ecs::destroy_entity(Registry *registry, Entity e)
{
    auto *edata = registry->edata;
    auto *cdata = registry->cdata;


    Component_functions::destroy_entity(cdata, e);
    Entity_functions::destroy_entity(edata, e);
}


void Ecs::init_event(Registry *registry, size_t event_id, size_t event_size, size_t event_alignment)
{
    Event_functions::init_event(registry->evdata, event_id, event_size, event_alignment);
}


void Ecs::broadcast_event(Registry *registry, size_t event_id, size_t event_size, size_t event_alignment, const void *event)
{
    Event_functions::broadcast_event(registry->evdata, event_id, event_size, event_alignment, event);
}

    

