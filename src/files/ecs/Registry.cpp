#include "Registry.hpp"

using namespace Ecs;


void Ecs::init(Registry *registry, top_memory_arena *mm)
{
    ECS_assert(registry != NULL, "Registry cannot be NULL");




    registry->mm = mm;

    registry->edata  = Arena::top_alloc<Entity_data>(registry->mm);
    registry->cdata  = Arena::top_alloc<Component_data>(registry->mm);

    Entity_functions::init(registry->edata);
    Component_functions::init(registry->cdata);
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


    

