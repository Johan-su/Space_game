#include "AngleSystem.hpp"
#include "../Components_Events.hpp"


void AngleSystem::update(Iter *iter)
{
    View<AnglularVelocity> *angle_vel_view = Ecs::get_view<AnglularVelocity, Transform>(iter->registry);

    for (Usize i = 0; i < angle_vel_view->size; ++i)
    {
        Entity e = angle_vel_view->entity_list[i];
        Transform *transform = Ecs::get_component<Transform>(iter->registry, e);
        AnglularVelocity ang_vel = angle_vel_view->comparray[i];


       float angle = atan2(transform->rot.y, transform->rot.x);

       transform->rot.x = cos(angle + ang_vel.angleV * iter->Ts);
       transform->rot.y = sin(angle + ang_vel.angleV * iter->Ts);

    }
}
