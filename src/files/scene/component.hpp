#pragma once


#include "../int.hpp"

struct Vector2
{
    float x;
    float y;
};



// predefined components


struct Transform
{
    Vector2 pos;
    Vector2 rot;
    Vector2 scale;
};


struct CameraComponent
{
    Vector2 world_scale;

    U16 screen_width;
    U16 screen_height;

    bool active;
    
};


struct Velocity
{
    float x;
    float y;
};


struct SpriteComponent
{
    U32 texture_id;
};


// colliders

struct BoxCollider {};
struct CircleCollider {};

