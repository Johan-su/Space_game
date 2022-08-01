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


struct HealthComponent
{
    float health;
};


struct DamageComponent
{
    float damage;
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


struct BulletSpawnEvent
{
    Vector2 pos;
    Vector2 rot;
    Vector2 vel;

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