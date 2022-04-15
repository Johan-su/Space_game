#include "BoidSystem.hpp"

#include "../Game.hpp"

#include "../Components_Events.hpp"

static game_data *game;

void BoidSystem::init(game_data *game)
{
    ::game = game;
}


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

static void goToCenter(View<Position> *pos_view, Entity e, float Ts)
{

    Position *pos = Ecs::get_component<Position>(game->registry, e);
    Velocity *vel = Ecs::get_component<Velocity>(game->registry, e);

    Position avg_pos = avgPos(pos_view, visualrange, pos);


    vel->x += (avg_pos.x - pos->x) * (cohesion * Ts);
    vel->y += (avg_pos.y - pos->y) * (cohesion * Ts);
}


static const float minDistance = 50.0f;

static void avoidOthers(View<Position> *pos_view, Entity e, float Ts)
{
    Position *pos = Ecs::get_component<Position>(game->registry, e);
    Velocity *vel = Ecs::get_component<Velocity>(game->registry, e);

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


static void matchVelocity(View<Position> *pos_view, View<Velocity> *vel_view, Entity e, float Ts)
{
    Position *pos = Ecs::get_component<Position>(game->registry, e);
    Velocity *vel = Ecs::get_component<Velocity>(game->registry, e);

    Velocity avg_vel = avgVel(pos_view, vel_view, visualrange, pos, vel);
        

    vel->x += (avg_vel.x - vel->x) * (alignment * Ts);
    vel->y += (avg_vel.y - vel->y) * (alignment * Ts);
}


static float speed_limit = 4000000.0f;

static void limitSpeed(Entity e, float Ts)
{
    Velocity *vel = Ecs::get_component<Velocity>(game->registry, e);

    float speed = hypotf(vel->x, vel->y);

    if(speed > speed_limit)
    {
        vel->x = (vel->x / speed) * speed_limit;
        vel->y = (vel->y / speed) * speed_limit;
    }
}


void BoidSystem::update(float Ts)
{
    auto vel_view = Ecs::get_view<Velocity, Boid>(game->registry);
    auto pos_view = Ecs::get_view<Position, Boid>(game->registry);


    const float maxDistance = 5000.0f;

    for(size_t i = 0; i < pos_view.size; ++i)
    {
        Entity e = pos_view.entity_list[i];
        // coherence
        goToCenter(&pos_view, e, Ts);
        // separation
        avoidOthers(&pos_view, e, Ts);
        // alignment
        matchVelocity(&pos_view, &vel_view, e, Ts);

        // keep in bounds
        Position *pos = Ecs::get_component<Position>(game->registry, e);
        Velocity *vel = Ecs::get_component<Velocity>(game->registry, e);

        if(pos->x > maxDistance)
        {
            vel->x *= (-1.0f);
            pos->x -= 50.0f;
        }


        if(pos->x < -maxDistance)
        {
            vel->x *= (-1.0f);
            pos->x += 50.0f;
        }

        
        if(pos->y > maxDistance)
        {
            vel->y *= (-1.0f);
            pos->y -= 50.0f;
        }


        if(pos->y < -maxDistance)
        {
            vel->y *= (-1.0f);
            pos->y += 50.0f;
        }

        // set angle to velocity vector

        Angle *ang    = Ecs::get_component<Angle>(game->registry, e);

        ang->angle = atan2(vel->y, vel->x);


        //limit speed
        limitSpeed(e, Ts);
    }

}


