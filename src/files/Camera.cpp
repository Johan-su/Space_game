#include "Camera.hpp"

#include <stdint.h>

void Camera_functions::init(Camera *camera, uint16_t screen_width, uint16_t screen_height)
{
    camera->world_x = 0.0f;
    camera->world_y = 0.0f;

    camera->screen_width = screen_width;
    camera->screen_height = screen_height;

    camera->world_scale_x = 1.0f;
    camera->world_scale_y = 1.0f;

}


void Camera_functions::clean(Camera *camera)
{
    return;
}


float Camera_functions::screen_to_world_x(Camera *camera, uint16_t x)
{
    float worldunit_per_pixel_x = 1.0f / camera->world_scale_x;

    float result = camera->world_x + worldunit_per_pixel_x * x;

    return result;
}


float Camera_functions::screen_to_world_y(Camera *camera, uint16_t y)
{
    float worldunit_per_pixel_y = 1.0f / camera->world_scale_y;

    float result = camera->world_y + worldunit_per_pixel_y * y;

    return result;
}


void Camera_functions::set_camera_center(Camera *camera, float x, float y)
{
    camera->world_x = x - (1.0f / camera->world_scale_x) * (camera->screen_width / 2);
    camera->world_y = y - (1.0f / camera->world_scale_y) * (camera->screen_height / 2);
}


void Camera_functions::zoom(Camera *camera, float scale)
{
    float cx = camera->world_x + (camera->screen_width / 2) * (1.0f / camera->world_scale_x);
    float cy = camera->world_y + (camera->screen_height / 2) * (1.0f / camera->world_scale_y);

    camera->world_scale_x *= scale;
    camera->world_scale_y *= scale;

    set_camera_center(camera, cx, cy);
}
