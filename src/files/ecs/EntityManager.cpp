#include "Entity.hpp"
#include "EntityManager.hpp"
#include "MemoryManager.hpp"

using namespace Ecs;



void Entity_functions::init(Memory_pool *mem, Entity_data *e_data)
{
    e_data->m_entitycount = -1;
}


Entity Entity_functions::create_entity(Entity_data *e_data)
{
    Entity e = Entity();
    e = {++(e_data->m_entitycount)};
    return e;
}


void Entity_functions::destroy_entity(Entity_data *edata, Entity e)
{
    
}
