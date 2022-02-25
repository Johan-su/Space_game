#include "Entity.hpp"
#include "EntityManager.hpp"
#include "MemoryManager.hpp"


void Entity_functions::init(Memory_pool *mem, Entity_data *e_data)
{
    e_data->m_entitycount = 0;
}


void Entity_functions::clean(Memory_pool *mem, Entity_data *e_data)
{
}


Entity Entity_functions::create_entity(Entity_data *e_data)
{
    Entity e = Entity();
    e = {++(e_data->m_entitycount)}; // entities start at 1 for debugging purposes //TODO(Johan) remove when finished
    return e;
}


void Entity_functions::destroy_entity(Entity_data *edata, Entity e)
{
    --edata->m_entitycount;
}
