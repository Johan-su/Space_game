#pragma once
#include "ecs/ecs.hpp"

#include <stdint.h>


// components
struct Position
{
    float x;
    float y;
};


struct Size
{
    float x;
    float y;
};


struct Velocity
{
    float x;
    float y;
};


struct Player
{
};


// events




struct CollisionEvent
{
    Entity e1;
    Entity e2;
};