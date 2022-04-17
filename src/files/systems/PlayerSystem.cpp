#include "PlayerSystem.hpp"
#include "../Components_Events.hpp"


#include <SDL.h>


static float lerp(float current, float target, float step)
{
    return current + step * (target - current);
}

static game_data *game;

static Entity player = ENTITY_NULL;

void PlayerSystem::init(game_data *game)
{
    ::game = game;
}


void PlayerSystem::set_player_entity(Entity id)
{
    player = id;
}

void PlayerSystem::update(float Ts)
{
    if(player == ENTITY_NULL)
    {
        return;
    }

    auto *key_map = game->key_map;

    Velocity *vel               = Ecs::get_component<Velocity>(game->registry, player);
    AnglularVelocity *angle_vel = Ecs::get_component<AnglularVelocity>(game->registry, player);
    Angle *angle                = Ecs::get_component<Angle>(game->registry, player);

    float vel_x_target;
    float vel_y_target;

    float speed;

    if(Hashmap::get_value(key_map, SDLK_LSHIFT))
    {
        speed = 5000.0f;
    }
    else
    {
        speed = 500.0f;
    }

    if(Hashmap::get_value(key_map, SDLK_w))
    {
        vel_x_target = speed * cosf(angle->angle);
        vel_y_target = speed * sinf(angle->angle);
    }
    else if(Hashmap::get_value(key_map, SDLK_s))
    {
        vel_x_target = -speed * cosf(angle->angle);
        vel_y_target = -speed * sinf(angle->angle);
    }
    else
    {
        vel_x_target = 0.0f;
        vel_y_target = 0.0f;
    }


    float angle_vel_target;

    if(Hashmap::get_value(key_map, SDLK_d))
    {
        angle_vel_target = 0.52359877559f *18; // pi/6
    }
    else if(Hashmap::get_value(key_map, SDLK_a))
    {
        angle_vel_target = -0.52359877559f *18; //  -pi/6
    }
    else
    {
        angle_vel_target = 0.0f;
    }

    vel->x = lerp(vel->x, vel_x_target, Ts * 6);
    vel->y = lerp(vel->y, vel_y_target, Ts * 6);

    angle_vel->angleV = lerp(angle_vel->angleV, angle_vel_target, Ts * 4);
}




