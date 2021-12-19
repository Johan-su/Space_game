#include "Registry.hpp"

bool Registry::init()
{
    m_memoryManager = new MemoryManager();
    m_memoryManager->init();

    m_entityManager = m_memoryManager->alloc<EntityManager>();
    m_entityManager->init(m_memoryManager);

    m_componentManager = m_memoryManager->alloc<ComponentManager>();
    m_componentManager->init(m_memoryManager);

    m_systemManager = m_memoryManager->alloc<SystemManager>();
    m_systemManager->init();
    return 0;
}

bool Registry::clean()
{
    m_systemManager->clean();
    m_memoryManager->dealloc<SystemManager>(m_systemManager);

    m_componentManager->clean(m_memoryManager);
    m_memoryManager->dealloc<ComponentManager>(m_componentManager);

    m_entityManager->clean(m_memoryManager);
    m_memoryManager->dealloc<EntityManager>(m_entityManager);

    m_memoryManager->clean();
    delete m_memoryManager;

    m_systemManager = nullptr;
    m_componentManager = nullptr;
    m_entityManager = nullptr;
    m_memoryManager = nullptr;
    return 0;
}

Entity Registry::create_entity()
{
    return m_entityManager->create_entity();
}
void Registry::destroy_entity(Entity e)
{

}

void Registry::set_entity_signature(Entity e, Signature sig)
{
    m_entityManager->set_entity_signature(e, sig);
    m_systemManager->set_entity_signature(e, sig);
}

