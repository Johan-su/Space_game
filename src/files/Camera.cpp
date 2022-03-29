#include "Camera.hpp"

#include <stdint.h>

void Camera_functions::init(Camera *camera, uint16_t screen_width, uint16_t screen_height)
{
    camera->world_x = 0.0f;
    camera->world_y = 0.0f;

    camera->screen_width = screen_width;
    camera->screen_height = screen_height;

    camera->world_width = (float)screen_width;
    camera->world_height = (float)screen_height;

}


void Camera_functions::clean(Camera *camera)
{
    return;
}


float Camera_functions::screen_to_world_x(Camera *camera, uint16_t x)
{
    float worldunit_per_pixel = camera->world_width / camera->screen_width;

    float result = camera->world_x + worldunit_per_pixel * x;

    return result;
}


float Camera_functions::screen_to_world_y(Camera *camera, uint16_t y)
{
    float worldunit_per_pixel = camera->world_height / camera->screen_height;

    float result = camera->world_y + worldunit_per_pixel * y;

    return result;
}


void Camera_functions::set_camera_center(Camera *camera, float x, float y)
{
    camera->world_x = x - (camera->screen_width / 2);
    camera->world_y = y - (camera->screen_height / 2);
}