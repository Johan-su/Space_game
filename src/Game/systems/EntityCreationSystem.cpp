#include "EntityCreationSystem.hpp"

#include <stdio.h>




Entity EntityCreationSystem::create_ship(Iter *iter)
{
    ShipSpawnEvent *event = (ShipSpawnEvent *)iter->curr_event; 
    Entity e = Ecs::create_entity(iter->curr_registry);

    
    Ecs::set_component<Transform>(iter->curr_registry, e, {
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


    Ecs::set_component<Velocity>(iter->curr_registry, e, {0.0f, 0.0f});
   // Ecs::set_component(iter->curr_registry, e, collision);
    Ecs::set_component<GravityAffected>(iter->curr_registry, e, {});
    Ecs::set_component<MassComponent>(iter->curr_registry, e, {1000.0f});
    Ecs::set_component<AnglularVelocity>(iter->curr_registry, e, {0.0f});
    Ecs::set_component<SpriteComponent>(iter->curr_registry, e, {event->ship_type});


    return e;
}






static U32 player_id_count = 0;

Entity EntityCreationSystem::create_player(Iter *iter)
{
    PlayerSpawnEvent *event = (PlayerSpawnEvent *)iter->curr_event; 
    ShipSpawnEvent sse = {event->x, event->y, event->width, event->height, event->ship_type};
    iter->curr_event = &sse;
    Entity e = create_ship(iter);
    
    Ecs::set_component<Player>(iter->curr_registry, e, {
        .id = player_id_count++
    });

    return e;
}


Entity EntityCreationSystem::create_ai(Iter *iter) //TODO(Johan) maybe separate to different functions
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
*/return 0;}







Entity EntityCreationSystem::create_planet(Iter *iter)
{
    PlanetSpawnEvent *event = (PlanetSpawnEvent *)iter->curr_event;
    Ecs::Registry *registry = iter->curr_registry;
    
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

    Ecs::set_component<Velocity>(registry, e, {.x = event->vel_x, .y = event->vel_y});

    Ecs::set_component<MassComponent>(registry, e, {.mass = event->mass});

    Ecs::set_component<GravityAttractor>(registry, e, {});
    Ecs::set_component<SpriteComponent>(registry, e, {.texture_id = event->planet_type});





    return e;
}