#include "FiringSystem.hpp"


#include "../Components_Events.hpp"

void FiringSystem::update(Iter *it)
{
    const Group *group = Ecs::get_group<FiringComponent, Transform>(it->registry);

    const FiringComponent *fc_list = Ecs::get_comp_array<FiringComponent>(group, 0);
    const Transform *t_list = Ecs::get_comp_array<Transform>(group, 1);

    for (Usize i = 0; i < group->size; ++i)
    {
        Entity e = group->entity_list[i];
        FiringComponent fc = fc_list[i];
        Transform t = t_list[i];

        if (fc.firing == true)
        {
            FiringComponent *fc_mut = Ecs::get_component<FiringComponent>(it->registry, e);

            float speed = 4000.0f;
            
            if (fc.timer >= fc.max_time)
            {
                BulletSpawnEvent bse = {
                    .pos = t.pos + t.rot * 200.0f,
                    .rot = t.rot,
                    .vel = t.rot * speed,
                    .damage = 5.0f,
                    .bullet_sprite = Real::get_sprite("ship1_sprite"),
                };

                Ecs::push_event<BulletSpawnEvent>(it->registry, &bse);
                fc_mut->timer = 0.0f;
            }
            else
            {
                fc_mut->timer += it->Ts;
            }
        }         
    }

}