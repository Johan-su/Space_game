#pragma once
#include "Entity.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"

template<typename T>
struct Collection
{
    size_t size;
    Entity *m_entities;
    T *comparray; // only one component type
};
