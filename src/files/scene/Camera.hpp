#pragma once


#include "../int.hpp"

#include "component.hpp"

namespace Real
{
    void init_camera(Transform *camera_transform, CameraComponent *camera, bool active, U16 screen_width, U16 screen_height);


    float screen_to_world_x(Transform *camera_transform, CameraComponent *camera, I32 x);
    float screen_to_world_y(Transform *camera_transform, CameraComponent *camera, I32 y);


    I32 world_to_screen_x(Transform *camera_transform, CameraComponent *camera, float x);
    I32 world_to_screen_y(Transform *camera_transform, CameraComponent *camera, float y);

    void set_camera_center(Transform *camera_transform, CameraComponent *camera, float x, float y);

    void zoom(Transform *camera_transform, CameraComponent *camera, I32 mx, I32 my, float scale);
}