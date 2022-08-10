#include "EntityCreationSystem.hpp"




static U32 player_id_count = 0;

void EntityCreationSystem::create_player(Iter *iter)
{
    PlayerSpawnEvent *event = (PlayerSpawnEvent *)iter->event; 
    Entity e = Ecs::create_entity(iter->registry);

    
    Ecs::set_component<Transform>(iter->registry, e, {
        .pos = event->pos,
        .rot = {0.0f, 0.0f},
        .scale = {event->scale, event->scale},
    });


    Ecs::set_component<Velocity>(iter->registry, e, {0.0f, 0.0f});
   // Ecs::set_component(iter->curr_registry, e, collision);
    Ecs::set_component<GravityAffected>(iter->registry, e, {});
    Ecs::set_component<MassComponent>(iter->registry, e, {1000.0f});
    Ecs::set_component<SpriteComponent>(iter->registry, e, {event->ship_type});

    Ecs::set_component<Player>(iter->registry, e, {});
}


void EntityCreationSystem::create_bullet(Iter *it)
{

    BulletSpawnEvent *event = (BulletSpawnEvent *)it->event;

    Entity e = Ecs::create_entity(it->registry);



    Ecs::set_component<Transform>(it->registry, e, {
        .pos = event->pos,
        .rot = event->rot,
        .scale = {
            .x = 1.0f,
            .y = 0.2f
        }
    });


   Ecs::set_component<Velocity>(it->registry, e, {event->vel}); 
   Ecs::set_component<GravityAffected>(it->registry, e, {});
   Ecs::set_component<MassComponent>(it->registry, e, {1000.0f});
   

   Ecs::set_component<SpriteComponent>(it->registry, e, {
        .sprite_id = SHIP1, 
   });
   
   
   Ecs::set_component<BoxCollider>(it->registry, e, {
        .type = ColliderType::CollideWithOthers|ColliderType::OthersCollideWithMe,        
   });

   
   Ecs::set_component<HealthComponent>(it->registry, e, {
        .health = 10.0f,
        .health_regen = -0.5f,
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
        .pos = event->pos,
        .rot = {0.0f, 0.0f},
        .scale = {event->scale, event->scale},
    });


    Ecs::set_component<SpriteComponent>(it->registry, e, {
        .sprite_id = event->ship_type,
    });


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
}







void EntityCreationSystem::create_planet(Iter *iter)
{
    PlanetSpawnEvent *event = (PlanetSpawnEvent *)iter->event;
    Ecs::Registry *registry = iter->registry;
    
    Entity e = Ecs::create_entity(registry);


    Ecs::set_component<Transform>(registry, e, {
        .pos = event->pos,
        .rot = event->rot,
        .scale = {event->scale, event->scale},
    });


    Ecs::set_component<MassComponent>(registry, e, {.mass = event->mass});

    Ecs::set_component<GravityAttractor>(registry, e, {});
    Ecs::set_component<SpriteComponent>(registry, e, {.sprite_id = event->planet_type});
    Ecs::set_component<Planet>(registry, e, {});
}
