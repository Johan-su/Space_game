#include "EntityCreationSystem.hpp"


void EntityCreationSystem::create_ship(Iter *it)
{
    ShipSpawnEvent *event = (ShipSpawnEvent *)it->event; 
    Entity e = Ecs::create_entity(it->registry);

    
    Ecs::set_component<Transform>(it->registry, e, {
        .pos = {
            .x = event->x,
            .y = event->y
        },
        .rot = {
            .x = 0.0f,
            .y = 0.0f
        },
        .scale = {
            .x = 1.0f,
            .y = 1.0f
        }
    });


    Ecs::set_component<Velocity>(it->registry, e, {0.0f, 0.0f});
   // Ecs::set_component(iter->curr_registry, e, collision);
    Ecs::set_component<GravityAffected>(it->registry, e, {});
    Ecs::set_component<MassComponent>(it->registry, e, {1000.0f});
    Ecs::set_component<AnglularVelocity>(it->registry, e, {0.0f});
    Ecs::set_component<SpriteComponent>(it->registry, e, {event->ship_type});

}






static U32 player_id_count = 0;

void EntityCreationSystem::create_player(Iter *iter)
{
    PlayerSpawnEvent *event = (PlayerSpawnEvent *)iter->event; 
    Entity e = Ecs::create_entity(iter->registry);

    
    Ecs::set_component<Transform>(iter->registry, e, {
        .pos = {
            .x = event->x,
            .y = event->y
        },
        .rot = {
            .x = 0.0f,
            .y = 0.0f
        },
        .scale = {
            .x = 1.0f,
            .y = 1.0f
        }
    });


    Ecs::set_component<Velocity>(iter->registry, e, {0.0f, 0.0f});
   // Ecs::set_component(iter->curr_registry, e, collision);
    Ecs::set_component<GravityAffected>(iter->registry, e, {});
    Ecs::set_component<MassComponent>(iter->registry, e, {1000.0f});
    Ecs::set_component<AnglularVelocity>(iter->registry, e, {0.0f});
    Ecs::set_component<SpriteComponent>(iter->registry, e, {event->ship_type});

   
    Ecs::set_component<Player>(iter->registry, e, {
        .id = player_id_count++
    });
}


void EntityCreationSystem::create_ai(Iter *iter) //TODO(Johan) maybe separate to different functions
{/*
    ShipSpawnEvent sse = {event->x, event->y, event->width, event->height, event->ship_type};

    auto nai = NeutralAI(); // TODO(Johan) make better
    auto aai = AllyAI();
    auto eai = EnemyAI();
    auto hai = HostileAI();

    Entity e = create_ship(registry, &sse);
    switch (event->ai_type)
    {
        case 0:
            Ecs::set_component(registry, e, nai);
            break;

        case 1:
            Ecs::set_component(registry, e, aai);
            break;
        case 2:
            Ecs::set_component(registry, e, eai);
            break;

        case 3:
            Ecs::set_component(registry, e, hai);
            break;
        
        default:
            ECS_assert(false, "Illegal Ai type");
            break;
    }

    return e;
*/}







void EntityCreationSystem::create_planet(Iter *iter)
{
    PlanetSpawnEvent *event = (PlanetSpawnEvent *)iter->event;
    Ecs::Registry *registry = iter->registry;
    
    Entity e = Ecs::create_entity(registry);


    Ecs::set_component<Transform>(registry, e, {
        .pos = {
            .x = event->x,
            .y = event->y,
        },
        .rot = {
            .x = event->rot_x,
            .y = event->rot_y,
        },
        .scale = {
            .x = event->radius,
            .y = event->radius,
        },
    });

    Ecs::set_component<Velocity>(registry, e, {
        .v = {event->vel_x, event->vel_y}
    });

    Ecs::set_component<MassComponent>(registry, e, {.mass = event->mass});

    Ecs::set_component<GravityAttractor>(registry, e, {});
    Ecs::set_component<SpriteComponent>(registry, e, {.sprite_id = event->planet_type});
}