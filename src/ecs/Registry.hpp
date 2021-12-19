#pragma once
#include "MemoryManager.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"

class Registry
{
public:
    bool init();
    bool clean();

    Entity create_entity();
    void destroy_entity(Entity e);
    Signature get_entity_signature(Entity e);
public:

    template<typename T>
    void set_component(Entity e, T comp)
    {
        Signature sig = m_componentManager->get_component_signature<T>();

        m_componentManager->set_component<T>(e, comp);
        set_entity_signature(e, sig);
    }

    template<typename T>
    T get_component(Entity e)
    {
       return m_componentManager->get_component<T>(e);
    }
    template<typename T>
    Signature get_component_signature()
    {
        return m_componentManager->get_component_signature<T>();
    }

private:
    void set_entity_signature(Entity e, Signature sig);


private:

    MemoryManager *m_memoryManager;
    EntityManager *m_entityManager;
    ComponentManager *m_componentManager;
    SystemManager *m_systemManager;

};
