#pragma once
#include "Entity.hpp"
#include "ecs_constants.hpp"



template<typename T>
struct View
{
    Usize size;
    Entity *entity_list;
    T *comparray;
};
