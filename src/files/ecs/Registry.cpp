#include "Registry.hpp"

using namespace Ecs;

static void init(Registry *registry)
{
    ECS_assert(registry != nullptr, "Registry cannot be NULL");



    registry->mm.m_MemoryActive = false;

    Memory::init(&registry->mm);

    registry->edata  = Memory::alloc<Entity_data>(&registry->mm);
    registry->evdata = Memory::alloc<event_data>(&registry->mm);
    registry->cdata  = Memory::alloc<Component_data>(&registry->mm);

    Entity_functions::init(registry->edata);
    Event_functions::init(registry->evdata);
    Component_functions::init(registry->cdata);
}




Registry *Ecs::create_registry()
{
    Registry *registry = (Registry*)malloc(sizeof(Registry));
    init(registry);
    return registry;
}


void Ecs::destroy_registry(Registry *registry)
{
    Memory::clean(&registry->mm);
    free(registry);
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


    

