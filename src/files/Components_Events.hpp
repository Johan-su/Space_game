#pragma once
#include "ecs/ecs.hpp"

#include <stdint.h>


// components
struct Position
{
    float x; // center x 
    float y; // center y
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
};


struct RigidCollision
{
};


struct Collision
{
};


struct Player 
{
    uint32_t id; //TODO(Johan) probably not needed
};


struct Sprite
{
    uint32_t texture_id;
};


struct NeutralAI
{
};


struct AllyAI
{
};


struct EnemyAI
{
};


struct HostileAI
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


struct ShipSpawnEvent
{
    float x;
    float y;
    float width;
    float height; 
    uint32_t ship_type;
};



struct PlayerSpawnEvent
{
    float x;
    float y;
    float width;
    float height; 
    uint32_t ship_type;
};

struct AiSpawnEvent
{
    float x;
    float y;
    float width;
    float height; 
    uint32_t ship_type;
    uint8_t ai_type;
};