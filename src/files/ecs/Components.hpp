#pragma once
#include "Entity.hpp"
#include "ecs_constants.hpp"

template<typename T>
struct ComponentArray // changing variables or order will affect componentManager functions
{
    size_t size;
    Entity sparse_array[MAX_ENTITY_AMOUNT];
    Entity entity_list[MAX_ENTITY_AMOUNT];
    T dense_array[MAX_ENTITY_AMOUNT];
};








