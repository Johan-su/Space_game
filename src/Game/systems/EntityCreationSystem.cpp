#include "EntityCreationSystem.hpp"




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

    Sprite *sprite = Application::get_sprite(event->ship_type);
    Ecs::set_component<SpriteComponent>(iter->registry, e, {
        .sprite = sprite,
    });

    Ecs::set_component<BoxCollider>(iter->registry, e ,{
        .type = ColliderType::CollideWithOthers|ColliderType::OthersCollideWithMe,
        .size = {
            .x = (float)Application::get_sprite_width(sprite), 
            .y = (float)Application::get_sprite_height(sprite),
        },
    });

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
   
    Sprite *sprite = Application::get_sprite(SHIP1);
   Ecs::set_component<SpriteComponent>(it->registry, e, {
        .sprite = sprite, 
   });
   
   
   Ecs::set_component<BoxCollider>(it->registry, e, {
        .type = ColliderType::CollideWithOthers|ColliderType::OthersCollideWithMe,
        .size = {
            .x = (float)Application::get_sprite_width(sprite),
            .y = (float)Application::get_sprite_height(sprite),
        },     
   });

   
   Ecs::set_component<HealthComponent>(it->registry, e, {
        .health = 10.0f,
        .health_regen = -1.0f,
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

    Sprite *sprite = Application::get_sprite(event->ship_type);
    Ecs::set_component<SpriteComponent>(it->registry, e, {
        .sprite = sprite,
    });


    Ecs::set_component<BoxCollider>(it->registry, e, {
        .type = ColliderType::CollideWithOthers|ColliderType::OthersCollideWithMe,
        .size = {
            .x = (float)Application::get_sprite_width(sprite), 
            .y = (float)Application::get_sprite_height(sprite),
        },
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

    Ecs::set_component<FiringComponent>(it->registry, e, {
        .timer = 0.0f,
        .max_time = 0.2f,
        .firing = false,
    });
}







void EntityCreationSystem::create_planet(Iter *it)
{
    PlanetSpawnEvent *event = (PlanetSpawnEvent *)it->event;
    Ecs::Registry *registry = it->registry;
    
    Entity e = Ecs::create_entity(registry);


    Ecs::set_component<Transform>(registry, e, {
        .pos = event->pos,
        .rot = event->rot,
        .scale = {event->scale, event->scale},
    });

    Ecs::set_component<Velocity>(registry, e, {.v = {0.0f, 0.0f},
    });

    Ecs::set_component<MassComponent>(registry, e, {.mass = event->mass});

    Ecs::set_component<GravityAttractor>(registry, e, {});

    Sprite *sprite = Application::get_sprite(event->planet_type);
    Ecs::set_component<SpriteComponent>(registry, e, {
        .sprite = sprite,
    });


   Ecs::set_component<CircleCollider>(it->registry, e, {
        .type = ColliderType::CollideWithOthers|ColliderType::OthersCollideWithMe,
        .radius = (float)Application::get_sprite_width(sprite) / 2.0f,
   });

    Ecs::set_component<Planet>(registry, e, {});
}
