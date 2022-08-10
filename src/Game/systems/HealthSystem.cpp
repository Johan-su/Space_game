#include "HealthSystem.hpp"


#include "../Components_Events.hpp"



void HealthSystem::update(Iter *it)
{
    Group *group = Ecs::get_group<HealthComponent>(it->registry);

    HealthComponent *hc_list = Ecs::get_comp_array<HealthComponent>(group, 0);


    for (Usize i = 0; i < group->size; ++i)
    {

        Entity e = group->entity_list[i];
        HealthComponent hc = hc_list[i];

        if (hc.health < 0.0f)
        {
            Ecs::destroy_entity(it->registry, e);
        }
        else
        {
            HealthComponent *hc_e = Ecs::get_component<HealthComponent>(it->registry, e);
            hc_e->health = hc.health + hc.health_regen * it->Ts;
        }
    }
}