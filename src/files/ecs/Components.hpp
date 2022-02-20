#pragma once
#include "Entity.hpp"
#include "ecs_constants.hpp"
#include "ecs_assert.hpp"



struct Position
{
    float x;
    float y;
};


struct Size
{
    float width;
    float height;
};


struct Health_hp
{
    float hp;
};

struct Health_regen
{
    float hp_regen;
};



template<typename T>
struct ComponentArray
{
    size_t size;
    Entity sparse_array[MAX_ENTITY_AMOUNT];
    Entity entity_list[MAX_ENTITY_AMOUNT];
    T dense_array[MAX_ENTITY_AMOUNT];
};








