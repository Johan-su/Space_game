#include "PlayerSystem.hpp"
#include "../Components_Events.hpp"
#include <math.h>


static float lerp(float current, float target, float step)
{
    return current + step * (target - current);
}


void PlayerSystem::update(Iter *it)
{
    Group *group = Ecs::get_group<Player>(it->registry);

    if (group->size < 1)
    {
        return;
    }

    Entity player = group->entity_list[0]; 


    Transform *transform        = Ecs::get_component<Transform>(it->registry, player);
    Velocity *vel               = Ecs::get_component<Velocity>(it->registry, player);
    AnglularVelocity *angle_vel = Ecs::get_component<AnglularVelocity>(it->registry, player);

    float vel_x_target;
    float vel_y_target;

    float speed;

    if (Real::IsKeyPressed(VK_LSHIFT))
    {
        speed = 5000.0f;
    }
    else
    {
        speed = 500.0f;
    }

    if (Real::IsKeyPressed(VK_w))
    {
        vel_x_target = speed * transform->rot.x;
        vel_y_target = speed * transform->rot.y;
    }
    else if (Real::IsKeyPressed(VK_s))
    {
        vel_x_target = -speed * transform->rot.x;
        vel_y_target = -speed * transform->rot.y;
    }
    else
    {
        vel_x_target = 0.0f;
        vel_y_target = 0.0f;
    }


    float angle_vel_target;

    if (Real::IsKeyPressed(VK_d))
    {
        angle_vel_target = 0.52359877559f * 18; // pi/6
    }
    else if (Real::IsKeyPressed(VK_a))
    {
        angle_vel_target = -0.52359877559f *18; //  -pi/6
    }
    else
    {
        angle_vel_target = 0.0f;
    }

    vel->v.x = lerp(vel->v.x, vel_x_target, it->Ts * 6);
    vel->v.y = lerp(vel->v.y, vel_y_target, it->Ts * 6);

   angle_vel->angleV = lerp(angle_vel->angleV, angle_vel_target, it->Ts * 4);
}




