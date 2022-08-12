#include "Camera.hpp"


void Real::init_camera(Transform *camera_transform,
                       CameraComponent *camera,
                       bool active,
                       U16 screen_width,
                       U16 screen_height)
{

    *camera_transform = {
        .pos   = {0.0f, 0.0f},
        .rot   = {0.0f, 0.0f},
        .scale = {1.0f, 1.0f}
    };


    *camera = {
        .world_scale   = {.x = 1.0f, .y = 1.0f},
        .screen_width  = screen_width,
        .screen_height = screen_height,
        .active        = active
    };

}



float Real::screen_to_world_x(Transform *camera_transform, CameraComponent *camera, I32 x)
{
    return camera_transform->pos.x + (x / camera->world_scale.x);
}


float Real::screen_to_world_y(Transform *camera_transform, CameraComponent *camera, I32 y)
{
    return camera_transform->pos.y + (y / camera->world_scale.y);
}


I32 Real::world_to_screen_x(const Transform *camera_transform, const CameraComponent *camera, float x)
{
    return (I32)((x - camera_transform->pos.x) * camera->world_scale.x);
}


I32 Real::world_to_screen_y(const Transform *camera_transform, const CameraComponent *camera, float y)
{
    return (I32)((y - camera_transform->pos.y) * camera->world_scale.y);
}


void Real::set_camera_center(Transform *camera_transform, CameraComponent *camera, float x, float y)
{
    I32 screen_cx = world_to_screen_x(camera_transform, camera, x) - camera->screen_width / 2; 
    I32 screen_cy = world_to_screen_y(camera_transform, camera, y) - camera->screen_height / 2;


    camera_transform->pos.x = screen_to_world_x(camera_transform, camera, screen_cx);
    camera_transform->pos.y = screen_to_world_y(camera_transform, camera, screen_cy);
}



void Real::zoom(Transform *camera_transform, CameraComponent *camera, int mx, int my, float scale)
{
    float world_mx = screen_to_world_x(camera_transform, camera, mx);
    float world_my = screen_to_world_y(camera_transform, camera, my);

    camera->world_scale.x *= scale;
    camera->world_scale.y *= scale;

    float world_mx_after = screen_to_world_x(camera_transform, camera, mx);
    float world_my_after = screen_to_world_y(camera_transform, camera, my); 

    camera_transform->pos.x += world_mx - world_mx_after;
    camera_transform->pos.y += world_my - world_my_after;
}
