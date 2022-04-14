#include "BoidSystem.hpp"

#include "../Game.hpp"

#include "../Components_Events.hpp"

static game_data *game;

void BoidSystem::init(game_data *game)
{
    ::game = game;
}


static Velocity avgVel(View<Velocity> vel_view)
{
    Velocity avg_vel = Velocity();

    avg_vel.x = 0.0f;
    avg_vel.y = 0.0f;


    for(size_t i = 0; i < vel_view.size; ++i)
    {
        Velocity vel = vel_view.comparray[i];

        avg_vel.x += vel.x;
        avg_vel.y += vel.y;
    }

    avg_vel.x /= vel_view.size;
    avg_vel.y /= vel_view.size;


    return avg_vel;
}


static Position avgPos(View<Position> pos_view)
{
    Position avg_pos = Position();

    avg_pos.x = 0.0f;
    avg_pos.y = 0.0f;


    for(size_t i = 0; i < pos_view.size; ++i)
    {
        Position pos = pos_view.comparray[i];

        avg_pos.x += pos.x;
        avg_pos.y += pos.y;
    }

    avg_pos.x /= pos_view.size;
    avg_pos.y /= pos_view.size;


    return avg_pos;
}


static float magnitude(Velocity vel)
{
    return sqrtf(vel.x * vel.x + vel.y * vel.y);
}


static float angle(Velocity vel)
{
    return atan2f(vel.y, vel.x);
}


static float lerp(float current, float target, float step)
{
    return current + step * (target - current);
}


static const float cohesion   = 0.4f;
static const float separation = 0.4f;
static const float alignment  = 0.3f;

void BoidSystem::update(float Ts)
{
    auto ang_view = Ecs::get_view<Angle, Boid>(game->registry);
    auto vel_view = Ecs::get_view<Velocity, Boid>(game->registry);
    auto pos_view = Ecs::get_view<Position, Boid>(game->registry);



    // coherence

    Position avg_pos = avgPos(pos_view);
    for(size_t i = 0; i < pos_view.size; ++i)
    {
        Entity e = vel_view.entity_list[i];

        Velocity *vel = Ecs::get_component<Velocity>(game->registry, e);
        Angle *ang = Ecs::get_component<Angle>(game->registry, e);
        Position pos = pos_view.comparray[i];

        float ang_to_avg = atan2(avg_pos.y - pos.y, avg_pos.x - pos.x);

        float mag = magnitude(*vel) + cohesion;

        vel->x = lerp(vel->x, mag * cosf(ang_to_avg), cohesion * Ts);
        vel->y = lerp(vel->y, mag * sinf(ang_to_avg), cohesion * Ts);
    }


    // separation
    const float minDistance = 160.0f;
    for(size_t i = 0; i < pos_view.size; ++i)
    {
        Entity curre = pos_view.entity_list[i];
        Position pos1 = pos_view.comparray[i];

        Velocity *vel = Ecs::get_component<Velocity>(game->registry, curre);
        Angle *ang = Ecs::get_component<Angle>(game->registry, curre);

        for(size_t j = 0; j < pos_view.size; ++j)
        {
            Entity e2 = pos_view.entity_list[j];
            if(e2 != curre)
            {
                Position pos2 = pos_view.comparray[j];
                float distance = hypotf(pos1.x - pos2.x, pos1.y - pos2.y);

                if(distance < minDistance)
                {

                    float mag = magnitude(*vel) + 5.0f *  minDistance / distance;
                    float ang_away = atan2(pos1.y - pos2.y, pos1.x - pos2.x);

                    vel->x = lerp(vel->x, mag * cosf(ang_away), separation * Ts);
                    vel->y = lerp(vel->y, mag * sinf(ang_away), separation * Ts);
                }
            }
        }
    }



    // alignment

    Velocity avg_vel = avgVel(vel_view);
    for(size_t i = 0; i < vel_view.size; ++i)
    {
        Entity e = vel_view.entity_list[i];

        Velocity *vel = Ecs::get_component<Velocity>(game->registry, e);
        //printf("vel: [%f, %f]\n", vel->x, vel->y);
        

        vel->x = lerp(vel->x, avg_vel.x, alignment * Ts);
        vel->y = lerp(vel->y, avg_vel.y, alignment * Ts);

    }


    // speed
    for(size_t i = 0; i < ang_view.size; ++i)
    {
        Entity e = vel_view.entity_list[i];
        Velocity *vel = Ecs::get_component<Velocity>(game->registry, e);
        Angle *ang = Ecs::get_component<Angle>(game->registry, e);

        float mag = magnitude(*vel) + 500.0f * Ts;


        ang->angle = atan2(vel->y, vel->x);

        vel->x = lerp(vel->x, mag * cosf(ang->angle), 1.5f);
        vel->y = lerp(vel->y, mag * sinf(ang->angle), 1.5f);
    }


    // keep in bounds
    const float maxDistance = 2000.0f;

    for(size_t i = 0; i < pos_view.size; ++i)
    {
        Entity e = pos_view.entity_list[i];
        Position *pos = Ecs::get_component<Position>(game->registry, e);

        if(pos->x > maxDistance)
        {
            pos->x -= 2 * maxDistance;
        }


        if(pos->x < -maxDistance)
        {
            pos->x += 2 * maxDistance;
        }

        
        if(pos->y > maxDistance)
        {
            pos->y -= 2 * maxDistance;
        }


        if(pos->y < -maxDistance)
        {
            pos->y += 2 * maxDistance;
        }

    }
}


