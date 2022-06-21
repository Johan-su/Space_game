#include "RenderSystem.hpp"
#include "../Components_Events.hpp"


static inline float RadToDeg(float angle)
{
    return angle * 57.2957786667f; // 180 / pi
}


void RenderSystem::render(Application_data *app, scene *scene)
{
    Application::clear_view_buffer();
    Ecs::Registry *registry = scene->registry;
    Camera *camera = &scene->camera;

    View<Position> *pos_view           = Ecs::get_view<Position, SizeComponent, Angle, SpriteComponent>(registry);
    View<SizeComponent> *size_view     = Ecs::get_view<SizeComponent, Angle, SpriteComponent, Position>(registry);

    View<Angle> *angle_view            = Ecs::get_view<Angle, SpriteComponent, Position, SizeComponent>(registry);
    View<SpriteComponent> *sprite_view = Ecs::get_view<SpriteComponent, Position, SizeComponent, Angle>(registry);

    for(Usize i = 0; i < pos_view->size; ++i)
    {
        //dbg(printf("running in render for loop\n"));
        Texture_Sprite *sprite = Application::get_sprite(app, sprite_view->comparray[i].texture_id);
        Texture *texture = Application::get_texture(app, sprite->texture_index);

        Rect srcrect = Rect{(int)sprite->x, (int)sprite->y, (int)sprite->w, (int)sprite->h};

        Position pos = pos_view->comparray[i];
        SizeComponent size = size_view->comparray[i];


        FRect dstrect = FRect();


       // dstrect.x = (pos.x - (size.width / 2) - (camera->world_x - worldunit_per_pixel_x * (camera->screen_width / 2))) * camera->world_scale_x;
       // dstrect.y = (pos.y - (size.height / 2) - (camera->world_y - worldunit_per_pixel_y * (camera->screen_height / 2))) * camera->world_scale_y;


        dstrect.x = Camera_functions::world_to_screen_x(camera, pos.x);
        dstrect.y = Camera_functions::world_to_screen_y(camera, pos.y);

        dstrect.w = size.width * camera->world_scale_x;
        dstrect.h = size.height * camera->world_scale_y;

        // printf("camerapos [x = %f, y = %f, scale_x = %f, scale_y = %f] ", camera->world_x, camera->world_y, camera->world_scale_x, camera->world_scale_y);
        // printf("renderpos [x = %f, y = %f, w = %f, h = %f]\n", dstrect.x, dstrect.y, dstrect.w, dstrect.h);

        Application::RenderCopyExF(app, texture, &srcrect, &dstrect, RadToDeg(angle_view->comparray[i].angle) + 90.0f, NULL, FLIP_NONE);
    }
}






