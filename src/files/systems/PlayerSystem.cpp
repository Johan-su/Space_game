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


    Velocity *vel = Ecs::get_component<Velocity>(game->registry, player);


    if(Hashmap::get_value(key_map, SDLK_s))
    {
        vel->y = 1.0f;
        printf("vel y = 1.0f\n");
    }
    else if(Hashmap::get_value(key_map, SDLK_w))
    {
        vel->y = -1.0f;
    }
    else
    {
        vel->y = 0.0f;
    }


    if(Hashmap::get_value(key_map, SDLK_d))
    {
        vel->x = 1.0f;
    }
    else if(Hashmap::get_value(key_map, SDLK_a))
    {
        vel->x = -1.0f;
    }
    else
    {
        vel->x = 0.0f;
    }

    vel->x *= 1000.0f;
    vel->y *= 1000.0f;
}

