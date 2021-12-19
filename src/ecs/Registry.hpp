#pragma once
#include "EntityManager.hpp"
#include "MemoryManager.hpp"
#include "ComponentManager.hpp"

class Registry
{
public:
    void init();
    void clean();
    Entity create_entity();
    void set_entity_signature(/*signature goes here*/);
    /*signature goes here*/void get_entity_signature(Entity e);

    void get_component(Entity e);
private:

    EntityManager m_EntityManager;
    MemoryManager m_MemoryManager;
    ComponentManager m_ComponentManager;

};
