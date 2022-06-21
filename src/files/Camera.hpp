#pragma once


#include "int.hpp"

struct Camera
{
    float world_x;
    float world_y;

    float world_scale_x;
    float world_scale_y;

    U16 screen_width;
    U16 screen_height;
    
};

namespace Camera_functions
{
    void init(Camera *camera, U16 screen_width, U16 screen_height);

    float screen_to_world_x(Camera *camera, I32 x);
    float screen_to_world_y(Camera *camera, I32 y);


    I32 world_to_screen_x(Camera *camera, float x);
    I32 world_to_screen_y(Camera *camera, float y);

    void set_camera_center(Camera *camera, float x, float y);

    void zoom(Camera *camera, I32 mx, I32 my, float scale);
}