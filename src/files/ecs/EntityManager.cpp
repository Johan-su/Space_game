#include "Entity.hpp"
#include "EntityManager.hpp"

using namespace Ecs;



void Entity_functions::init(Entity_data *e_data)
{
    e_data->m_entitycount = 0;
}


Entity Entity_functions::create_entity(Entity_data *e_data)
{
    Entity e = Entity();
    e = {e_data->m_entitycount++};
    return e;
}


void Entity_functions::destroy_entity(Entity_data *edata, Entity e)
{
    
}
