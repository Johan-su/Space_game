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


const float rotation_speed = 1.0f;

void PlayerSystem::update(Iter *it)
{
    const Group *group = Ecs::get_group<Player>(it->registry);
    if (group->size < 1)
    {
        return;
    }

    Entity active_camera = Application::get_first_active_camera(it->registry);


    Entity player = group->entity_list[0]; 


    Transform *transform = Ecs::get_component<Transform>(it->registry, player);
    Velocity *vel = Ecs::get_component<Velocity>(it->registry, player);

    float vel_x_target;
    float vel_y_target;


    float speed = 5000.0f;

    vel_x_target = 0.0f;
    vel_y_target = 0.0f;

    {
        Vector2f vel_direction = {0.0f, 0.0f};
        
        if (Real::IsKeyPressed(VK_KEY_W))
        {
            vel_direction.y += -1.0f;
        }

        if (Real::IsKeyPressed(VK_KEY_S))
        {
            vel_direction.y += 1.0f;
        }

        if (Real::IsKeyPressed(VK_KEY_A))
        {
            vel_direction.x += -1.0f;
        }

        if (Real::IsKeyPressed(VK_KEY_D))
        {
            vel_direction.x += 1.0f;
        }

        vel_direction.normalize();
        vel_x_target = speed * vel_direction.x;
        vel_y_target = speed * vel_direction.y;
    }


    MousePos mpos = Real::getMousePos();


    Transform *t_camera = Ecs::get_component<Transform>(it->registry, active_camera);
    CameraComponent *cc_camera = Ecs::get_component<CameraComponent>(it->registry, active_camera);

    //TODO(Johan): fix mouse tracking
    /*{
        float world_mx = Real::screen_to_world_x(t_camera, cc_camera, mpos.x);
        float world_my = Real::screen_to_world_y(t_camera, cc_camera, mpos.y);

        float dx = world_mx - transform->pos.x;
        float dy = world_my - transform->pos.y;

        float angle = atan2f(dy, dx);
        transform->rot = {cosf(angle), sinf(angle)};
    }*/


    vel->v.x = lerp(vel->v.x, vel_x_target, it->Ts * 6);
    vel->v.y = lerp(vel->v.y, vel_y_target, it->Ts * 6);

    
    if (Real::IsMousePressed(mouseCodes::VK_MOUSE_BUTTON_LEFT))
    {
        shoot_timer.time += it->Ts;
        if (shoot_timer.time >= shoot_timer.max_val)
        {
            shoot_timer.time -= shoot_timer.max_val;
            BulletSpawnEvent bse = {
                .transform = {
                    .pos = transform->pos + transform->rot * 400.0f,
                    .rot = transform->rot,
                    .scale = {50.0f, 50.0f, 0.0f},
                },
                .mesh = Real::get_mesh("square_mesh"),
                .material = Real::get_material("ship_material"),
                .vel = transform->rot * speed,
                .damage = 5.0f,
            };
            Ecs::push_event<BulletSpawnEvent>(it->registry, &bse);           
        }
    }

    
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_T))
    {
        transform->pos.z += 1.0f;
    }
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_G))
    {
        transform->pos.z -= 1.0f;
    }


    if (Real::IsKeyPressed(KeyCodes::VK_KEY_I))
    {
        transform->rot.x += rotation_speed * it->Ts;
    }
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_K))
    {
        transform->rot.x -= rotation_speed * it->Ts;
    }


    if (Real::IsKeyPressed(KeyCodes::VK_KEY_U))
    {
        transform->rot.y -= rotation_speed * it->Ts;
    }
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_O))
    {
        transform->rot.y += rotation_speed * it->Ts;
    }


    if (Real::IsKeyPressed(KeyCodes::VK_KEY_J))
    {
        transform->rot.z += rotation_speed * it->Ts;
    }
    if (Real::IsKeyPressed(KeyCodes::VK_KEY_L))
    {
        transform->rot.z -= rotation_speed * it->Ts;
    }



}




