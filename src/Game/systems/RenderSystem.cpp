#include "RenderSystem.hpp"
#include "../Components_Events.hpp"


//#include <stdint.h>

inline static float RadToDeg(float angle)
{
    return angle * 57.2957786667f; // 180 / pi
}


void RenderSystem::render(Application_data *app, scene *scene)
{
    Ecs::Registry *registry = scene->registry;
    Camera *camera = &scene->camera;

    auto pos_view    = Ecs::get_view<Position, Size, Angle, SpriteComponent>(registry);
    auto size_view   = Ecs::get_view<Size, Angle, SpriteComponent, Position>(registry);

    auto angle_view  = Ecs::get_view<Angle, SpriteComponent, Position, Size>(registry);
    auto sprite_view = Ecs::get_view<SpriteComponent, Position, Size, Angle>(registry);

    for(size_t i = 0; i < pos_view.size; ++i)
    {
        //dbg(printf("running in render for loop\n"));
        Texture_Sprite *sprite = Application::get_sprite(app, sprite_view.comparray[i].texture_id);
        Texture *texture       = Application::get_texture(app, sprite->texture_index);

        Rect srcrect     = Rect{(int)sprite->x, (int)sprite->y, (int)sprite->w, (int)sprite->h};

        auto pos = pos_view.comparray[i];
        auto size = size_view.comparray[i];


        FRect dstrect = FRect();

        float worldunit_per_pixel_x = 1.0f / camera->world_scale_x;
        float worldunit_per_pixel_y = 1.0f / camera->world_scale_y;

        dstrect.x = (pos.x - (size.width / 2) - (camera->world_x - worldunit_per_pixel_x * (camera->screen_width / 2))) * camera->world_scale_x;
        dstrect.y = (pos.y - (size.height / 2) - (camera->world_y - worldunit_per_pixel_y * (camera->screen_height / 2))) * camera->world_scale_y;
        dstrect.w = size.width * camera->world_scale_x;
        dstrect.h = size.height * camera->world_scale_y;
        

        //SDL_RenderCopyExF(renderer, texture, &srcrect, &dstrect, RadToDeg(angle_view.comparray[i].angle) + 90.0f, NULL, SDL_FLIP_NONE);

        Application::RenderCopyExF(app, texture, &srcrect, &dstrect, RadToDeg(angle_view.comparray[i].angle) + 90.0f, NULL, FLIP_NONE);
    }
}






