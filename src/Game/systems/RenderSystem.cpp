#include "RenderSystem.hpp"
#include "../Components_Events.hpp"
#include "../../assert.hpp"

#include "../../ecs/ecs.hpp"



#include <SDL.h>
#include <stdint.h>

static float RadToDeg(float angle)
{
    return angle * 57.2957786667; // 180 / pi
}

void RenderSystem::render(Ecs::Registry *registry, SDL_Renderer *renderer, Camera *camera, textures_data *texture_data)
{
    auto pos_view    = Ecs::get_view<Position, Size, Angle, Sprite>(registry);
    auto size_view   = Ecs::get_view<Size, Angle, Sprite, Position>(registry);

    auto angle_view  = Ecs::get_view<Angle, Sprite, Position, Size>(registry);
    auto sprite_view = Ecs::get_view<Sprite, Position, Size, Angle>(registry);

    for(size_t i = 0; i < pos_view.size; ++i)
    {
        //dbg(printf("running in render for loop\n"));
        Tex_Sprite *sprite   = Texture::get_sprite(texture_data, sprite_view.comparray[i].texture_id);
        SDL_Texture *texture = Texture::get_texture(texture_data, sprite->texture_index);

        SDL_Rect srcrect     = SDL_Rect{(int)sprite->x, (int)sprite->y, (int)sprite->w, (int)sprite->h};

        auto pos = pos_view.comparray[i];
        auto size = size_view.comparray[i];


        SDL_FRect dstrect = SDL_FRect();

        float worldunit_per_pixel_x = 1.0f / camera->world_scale_x;
        float worldunit_per_pixel_y = 1.0f / camera->world_scale_y;

        dstrect.x = (pos.x - (size.width / 2) - (camera->world_x - worldunit_per_pixel_x * (camera->screen_width / 2))) * camera->world_scale_x;
        dstrect.y = (pos.y - (size.height / 2) - (camera->world_y - worldunit_per_pixel_y * (camera->screen_height / 2))) * camera->world_scale_y;
        dstrect.w = size.width * camera->world_scale_x;
        dstrect.h = size.height * camera->world_scale_y;
        

        SDL_RenderCopyExF(renderer, texture, &srcrect, &dstrect, RadToDeg(angle_view.comparray[i].angle) + 90.0f, NULL, SDL_FLIP_NONE);
    }
}






