#include "Registry.hpp"

void Ecs::init(Registry *registry)
{
    ECS_assert(registry != nullptr, "Registry cannot be NULL");


    registry->mm = (Memory_pool*)malloc(sizeof(Memory_pool));

    registry->mm->m_MemoryActive = false;

    Memory::init(registry->mm);

    registry->edata  = Memory::alloc<Entity_data>(registry->mm);
    registry->evdata = Memory::alloc<event_data>(registry->mm);
    registry->cdata  = Memory::alloc<Component_data>(registry->mm);

    Entity_functions::init(registry->mm, registry->edata);
    Event_functions::init(registry->evdata);
    Component_functions::init(registry->cdata);
}


void Ecs::clean(Registry *registry)
{
    Memory::clean(registry->mm);
    free(registry->mm);

    registry->mm    = nullptr;
    registry->edata = nullptr;
    registry->cdata = nullptr;
}


Ecs::Registry *Ecs::create_registry()
{
    return (Registry*)malloc(sizeof(Registry));
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


    

