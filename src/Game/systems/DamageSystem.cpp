#include "DamageSystem.hpp"



#include "../Components_Events.hpp"


void DamageSystem::onCollision(Iter *it)
{
    CollisionEvent *event = (CollisionEvent *)it->event;


    if ((event->e1_type & ColliderType::DynamicCollider) && (event->e2_type & (ColliderType::DynamicCollider|ColliderType::StaticCollider)))
    {
        Velocity *vel_mut_e1 = Ecs::get_component<Velocity>(it->registry, event->e1);
        

        vel_mut_e1->v = vel_mut_e1->v * -1.0f;

        if ((event->e1_type & ColliderType::TakesDamageOnCollide) && (event->e2_type & ColliderType::DealsDamageOnCollide))
        {
            HealthComponent *hc_mut_e1 = Ecs::get_component<HealthComponent>(it->registry, event->e1);
            DamageComponent *dc_mut_e2 = Ecs::get_component<DamageComponent>(it->registry, event->e2);

            hc_mut_e1->health -= dc_mut_e2->damage;
        }

    }
    else if (event->e1_type & ColliderType::StaticCollider)
    {
        if ((event->e1_type & ColliderType::TakesDamageOnCollide )&& (event->e2_type & ColliderType::DealsDamageOnCollide))
        {
            HealthComponent *hc_mut_e1 = Ecs::get_component<HealthComponent>(it->registry, event->e1);
            DamageComponent *dc_mut_e2 = Ecs::get_component<DamageComponent>(it->registry, event->e2);

            hc_mut_e1->health -= dc_mut_e2->damage;
        }
    }
}