#include "Camera.hpp"


void Real::init(Camera *camera, U16 screen_width, U16 screen_height)
{
    camera->world_x = 0.0f;
    camera->world_y = 0.0f;

    camera->screen_width  = screen_width;
    camera->screen_height = screen_height;

    camera->world_scale_x = 1.0f;
    camera->world_scale_y = 1.0f;

}


float Real::screen_to_world_x(Camera *camera, I32 x)
{
    return camera->world_x + (x / camera->world_scale_x);
}


float Real::screen_to_world_y(Camera *camera, I32 y)
{
    return camera->world_y + (y / camera->world_scale_y);
}


I32 Real::world_to_screen_x(Camera *camera, float x)
{
    return (I32)((x - camera->world_x) * camera->world_scale_x);
}


I32 Real::world_to_screen_y(Camera *camera, float y)
{
    return (I32)((y - camera->world_y) * camera->world_scale_y);
}


void Real::set_camera_center(Camera *camera, float x, float y)
{
    I32 screen_cx = world_to_screen_x(camera, x) - camera->screen_width / 2; 
    I32 screen_cy = world_to_screen_y(camera, y) - camera->screen_height / 2;


    camera->world_x = screen_to_world_x(camera, screen_cx);
    camera->world_y = screen_to_world_y(camera, screen_cy);
}



void Real::zoom(Camera *camera, int mx, int my, float scale)
{
    float world_mx = screen_to_world_x(camera, mx);
    float world_my = screen_to_world_y(camera, my);

    camera->world_scale_x *= scale;
    camera->world_scale_y *= scale;

    float world_mx_after = screen_to_world_x(camera, mx);
    float world_my_after = screen_to_world_y(camera, my); 

    camera->world_x += world_mx - world_mx_after;
    camera->world_y += world_my - world_my_after;
}
