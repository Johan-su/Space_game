#pragma once


#include "../int.hpp"


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
    U32 sprite_id;
};



// colliders


enum ColliderType
{
    CollideWithOthers   = (1 << 0),
    OthersCollideWithMe = (1 << 1),
};


struct BoxCollider 
{
    U64 type;
};


struct CircleCollider 
{
    U64 type;
};

