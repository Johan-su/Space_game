#include "GravitySystem.hpp"

#include "../Components_Events.hpp"

#include <math.h>

static const float G = 6.6743E-11f;

// hardcoded from planet texture
static const Usize PLANET_WIDTH  = 132;
static const Usize PLANET_HEIGHT = 132;


void GravitySystem::update(Iter *it)
{

    Group *group = Ecs::get_group<Transform, MassComponent, GravityAttractor>(it->registry);

    Transform *t_list     = Ecs::get_comp_array<Transform>(group, 0);
    MassComponent *m_list = Ecs::get_comp_array<MassComponent>(group, 1);


    Group *group_affected = Ecs::get_group<Transform, MassComponent, Velocity, GravityAffected>(it->registry);

    Transform *t_list_a     = Ecs::get_comp_array<Transform>(group_affected, 0);



    for (Usize i = 0; i < group->size; ++i)
    {
        Entity e1 = group->entity_list[i];


        Transform t = t_list[i];
        MassComponent mass = m_list[i];

        for (Usize j = 0; j < group_affected->size; ++j)
        {
            Entity e2 = group_affected->entity_list[j];
            if (e1 == e2)
            {
                continue;
            }

            Transform t2 = t_list_a[j]; 

            Velocity *vel = Ecs::get_component<Velocity>(it->registry, e2);

            float center1_x = t.pos.x + t.scale.x * PLANET_WIDTH;
            float center1_y = t.pos.y + t.scale.y * PLANET_HEIGHT;

            float center2_x = t2.pos.x; // not actually center fix later
            float center2_y = t2.pos.y;

            float distance2 = (center1_x - center2_x) * (center1_x - center2_x) + (center1_y - center2_y) * (center1_y - center2_y);
            float angle = atan2f((center1_y - center2_y), (center1_x - center2_x));

           
            float accl = G * mass.mass / distance2; 

            vel->v.x += cosf(angle) * accl * it->Ts;
            vel->v.y += sinf(angle) * accl * it->Ts;
        }
    }




}