#include "EntityCreationSystem.hpp"

#include <stdio.h>

#include "../Game.hpp"


Entity EntityCreationSystem::create_ship(Ecs::Registry *registry, ShipSpawnEvent *event)
{
    float x            = event->x;
    float y            = event->y;
    float width        = event->width;
    float height       = event->height;
    uint32_t ship_type = event->ship_type;

    Entity e = Ecs::create_entity(registry);

    Collision collision = {};
    
    Position position = {x, y};

    Velocity velocity = {0.0f, 0.0f};

    Size size = {width, height};

    Angle angle = {0.0f};

    AnglularVelocity angleVel = {0.0f};
    
    SpriteComponent spriteComp = {ship_type};


    Ecs::set_component(registry, e, collision);
    Ecs::set_component(registry, e, position);
    Ecs::set_component(registry, e, velocity);
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


Entity EntityCreationSystem::create_boid(Ecs::Registry *registry, BoidSpawnEvent *event)
{
    Entity e = Ecs::create_entity(registry);

    Position pos = Position();
    pos.x = event->x;
    pos.y = event->y;

    Velocity vel = Velocity();
    vel.x = event->vel_x;
    vel.y = event->vel_y;

    Size size = Size();
    size.height = 114.0f * 0.25f;
    size.width  = 200.0f * 0.25f;

    Angle ang = Angle();
    ang.angle = 0.0f;

    Boid boid = Boid();

    SpriteComponent sprite = SpriteComponent();

    sprite.texture_id = SHIP1;
    

    Ecs::set_component(registry, e, pos);
    Ecs::set_component(registry, e, vel);
    Ecs::set_component(registry, e, size);
    Ecs::set_component(registry, e, ang);
    Ecs::set_component(registry, e, boid);
    Ecs::set_component(registry, e, sprite);

    return e;
}




Entity EntityCreationSystem::create_planet(Ecs::Registry *registry, PlanetSpawnEvent *event)
{
    Entity e = Ecs::create_entity(registry);

    Position pos = {event->x, event->y};
    Velocity vel = {event->vel_x, event->vel_y};

    Circle_size c_size = {event->radius};
    GravityAttractor grav = GravityAttractor();


    SpriteComponent sprite = {event->planet_type};








    Ecs::set_component(registry, e, pos);
    Ecs::set_component(registry, e, vel);
    Ecs::set_component(registry, e, c_size);
    Ecs::set_component(registry, e, grav);
    Ecs::set_component(registry, e, sprite);





    return e;
}