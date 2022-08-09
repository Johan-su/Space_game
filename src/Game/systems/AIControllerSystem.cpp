#include "AIControllerSystem.hpp"

#include "../Components_Events.hpp"


void AIControllerSystem::update(Iter *it)
{

    Group *enemy_group = Ecs::get_group<Transform, EnemyAI>(it->registry);

    Transform *t_list = Ecs::get_comp_array<Transform>(enemy_group, 0);
    EnemyAI *Eai_list = Ecs::get_comp_array<EnemyAI>(enemy_group, 1);

    for (Usize i = 0; i < enemy_group->size; ++i)
    {
        switch (Eai_list[i].ai_state)
        {
            case EnemyAiState::TargetPlanet:
            {

            } break;
        }   
    }
}