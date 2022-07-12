#pragma once

#include <stdint.h>


// components


struct AnglularVelocity
{
    float angleV;
};


struct MassComponent
{
    float mass;
};


struct Player 
{
    uint32_t id; //TODO(Johan) probably not needed
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


struct GravityAttractor
{
};


struct GravityAffected
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


struct PlanetSpawnEvent
{
    float x;
    float y;

    float rot_x;
    float rot_y;

    float vel_x;
    float vel_y;

    float radius;
    float mass;

    uint8_t planet_type;
};