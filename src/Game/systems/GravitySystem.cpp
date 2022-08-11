#include "GravitySystem.hpp"

#include "../Components_Events.hpp"

#include <math.h>
const float G = 6.6743E-11f;


// TODO(Johan) make faster 
void GravitySystem::update(Iter *it)
{

    const Group *group = Ecs::get_group<Transform, MassComponent, GravityAttractor>(it->registry);

    const Transform *t_list     = Ecs::get_comp_array<Transform>(group, 0);
    const MassComponent *m_list = Ecs::get_comp_array<MassComponent>(group, 1);


    const Group *group_affected = Ecs::get_group<Transform, MassComponent, Velocity, GravityAffected>(it->registry);

    const Transform *t_list_a     = Ecs::get_comp_array<Transform>(group_affected, 0);



    for (I64 i = 0; i < group->size; ++i)
    {
        Entity e1 = group->entity_list[i];


        Transform t = t_list[i];
        MassComponent mass = m_list[i];

        for (I64 j = 0; j < group_affected->size; ++j)
        {
            Entity e2 = group_affected->entity_list[j];
            if (e1 == e2)
            {
                continue;
            }

            Transform t2 = t_list_a[j]; 

            Velocity *vel = Ecs::get_component<Velocity>(it->registry, e2);

            float center1_x = t.pos.x;
            float center1_y = t.pos.y;

            float center2_x = t2.pos.x;
            float center2_y = t2.pos.y;

            float center_dx = center1_x - center2_x;
            float center_dy = center1_y - center2_y;

            float distance2 = (center_dx) * (center_dx) + (center_dy) * (center_dy);
            float angle = atan2f((center_dy), (center_dx));

           
            float accl = G * mass.mass / (distance2 + __FLT_MIN__); // FLT_MIN to avoid div by zero 

            vel->v.x += cosf(angle) * accl * it->Ts;
            vel->v.y += sinf(angle) * accl * it->Ts;
        }
    }




}