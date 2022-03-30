#pragma once


#include <stdint.h>

struct Camera
{
    float world_x;
    float world_y;

    float world_scale_x;
    float world_scale_y;

    uint16_t screen_width;
    uint16_t screen_height;
    
};

namespace Camera_functions
{
    void init(Camera *camera, uint16_t screen_width, uint16_t screen_height);
    void clean(Camera *camera);

    float screen_to_world_x(Camera *camera, uint16_t x);
    float screen_to_world_y(Camera *camera, uint16_t y);

    void set_camera_center(Camera *camera, float x, float y);

    void zoom(Camera *camera, float scale);
}