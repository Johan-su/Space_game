#include "AngleSystem.hpp"
#include "../Components_Events.hpp"

#include <stdlib.h>

static game_data *game;

void AngleSystem::init(game_data *game)
{
    ::game = game;
}


void AngleSystem::update(float Ts)
{
    auto angle_vel_view = Ecs::get_view<AnglularVelocity, Angle>(game->registry);

    for(size_t i = 0; i < angle_vel_view.size; ++i)
    {
        Entity e = angle_vel_view.entity_list[i];
        Angle *ang = Ecs::get_component<Angle>(game->registry, e);
        AnglularVelocity ang_vel = angle_vel_view.comparray[i];

        ang->angle += ang_vel.angleV * Ts;

        if(ang->angle > 6.28318530708f) // 2pi
        {
            ang->angle -= 6.28318530708;
        } 
        else if(ang->angle < -6.28318530708f)
        {
            ang->angle += 6.28318530708;  
        }
    }
}
