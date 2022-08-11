#include "CameraController.hpp"


static const float MOUSE_ZOOM_SCALE_SPEED = 1.3f;


static vec2i anchor;
static bool anchor_check = false;

void CameraController::update(Iter *iter)
{
    Entity active_camera = Application::get_first_active_camera(iter->registry);

    if (active_camera == ENTITY_NULL)
    {
        return;
    }

    CameraComponent *camera_comp = Ecs::get_component<CameraComponent>(iter->registry, active_camera);
    Transform *camera_transform  = Ecs::get_component<Transform>(iter->registry, active_camera);

    vec2i mouse_pos = Real::getMousePos();

    printf("Mouse pos [%.2f, %.2f]\n", 
        Real::screen_to_world_x(camera_transform, camera_comp, mouse_pos.x), 
        Real::screen_to_world_y(camera_transform, camera_comp, mouse_pos.y)); 

    // printf("camerapos [x = %f, y = %f, scale_x = %f, scale_y = %f]\n", scene->camera.world_x, scene->camera.world_y, scene->camera.world_scale_x, scene->camera.world_scale_y);
    switch (Real::IsMouseScroll())
    {
        case MOUSE_SCROLL_NONE:
        {
            // left blank
        } break;

        case MOUSE_SCROLL_UP: //TODO(Johan) add zoom clamp to avoid floating point rounding errors.
        {
            Real::zoom(camera_transform, camera_comp, mouse_pos.x, mouse_pos.y, MOUSE_ZOOM_SCALE_SPEED);

        } break;

        case MOUSE_SCROLL_DOWN:
        {
            Real::zoom(camera_transform, camera_comp, mouse_pos.x, mouse_pos.y, 1.0f / MOUSE_ZOOM_SCALE_SPEED);
        } break;
    }

    if (Real::IsMousePressed(MOUSE_BUTTON_MIDDLE))
    {
        //TODO(Johan) try to remove anchor_check.
        if (!anchor_check)
        {
            anchor = Real::getMousePos();
            anchor_check = true;
        }

        vec2i mpos = Real::getMousePos();
        
        camera_transform->pos.x -= (mpos.x - anchor.x) / camera_comp->world_scale.x;
        camera_transform->pos.y -= (mpos.y - anchor.y) / camera_comp->world_scale.y;
        anchor = Real::getMousePos();


    }
    else
    {
        anchor_check = false;
    }
}