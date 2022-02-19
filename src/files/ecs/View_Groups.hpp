#pragma once
#include "Entity.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"

struct Collection 
{
    Entity *m_entities;
    void *comparray; // only one component type
    size_t size;
};
