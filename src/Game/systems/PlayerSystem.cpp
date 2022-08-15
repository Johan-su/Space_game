#include "PlayerSystem.hpp"
#include "../Components_Events.hpp"
#include <math.h>


struct Timer
{
    float max_val;
    float time;
};




static float lerp(float current, float target, float step)
{
    return current + step * (target - current);
}



static Timer shoot_timer = {
    .max_val = 0.4f,
    .time = 0.0f,
};


void PlayerSystem::update(Iter *it)
{
    const Group *group = Ecs::get_group<Player>(it->registry);
    if (group->size < 1)
    {
        return;
    }

    Entity active_camera = Application::get_first_active_camera(it->registry);


    Entity player = group->entity_list[0]; 


    Transform *transform        = Ecs::get_component<Transform>(it->registry, player);
    Velocity *vel               = Ecs::get_component<Velocity>(it->registry, player);

    float vel_x_target;
    float vel_y_target;


    float speed = 5000.0f;

    vel_x_target = 0.0f;
    vel_y_target = 0.0f;

    Vector2f vel_direction = {0.0f, 0.0f};
    /*
    if (Real::IsKeyPressed(VK_LSHIFT))
    {
        speed = 5000.0f;
    }
    */
    if (Real::IsKeyPressed(VK_w))
    {
        vel_direction.y += -1.0f;
    }

    if (Real::IsKeyPressed(VK_s))
    {
        vel_direction.y += 1.0f;
    }

    if (Real::IsKeyPressed(VK_a))
    {
        vel_direction.x += -1.0f;
    }

    if (Real::IsKeyPressed(VK_d))
    {
        vel_direction.x += 1.0f;
    }

    vel_direction.normalize();
    vel_x_target = speed * vel_direction.x;
    vel_y_target = speed * vel_direction.y;


    vec2i mpos = Real::getMousePos();


    Transform *t_camera = Ecs::get_component<Transform>(it->registry, active_camera);
    CameraComponent *cc_camera = Ecs::get_component<CameraComponent>(it->registry, active_camera);

    float world_mx = Real::screen_to_world_x(t_camera, cc_camera, mpos.x);
    float world_my = Real::screen_to_world_y(t_camera, cc_camera, mpos.y);

    float dx = world_mx - transform->pos.x;
    float dy = world_my - transform->pos.y;

    float angle = atan2f(dy, dx);
    transform->rot = {cosf(angle), sinf(angle)};


    vel->v.x = lerp(vel->v.x, vel_x_target, it->Ts * 6);
    vel->v.y = lerp(vel->v.y, vel_y_target, it->Ts * 6);

    
    if (Real::IsMousePressed(mouseCodes::MOUSE_BUTTON_LEFT))
    {
        shoot_timer.time += it->Ts;
        if (shoot_timer.time >= shoot_timer.max_val)
        {
            shoot_timer.time -= shoot_timer.max_val;
            BulletSpawnEvent event = {
                .pos = {transform->pos + transform->rot * 200.0f},
                .rot = {transform->rot},
                .vel = {
                    .x = transform->rot.x * speed,
                    .y = transform->rot.y * speed,
                },
                .bullet_sprite = Real::get_sprite("ship1_sprite"),
            };
            Ecs::push_event<BulletSpawnEvent>(it->registry, &event);           
        }
    }
}




