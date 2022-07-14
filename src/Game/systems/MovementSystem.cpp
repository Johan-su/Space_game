#include "MovementSystem.hpp"
#include "../Components_Events.hpp"



void MovementSystem::update(Iter *iter)
{
    View<Velocity> *vel_view = Ecs::get_view<Velocity, Transform>(iter->registry);

    for(size_t i = 0; i < vel_view->size; ++i)
    {
        Entity e = vel_view->entity_list[i];
        Transform *transform = Ecs::get_component<Transform>(iter->registry, e);
        Velocity vel = vel_view->comparray[i];

        
        transform->pos.x += vel.v.x * iter->Ts;
        transform->pos.y += vel.v.y * iter->Ts;
    }
}