#include "GravitySystem.hpp"

#include "../Components_Events.hpp"


static game_data *game;

void GravitySystem::init(game_data *game)
{
    ::game = game;
}

static const float G = 6.6743E-11f;

void GravitySystem::update(float Ts)
{
    View<Position> pos_view = Ecs::get_view<Position, Mass, GravityAttractor>(game->registry);


    View<Position> pos_view_affected = Ecs::get_view<Position, Velocity, Gravity>(game->registry);



    for (size_t i = 0; i < pos_view.size; ++i)
    {
        Entity e1 = pos_view.entity_list[i];
        Position pos = pos_view.comparray[i];
        Mass *mass = Ecs::get_component<Mass>(game->registry, e1);

        for (size_t j = 0; j < pos_view_affected.size; ++j)
        {
            Entity e2 = pos_view_affected.entity_list[i];
            Position pos2 = pos_view_affected.comparray[i];
            Velocity *vel = Ecs::get_component<Velocity>(game->registry, e2);
            Mass *mass2 = Ecs::get_component<Mass>(game->registry, e2);

            float distance2 = (pos.x - pos2.x) * (pos.x - pos2.x) + (pos.y - pos2.y) * (pos.y - pos2.y);
            float angle = atan2f((pos.y - pos2.y), (pos.x - pos2.x));


            float force = G * mass->mass * mass2->mass / distance2;
            
            float velocity = force / mass2->mass; 

            vel->x = cos(angle) * velocity;
            vel->y = sin(angle) * velocity;
        }
    }




}