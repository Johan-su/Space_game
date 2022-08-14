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


struct HealthComponent
{
    float health;
    float health_regen;
};


struct DamageComponent
{
    float damage;
};


enum EnemyAiState
{
    TargetPlanet,
    TargetAlly,
    TargetPlayer,
};


struct EnemyAI
{
    EnemyAiState ai_state;
};


struct FiringComponent
{
    float timer;
    float max_time;
    bool firing;
};


// tags
struct Player {};
struct NeutralAI {};
struct AllyAI {};
struct HostileAI {};
struct GravityAttractor {};
struct GravityAffected {};
struct Planet {};



// events



struct PlayerSpawnEvent
{
    Vector2f pos;
    float scale;
    Sprite *ship_sprite;
};


struct BulletSpawnEvent
{
    Vector2f pos;
    Vector2f rot;
    Vector2f vel;
    float damage;
    Sprite *bullet_sprite;
};


enum AIType
{
    Neutral,
    Ally,
    Enemy,
    Hostile,
};


struct AiSpawnEvent
{
    Vector2f pos;
    float scale;
    Sprite *ship_sprite;
    AIType ai_type;
    float health;
    float health_regen;
};


struct PlanetSpawnEvent
{
    Vector2f pos;
    Vector2f rot;

    float scale;
    float mass;

    Sprite *planet_sprite;

    float health;
    float health_regen;
};


struct KillEvent
{
    Entity e;
};