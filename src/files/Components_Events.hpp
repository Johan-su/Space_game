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
    float width;
    float height;
};


struct Velocity
{
    float x;
    float y;
};


struct Angle
{
    float angle;
};


struct AnglularVelocity
{
    float angleV;
}


struct RigidCollision
{
};


struct Collision
{
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

struct SpawnEvent
{
    float x;
    float y;
};