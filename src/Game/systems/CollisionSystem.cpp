#include "CollisionSystem.hpp"

#include "../Components_Events.hpp"

#include <assert.h>

void BoxCollisionSystem::update(Iter *it)
{
    Group *group = Ecs::get_group<Transform, Velocity, BoxCollider, SpriteComponent>(it->registry); 

    Transform *transform_list   = Ecs::get_comp_array<Transform>(group, 0);
    Velocity *velocity_list     = Ecs::get_comp_array<Velocity>(group, 1);
    BoxCollider *collider_list  = Ecs::get_comp_array<BoxCollider>(group, 2);
    SpriteComponent*sprite_list = Ecs::get_comp_array<SpriteComponent>(group, 3);

    for (I64 i = 0; i < group->size; ++i)
    {
        Entity e1 = group->entity_list[i]; 
        Transform transform_e1    = transform_list[i];
        Velocity velocity_e1      = velocity_list[i];
        BoxCollider collider_e1   = collider_list[i];
        SpriteComponent sprite_e1 = sprite_list[i];

        for (I64 j = 0; i < group->size; ++j)
        {
            Entity e2 = group->entity_list[j]; 
            Transform transform_e2    = transform_list[j];
            Velocity velocity_e2      = velocity_list[j];
            BoxCollider collider_e2   = collider_list[j];
            SpriteComponent sprite_e2 = sprite_list[j];


            if (e1 == e2)
            {
                return;
            }


            bool b1 = transform_e1.pos.x; //TODO(Johan) finish


        }
    }
    

}


