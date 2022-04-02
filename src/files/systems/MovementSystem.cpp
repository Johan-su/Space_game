#include "MovementSystem.hpp"
#include "../Components_Events.hpp"
#include "../ecs/ecs.hpp"



void MovementSystem::update(game_data *game, float Ts)
{
    auto pos_view = Registry_functions::get_view<Position, Velocity>(game->registry);
    auto vel_view = Registry_functions::get_view<Velocity, Position>(game->registry);

    for(size_t i = 0; i < pos_view.size; ++i)
    {
        pos_view.comparray[i].x += vel_view.comparray[i].x * Ts;
        pos_view.comparray[i].y += vel_view.comparray[i].y * Ts;       
    }
}