#include "GravitySystem.hpp"

#include "../Components_Events.hpp"

#include <math.h>

static const float G = 6.6743E-11f;

void GravitySystem::update(Ecs::Registry *registry, float Ts)
{
    Application::clear_view_buffer();
    View<Position> *pos_view       = Ecs::get_view<Position, MassComponent, Circle_size, GravityAttractor>(registry);
    View<MassComponent> *mass_view = Ecs::get_view<MassComponent, Circle_size, GravityAttractor, Position>(registry);
    View<Circle_size> *csize_view  = Ecs::get_view<Circle_size, GravityAttractor, Position, MassComponent>(registry);


    View<Position> *pos_view_affected       = Ecs::get_view<Position, SizeComponent, Velocity, MassComponent, GravityAffected>(registry);
    View<SizeComponent> *size_view_affected = Ecs::get_view<SizeComponent, Velocity, MassComponent, GravityAffected, Position>(registry);



    for (size_t i = 0; i < pos_view->size; ++i)
    {
        Entity e1          = pos_view->entity_list[i];

        Position pos       = pos_view->comparray[i];
        Circle_size csize  = csize_view->comparray[i];
        MassComponent mass = mass_view->comparray[i];

        for (size_t j = 0; j < pos_view_affected->size; ++j)
        {
            Entity e2 = pos_view_affected->entity_list[j];
            if(e1 == e2)
            {
                continue;
            }
            Position pos2       = pos_view_affected->comparray[j];
            SizeComponent size2 = size_view_affected->comparray[j];

            Velocity *vel       = Ecs::get_component<Velocity>(registry, e2);

            float center1_x = pos.x + csize.radius;
            float center1_y = pos.y + csize.radius;

            float center2_x = pos2.x + size2.width / 2;
            float center2_y = pos2.y + size2.height / 2;

            float distance2 = (center1_x - center2_x) * (center1_x - center2_x) + (center1_y - center2_y) * (center1_y - center2_y);
            float angle = atan2f((center1_y - center2_y), (center1_x - center2_x));

           
            float accl = G * mass.mass / distance2; 

            vel->x += cosf(angle) * accl * Ts;
            vel->y += sinf(angle) * accl * Ts;
        }
    }




}