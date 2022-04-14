#include "PlayerSystem.hpp"
#include "../Components_Events.hpp"


#include <SDL.h>

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

    const float speed = 100.0f;

    if(Hashmap::get_value(key_map, SDLK_w))
    {
        vel->x = speed * cosf(angle->angle);
        vel->y = speed * sinf(angle->angle);
    }
    else if(Hashmap::get_value(key_map, SDLK_s))
    {
        vel->x = -speed * cosf(angle->angle);
        vel->y = -speed * sinf(angle->angle);
    }
    else
    {
        vel->x = 0.0f;
        vel->y = 0.0f;
    }


    if(Hashmap::get_value(key_map, SDLK_d))
    {
        angle_vel->angleV = 0.52359877559f *3; // pi/6
    }
    else if(Hashmap::get_value(key_map, SDLK_a))
    {
        angle_vel->angleV = -0.52359877559f *3; //  -pi/6
    }
    else
    {
        angle_vel->angleV = 0.0f;
    }
}

