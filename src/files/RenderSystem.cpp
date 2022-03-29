#include "RenderSystem.hpp"
#include "Components_Events.hpp"
#include "assert.hpp"

#include "ecs/ecs.hpp"

#include <SDL.h>
#include <stdint.h>

void RenderSystem::render(game_data *game)
{
    auto pos_view    = Registry_functions::get_view<Position, Size, Angle, Sprite>(game->registry);
    auto size_view   = Registry_functions::get_view<Size, Angle, Sprite, Position>(game->registry);

    auto angle_view  = Registry_functions::get_view<Angle, Sprite, Position, Size>(game->registry);
    auto sprite_view = Registry_functions::get_view<Sprite, Position, Size, Angle>(game->registry);

    for(size_t i = 0; i < pos_view.size; ++i)
    {
        dbg(printf("running in render for loop\n"));
        Tex_Sprite *sprite   = Texture::get_sprite(game->texture, sprite_view.comparray[i].texture_id);

        SDL_Rect srcrect     = SDL_Rect{(int)sprite->x, (int)sprite->y, (int)sprite->w, (int)sprite->h};
        SDL_FRect dstrect    = SDL_FRect{pos_view.comparray[i].x, pos_view.comparray[i].y, size_view.comparray[i].width, size_view.comparray[i].height};
        
        SDL_Texture *texture = Texture::get_texture(game->texture, sprite->texture_index);

        SDL_RenderCopyExF(game->renderer, texture, &srcrect, &dstrect, angle_view.comparray[i].angle, NULL, SDL_FLIP_NONE);
    }
}