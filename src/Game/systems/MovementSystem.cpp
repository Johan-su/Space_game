#include "MovementSystem.hpp"
#include "../Components_Events.hpp"



void MovementSystem::update(Ecs::Registry *registry, float Ts)
{
    auto vel_view = Ecs::get_view<Velocity, Position>(registry);

    for(size_t i = 0; i < vel_view.size; ++i) //TODO(Johan) maybe fix to better system
    {
        Entity e = vel_view.entity_list[i];
        Position *pos = Ecs::get_component<Position>(registry, e);
        Velocity vel = vel_view.comparray[i];

        
        pos->x += vel.x * Ts;
        pos->y += vel.y * Ts;
    }
}