#pragma once

#include "../ecs/Entity.hpp"
#include "../math/math_types.hpp"
#include "../int.hpp"



struct Mesh;
struct Material;
struct Sprite;






// predefined components


struct Transform
{
    Vector3f pos; // center of the entity
    Vector3f rot;
    Vector3f scale;
};


struct CameraComponent
{
    Mat4 projection;
    U16 screen_width;
    U16 screen_height;
    bool active;
    
};


struct Velocity
{
    union {Vector3f v;};
};


struct SpriteComponent
{
    Sprite *sprite;
};


struct MeshComponent
{
    Mesh *mesh;
};


struct MaterialComponent
{
    Material *material;
};

// colliders


enum ColliderType
{
    Nothing              = 0,
    DynamicCollider      = (1 << 0), // can not have both dynamic and static
    StaticCollider       = (1 << 1),
    DealsDamageOnCollide = (1 << 2),
    TakesDamageOnCollide = (1 << 3),
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
    Transform transform;

    CameraComponent cc;
};



namespace Real
{
    Mat4 transform_to_mat4(const Transform *transform);
} // namespace Real
