#include "Entity.hpp"
#include "Signature.hpp"
#include "MemoryManager.hpp"
#include "EntityManager.hpp"

void Entity_functions::init(Memory_pool *mem, Entity_data *e_data)
{
    e_data->m_entitycount = 0;
    e_data->m_signatures = Memory::alloc<Signature>(mem, MAX_ENTITY_AMOUNT);
}

void Entity_functions::clean(Memory_pool *mem, Entity_data *e_data)
{
    Memory::dealloc<Signature>(mem, e_data->m_signatures, MAX_ENTITY_AMOUNT);
}

Entity Entity_functions::create_entity(Entity_data *e_data)
{
    Entity e = Entity();
    e = {++e_data->m_entitycount};
    return e;
}
void Entity_functions::destroy_entity(Entity_data *edata, Entity e)
{
    Entity_functions::set_entity_signature(edata, e, 0);
    --edata->m_entitycount;
}

void Entity_functions::set_entity_signature(Entity_data *e_data, Entity e, Signature sig)
{
    e_data->m_signatures[e] = sig;
}
Signature Entity_functions::get_entity_signature(Entity_data *e_data, Entity e)
{
    return e_data->m_signatures[e];
}