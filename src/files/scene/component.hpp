#pragma once


#include "../int.hpp"

class Vector2
{
public:
    float x;
    float y;

    float magnitude();
    void normalize();
};



// predefined components


struct Transform
{
    Vector2 pos; // center of the entity
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
    Vector2 v;
};


struct SpriteComponent
{
    U32 sprite_id;
};


// colliders

struct BoxCollider {};
struct CircleCollider {};

