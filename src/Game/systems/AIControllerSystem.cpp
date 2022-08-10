#include "AIControllerSystem.hpp"

#include "../Components_Events.hpp"





void AIControllerSystem::update(Iter *it)
{

    Group *enemy_group = Ecs::get_group<Transform, EnemyAI>(it->registry);

    Transform *t_list = Ecs::get_comp_array<Transform>(enemy_group, 0);
    EnemyAI *Eai_list = Ecs::get_comp_array<EnemyAI>(enemy_group, 1);
    



    Group *planet_group = Ecs::get_group<Transform, CircleCollider, Planet>(it->registry);

    Transform *p_t_list = Ecs::get_comp_array<Transform>(planet_group, 0);
    CircleCollider *p_cc_list = Ecs::get_comp_array<CircleCollider>(planet_group, 1);


    Transform planet_transform = p_t_list[0];


    for (Usize i = 0; i < enemy_group->size; ++i)
    {
        switch (Eai_list[i].ai_state)
        {
            case EnemyAiState::TargetPlanet:
            {
                Entity e = enemy_group->entity_list[i];
                Transform t = t_list[i];

                float dx = planet_transform.pos.x - t.pos.x;
                float dy = planet_transform.pos.y - t.pos.y;

                float angle = atan2(dy, dx);


                t_list->rot = {cosf(angle), sinf(angle)};

                float speed = 100.0f;

                BulletSpawnEvent bse = {
                    .pos = t.pos,
                    .rot = t.rot,
                    .vel = t.rot * speed,
                    .damage = 5.0f,
                    .bullet_type = SHIP1,
                };

                Ecs::push_event<BulletSpawnEvent>(it->registry, &bse); //TODO(Johan): add firing component

            } break;
        }   
    }
}