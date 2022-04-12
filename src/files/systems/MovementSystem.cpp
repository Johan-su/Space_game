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

    for(size_t i = 0; i < pos_view.size; ++i) //TODO(Johan) maybe fix to better system
    {
        Entity e = pos_view.entity_list[i];
        Position *pos = Ecs::get_component<Position>(game->registry, e);
        Velocity *vel = Ecs::get_component<Velocity>(game->registry, e);

        
        pos->x += vel->x * Ts;
        pos->y += vel->y * Ts;
    }
}