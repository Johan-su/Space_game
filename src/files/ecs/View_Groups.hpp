#pragma once
#include "Entity.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"

struct Collection 
{
    Entity m_entities[MAX_ENTITY_AMOUNT];
    void *comparray;
    uint64_t size = 0;
};
