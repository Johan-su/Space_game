#include "AngleSystem.hpp"
#include "../Components_Events.hpp"

#include <stdlib.h>



void AngleSystem::update(Ecs::Registry *registry, float Ts)
{
    Application::clear_view_buffer();
    auto angle_vel_view = Ecs::get_view<AnglularVelocity, Angle>(registry);

    for(size_t i = 0; i < angle_vel_view->size; ++i)
    {
        Entity e = angle_vel_view->entity_list[i];
        Angle *ang = Ecs::get_component<Angle>(registry, e);
        AnglularVelocity ang_vel = angle_vel_view->comparray[i];

        ang->angle += ang_vel.angleV * Ts;

        if(ang->angle > 6.28318530708f) // 2pi
        {
            ang->angle -= 6.28318530708;
        } 
        else if(ang->angle < -6.28318530708f)
        {
            ang->angle += 6.28318530708;  
        }
    }
}
