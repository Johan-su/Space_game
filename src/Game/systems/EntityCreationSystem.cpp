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

    auto collision_comp = Collision();
    
    auto position_comp = Position();
    auto velocity_comp = Velocity();
    auto size_comp     = Size();

    auto angle_comp    = Angle();
    auto angleVel_comp = AnglularVelocity();
    
    auto sprite_comp   = Sprite();

    

    position_comp.x = x;
    position_comp.y = y;

    velocity_comp.x = 0.0f;
    velocity_comp.y = 0.0f;

    size_comp.width = width;
    size_comp.height = height;

    angle_comp.angle = 0.0f;
    angleVel_comp.angleV = 0.0f;

    sprite_comp.texture_id = ship_type;

    Ecs::set_component(registry, e, collision_comp);
    Ecs::set_component(registry, e, position_comp);
    Ecs::set_component(registry, e, velocity_comp);
    Ecs::set_component(registry, e, size_comp);
    Ecs::set_component(registry, e, angle_comp);
    Ecs::set_component(registry, e, angleVel_comp);
    Ecs::set_component(registry, e, sprite_comp);


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

    Position pos = {event->x, event->y};
    Velocity vel = {event->vel_x, event->vel_y};

    Circle_size c_size = {event->radius};
    GravityAttractor grav = GravityAttractor();


    Sprite sprite = {event->planet_type};








    Ecs::set_component(registry, e, pos);
    Ecs::set_component(registry, e, vel);
    Ecs::set_component(registry, e, c_size);
    Ecs::set_component(registry, e, grav);
    Ecs::set_component(registry, e, sprite);





    return e;
}