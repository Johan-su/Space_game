#include "BoidSystem.hpp"
#include "../Components_Events.hpp"

#include <math.h>

static Velocity avgVel(View<Position> *pos_view, View<Velocity> *vel_view, float visual_range, Position *e_pos,  Velocity *e_vel)
{
    Velocity avg_vel = Velocity();

    avg_vel.x = 0.0f;
    avg_vel.y = 0.0f;

    size_t neighbors = 0;

    for(size_t i = 0; i < vel_view->size; ++i)
    {
        Position pos = pos_view->comparray[i];
        Velocity vel = vel_view->comparray[i];

        float x_diff = e_pos->x - pos.x;
        float y_diff = e_pos->y - pos.y;

        if(x_diff * x_diff + y_diff * y_diff < visual_range * visual_range)
        {
            avg_vel.x += vel.x;
            avg_vel.y += vel.y;
            ++neighbors;
        }
    }

    avg_vel.x /= neighbors;
    avg_vel.y /= neighbors;


    return avg_vel;
}


static Position avgPos(View<Position> *pos_view, float visual_range, Position *e_pos)
{
    Position avg_pos = Position();

    avg_pos.x = 0.0f;
    avg_pos.y = 0.0f;

    size_t neighbors = 0;

    for(size_t i = 0; i < pos_view->size; ++i)
    {
        Position pos = pos_view->comparray[i];

        float x_diff = e_pos->x - pos.x;
        float y_diff = e_pos->y - pos.y;

        if(x_diff * x_diff + y_diff * y_diff < visual_range * visual_range)
        {
            avg_pos.x += pos.x;
            avg_pos.y += pos.y;
            ++neighbors;
        }
    }

    avg_pos.x /= neighbors;
    avg_pos.y /= neighbors;


    return avg_pos;
}



static const float visualrange = 300.0f;


static const float separation = 9000.0f;
static const float alignment  = 12.0f;

static const float cohesion   = 3.0f;

static void goToCenter(Ecs::Registry *registry, View<Position> *pos_view, Entity e, float Ts)
{

    Position *pos = Ecs::get_component<Position>(registry, e);
    Velocity *vel = Ecs::get_component<Velocity>(registry, e);

    Position avg_pos = avgPos(pos_view, visualrange, pos);


    vel->x += (avg_pos.x - pos->x) * (cohesion * Ts);
    vel->y += (avg_pos.y - pos->y) * (cohesion * Ts);
}


static const float minDistance = 50.0f;

static void avoidOthers(Ecs::Registry *registry, View<Position> *pos_view, Entity e, float Ts)
{
    Position *pos = Ecs::get_component<Position>(registry, e);
    Velocity *vel = Ecs::get_component<Velocity>(registry, e);

    for(size_t i = 0; i < pos_view->size; ++i)
    {
        Entity e2 = pos_view->entity_list[i];
        if(e2 != e)
        {
            Position pos2 = pos_view->comparray[i];
            float distance2 = (pos->x - pos2.x) * (pos->x - pos2.x) + (pos->y - pos2.y) * (pos->y - pos2.y);

            if(distance2 < minDistance * minDistance)
            {
                vel->x += (pos->x - pos2.x) * (separation * Ts);
                vel->y += (pos->y - pos2.y) * (separation * Ts);
            }
        }
    }
}


static void matchVelocity(Ecs::Registry *registry, View<Position> *pos_view, View<Velocity> *vel_view, Entity e, float Ts)
{
    Position *pos = Ecs::get_component<Position>(registry, e);
    Velocity *vel = Ecs::get_component<Velocity>(registry, e);

    Velocity avg_vel = avgVel(pos_view, vel_view, visualrange, pos, vel);
        

    vel->x += (avg_vel.x - vel->x) * (alignment * Ts);
    vel->y += (avg_vel.y - vel->y) * (alignment * Ts);
}


static float speed_limit = 40000.0f;

static void limitSpeed(Ecs::Registry *registry, Entity e, float Ts)
{
    Velocity *vel = Ecs::get_component<Velocity>(registry, e);

    float speed = hypotf(vel->x, vel->y);

    if(speed > speed_limit)
    {
        vel->x = (vel->x / speed) * speed_limit;
        vel->y = (vel->y / speed) * speed_limit;
    }
}

static float spawn_timer = 0.0f;

static float print_timer = 0.0f;

void BoidSystem::update(Ecs::Registry *registry, float Ts)
{
    Application::clear_view_buffer();
    auto vel_view = Ecs::get_view<Velocity, Boid>(registry);
    auto pos_view = Ecs::get_view<Position, Boid>(registry);


    const float maxDistance = 5000.0f;

    print_timer += Ts;
    while(print_timer > 1.0f)
    {
        print_timer -= 1.0f;
        printf("entity count: %llu\n", pos_view->size);
    }

    for(size_t i = 0; i < pos_view->size; ++i)
    {


        Entity e = pos_view->entity_list[i];
        // coherence
        //goToCenter(registry, pos_view, e, Ts);
        // separation
        //avoidOthers(registry, pos_view, e, Ts);
        // alignment
        //matchVelocity(registry, pos_view, vel_view, e, Ts);

        // keep in bounds
        Position *pos = Ecs::get_component<Position>(registry, e);
        Velocity *vel = Ecs::get_component<Velocity>(registry, e);

        if(pos->x > maxDistance)
        {
            vel->x *= (-1.0f);
            pos->x = maxDistance - 50.0f;
        }


        if(pos->x < -maxDistance)
        {
            Ecs::destroy_entity(registry, e);
            continue;
        }

        
        if(pos->y > maxDistance)
        {
            vel->y *= (-1.0f);
            pos->y = maxDistance - 50.0f;
        }

        
        if(pos->y < -maxDistance)
        {
            Ecs::destroy_entity(registry, e);
            continue;
        }
        
        // set angle to velocity vector

        Angle *ang    = Ecs::get_component<Angle>(registry, e);
        ang->angle = atan2(vel->y, vel->x);


        //limit speed
        //limitSpeed(registry, e, Ts);
    }

    spawn_timer += Ts;
    while(spawn_timer > 0.00001f)
    {
        spawn_timer -= 0.00001f;
        BoidSpawnEvent bse = BoidSpawnEvent();

        bse.y = 1500.0f * (float)(rand() - rand()) / (float)RAND_MAX;

        float speed = 5000.0f;
        float angle = (((float)rand() / (float)RAND_MAX) - 0.5f) * 2 * 3.141592741f;
        bse.vel_x = speed * cos(angle);
        bse.vel_y = speed * sin(angle);
        


        Ecs::broadcast_event<Entity>(registry, &bse);
    }
}


