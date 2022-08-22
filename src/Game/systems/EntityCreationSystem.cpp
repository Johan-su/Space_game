#include "EntityCreationSystem.hpp"




void EntityCreationSystem::create_player(Iter *iter)
{
    PlayerSpawnEvent *event = (PlayerSpawnEvent *)iter->event; 
    Entity e = Ecs::create_entity(iter->registry);

    
    Ecs::set_component<Transform>(iter->registry, e, {
        event->transform,
    });


    Ecs::set_component<Velocity>(iter->registry, e, {0.0f, 0.0f});
   // Ecs::set_component(iter->curr_registry, e, collision);
    Ecs::set_component<GravityAffected>(iter->registry, e, {});
    Ecs::set_component<MassComponent>(iter->registry, e, {1000.0f});

    Ecs::set_component<MeshComponent>(iter->registry, e, {
        .mesh = event->mesh,
    });

    Ecs::set_component<MaterialComponent>(iter->registry, e, {
        .material = event->material,
    });

    /*Ecs::set_component<BoxCollider>(iter->registry, e ,{
        .type = ColliderType::DynamicCollider|ColliderType::StaticCollider,
        .size = {
            .x = (float)sprite->width,
            .y = (float)sprite->height,
        },  
    });*/

    Ecs::set_component<Player>(iter->registry, e, {});
}


void EntityCreationSystem::create_bullet(Iter *it)
{
    BulletSpawnEvent *event = (BulletSpawnEvent *)it->event;

    Entity e = Ecs::create_entity(it->registry);



    Ecs::set_component<Transform>(it->registry, e, {
        event->transform,
    });


    Ecs::set_component<Velocity>(it->registry, e, {event->vel}); 
    Ecs::set_component<GravityAffected>(it->registry, e, {});
    Ecs::set_component<MassComponent>(it->registry, e, {1000.0f});
   

   
   
    /*Ecs::set_component<BoxCollider>(it->registry, e, {
        .type = ColliderType::DynamicCollider|ColliderType::DealsDamageOnCollide|ColliderType::TakesDamageOnCollide,
        .size = {
            .x = (float)sprite->width,
            .y = (float)sprite->height,
        },     
    });*/

   
    Ecs::set_component<HealthComponent>(it->registry, e, {
        .health = 10.0f,
        .health_regen = 0.0f,
    });

   
    Ecs::set_component<DamageComponent>(it->registry, e, {
        .damage = 5.0f
    });

}


void EntityCreationSystem::create_ai(Iter *it) //TODO(Johan) maybe separate to different functions
{
    AiSpawnEvent *event = (AiSpawnEvent *)it->event;
    Entity e = Ecs::create_entity(it->registry);

    Ecs::set_component<Transform>(it->registry, e, {
        event->transform
    });

    Ecs::set_component<Velocity>(it->registry, e, {
        event->vel,
    });



    /*Ecs::set_component<BoxCollider>(it->registry, e, {
        .type = ColliderType::DynamicCollider|ColliderType::TakesDamageOnCollide,
        .size = {
            .x = (float)sprite->width,
            .y = (float)sprite->height,
        },  
    });*/


    switch (event->ai_type)
    {
        case AIType::Neutral:
        {
            Ecs::set_component<NeutralAI>(it->registry, e, {});
        } break;


        case AIType::Ally:
        {
            Ecs::set_component<AllyAI>(it->registry, e, {});
        } break;


        case AIType::Enemy:
        {
            Ecs::set_component<EnemyAI>(it->registry, e, {});
        } break;        


        case AIType::Hostile:
        {
            Ecs::set_component<HostileAI>(it->registry, e, {});
        } break;    
    }

    Ecs::set_component<HealthComponent>(it->registry, e, {
        .health = event->health,
        .health_regen = event->health_regen,
    });

    Ecs::set_component<FiringComponent>(it->registry, e, {
        .timer = 0.0f,
        .max_time = 0.4f,
        .firing = false,
    });
}


void EntityCreationSystem::create_planet(Iter *it)
{
    PlanetSpawnEvent *event = (PlanetSpawnEvent *)it->event;
    Ecs::Registry *registry = it->registry;
    
    Entity e = Ecs::create_entity(registry);


    Ecs::set_component<Transform>(registry, e, {
        event->transform,
    });


    Ecs::set_component<MassComponent>(registry, e, {.mass = event->mass});

    Ecs::set_component<GravityAttractor>(registry, e, {});



   /*Ecs::set_component<CircleCollider>(it->registry, e, {
        .type = ColliderType::StaticCollider|ColliderType::TakesDamageOnCollide,
        .radius = (float)sprite->width / 2.0f,
   });*/


    Ecs::set_component<HealthComponent>(registry, e, {
        .health = event->health,
        .health_regen = event->health_regen,
    });

    Ecs::set_component<Planet>(registry, e, {});
}
