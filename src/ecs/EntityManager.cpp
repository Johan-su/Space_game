#include "Entity.hpp"
#include "Signature.hpp"
#include "MemoryManager.hpp"
#include "EntityManager.hpp"

void EntityManager::init(MemoryManager *mem)
{
    m_entitycount = 0;
    m_signatures = mem->alloc<Signature>(MAX_ENTITY_AMOUNT);
}

void EntityManager::clean(MemoryManager *mem)
{
    mem->dealloc<Signature>(m_signatures, MAX_ENTITY_AMOUNT);
}

Entity EntityManager::create_entity()
{
    Entity e = Entity();
    e = {++m_entitycount};
    return e;
}
void EntityManager::set_entity_signature(Entity e, Signature sig)
{
    m_signatures[e.id] = sig;
}
Signature EntityManager::get_entity_signature(Entity e)
{
    return m_signatures[e.id];
}