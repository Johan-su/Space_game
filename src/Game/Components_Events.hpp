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
    Transform transform;
    Mesh *mesh;
    Material *material;

    Velocity vel;
};


struct BulletSpawnEvent
{
    Transform transform;
    Mesh *mesh;
    Material *material;

    Velocity vel;
    float damage;
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
    Transform transform;
    Mesh *mesh;
    Material *material;

    Velocity vel;

    AIType ai_type;
    float health;
    float health_regen;
};


struct PlanetSpawnEvent
{
    Transform transform;
    Mesh *mesh;
    Material *material;

    float mass;

    float health;
    float health_regen;
};


struct KillEvent
{
    Entity e;
};