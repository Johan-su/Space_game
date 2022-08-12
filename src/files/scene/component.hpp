#pragma once

#include "../ecs/Entity.hpp"
#include "../int.hpp"

struct Sprite;


class Vector2i
{
public:
    I32 x;
    I32 y;
};



class Vector2f
{
public:
    float x;
    float y;

    Vector2f operator*(float scalar) { return Vector2f{this->x * scalar, this->y * scalar}; }


    float magnitude();
    void normalize();
};



// predefined components


struct Transform
{
    Vector2f pos; // center of the entity
    Vector2f rot;
    Vector2f scale;
};


struct CameraComponent
{
    Vector2f world_scale;

    U16 screen_width;
    U16 screen_height;

    bool active;
    
};


struct Velocity
{
    Vector2f v;
};


struct SpriteComponent
{
    Sprite *sprite;
};



// colliders


enum ColliderType
{
    Nothing              = 0,
    CollideWithOthers    = (1 << 0),
    OthersCollideWithMe  = (1 << 1),
    DealsDamageOnCollide = (1 << 2),
};


struct BoxCollider 
{
    U64 type;
    Vector2f size; // gets scaled by transform.scale
};


struct CircleCollider 
{
    U64 type;
    float radius;
};




// events

struct CollisionEvent
{
    U64 e1_type;
    U64 e2_type;
    Entity e1;
    Entity e2;
};




struct CameraSpawnEvent
{
    Vector2f pos;
    Vector2f rot;

    Vector2f world_scale;

    U16 screen_width;
    U16 screen_height;

    bool active;
};