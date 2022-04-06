#include "MovementSystem.hpp"
#include "../Components_Events.hpp"
#include "../ecs/ecs.hpp"


static game_data *game;

void MovementSystem::init(game_data *game)
{
    ::game = game;
}


void MovementSystem::update(float Ts)
{
    auto pos_view = Ecs::get_view<Position, Velocity>(game->registry);
    auto vel_view = Ecs::get_view<Velocity, Position>(game->registry);

    for(size_t i = 0; i < pos_view.size; ++i)
    {
        pos_view.comparray[i].x += vel_view.comparray[i].x * Ts;
        pos_view.comparray[i].y += vel_view.comparray[i].y * Ts;
    }
}