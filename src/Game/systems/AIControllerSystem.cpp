#include "AIControllerSystem.hpp"

#include "../Components_Events.hpp"

#include <math.h>



void AIControllerSystem::update(Iter *it)
{

    const Group *enemy_group = Ecs::get_group<Transform, EnemyAI, FiringComponent>(it->registry);

    const Transform *t_list = Ecs::get_comp_array<Transform>(enemy_group, 0);
    const EnemyAI *Eai_list = Ecs::get_comp_array<EnemyAI>(enemy_group, 1);
    



    const Group *planet_group = Ecs::get_group<Transform, CircleCollider, Planet>(it->registry);


    Transform planet_transform = {};

    if (planet_group->size == 1)
    {
        const Transform *p_t_list = Ecs::get_comp_array<Transform>(planet_group, 0);
        const CircleCollider *p_cc_list = Ecs::get_comp_array<CircleCollider>(planet_group, 1);

        planet_transform = p_t_list[0];
    }


    for (Usize i = 0; i < enemy_group->size; ++i)
    {
        switch (Eai_list[i].ai_state)
        {
            case EnemyAiState::TargetPlanet:
            {
                Entity e = enemy_group->entity_list[i];
                Transform t = t_list[i];
                Transform *t_mut = Ecs::get_component<Transform>(it->registry, e);
                FiringComponent *fc_mut = Ecs::get_component<FiringComponent>(it->registry, e);

                float dx = planet_transform.pos.x - t.pos.x;
                float dy = planet_transform.pos.y - t.pos.y;

                float angle = atan2f(dy, dx);

                t_mut->rot = {cosf(angle), sinf(angle)};

                fc_mut->firing = true;

            } break;

            case EnemyAiState::TargetAlly:
            {

            } break;

            case EnemyAiState::TargetPlayer:
            {

            } break;
        } 
    }
}