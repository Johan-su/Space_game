#include "EntityCreationSystem.hpp"

#include <stdio.h>




Entity EntityCreationSystem::create_ship(Ecs::Registry *registry, ShipSpawnEvent *event)
{
    float x            = event->x;
    float y            = event->y;
    float width        = event->width;
    float height       = event->height;
    uint32_t ship_type = event->ship_type;

    Entity e = Ecs::create_entity(registry);

    Position position = {x, y};
    Velocity velocity = {0.0f, 0.0f};

    Collision collision = {};
    GravityAffected gravity_affected = {};
    MassComponent mass = {1000.0f};
    

    SizeComponent size = {width, height};

    Angle angle = {0.0f};

    AnglularVelocity angleVel = {0.0f};  
    SpriteComponent spriteComp = {ship_type};


    Ecs::set_component(registry, e, position);
    Ecs::set_component(registry, e, velocity);
    Ecs::set_component(registry, e, collision);
    Ecs::set_component(registry, e, gravity_affected);
    Ecs::set_component(registry, e, mass);
    Ecs::set_component(registry, e, size);
    Ecs::set_component(registry, e, angle);
    Ecs::set_component(registry, e, angleVel);
    Ecs::set_component(registry, e, spriteComp);


    return e;
}






static uint32_t player_id_count = 0;

Entity EntityCreationSystem::create_player(Ecs::Registry *registry, PlayerSpawnEvent *event)
{
    ShipSpawnEvent sse = {event->x, event->y, event->width, event->height, event->ship_type};

    Entity e = create_ship(registry, &sse);
    Player player_comp = Player();
    player_comp.id = player_id_count++;
    Ecs::set_component(registry, e, player_comp);

    return e;
}


Entity EntityCreationSystem::create_ai(Ecs::Registry *registry, AiSpawnEvent *event) //TODO(Johan) maybe separate to different functions
{
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
}







Entity EntityCreationSystem::create_planet(Ecs::Registry *registry, PlanetSpawnEvent *event)
{
    Entity e = Ecs::create_entity(registry);


    Ecs::set_component<Position>(registry, e, {.x = event->x, .y = event->y});
    Ecs::set_component<Velocity>(registry, e, {.x = event->vel_x, .y = event->vel_y});

    Ecs::set_component<Circle_size>(registry, e, {.radius = event->radius});
    Ecs::set_component<MassComponent>(registry, e, {.mass = event->mass});

    Ecs::set_component<GravityAttractor>(registry, e, {});
    Ecs::set_component<SpriteComponent>(registry, e, {.texture_id = event->planet_type});





    return e;
}