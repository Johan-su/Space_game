#include "RenderSystem.hpp"
#include "../Components_Events.hpp"
#include "../assert.hpp"

#include "../ecs/ecs.hpp"

#include <SDL.h>
#include <stdint.h>

void RenderSystem::render(game_data *game)
{
    Camera *camera = game->camera;
    auto pos_view    = Registry_functions::get_view<Position, Size, Angle, Sprite>(game->registry);
    auto size_view   = Registry_functions::get_view<Size, Angle, Sprite, Position>(game->registry);

    auto angle_view  = Registry_functions::get_view<Angle, Sprite, Position, Size>(game->registry);
    auto sprite_view = Registry_functions::get_view<Sprite, Position, Size, Angle>(game->registry);

    for(size_t i = 0; i < pos_view.size; ++i)
    {
        //dbg(printf("running in render for loop\n"));
        Tex_Sprite *sprite   = Texture::get_sprite(game->texture, sprite_view.comparray[i].texture_id);
        SDL_Texture *texture = Texture::get_texture(game->texture, sprite->texture_index);

        SDL_Rect srcrect     = SDL_Rect{(int)sprite->x, (int)sprite->y, (int)sprite->w, (int)sprite->h};

        auto pos = pos_view.comparray[i];
        auto size = size_view.comparray[i];


        SDL_FRect dstrect    = SDL_FRect{(pos.x - (size.width / 2) - camera->world_x) * camera->world_scale_x,
                                         (pos.y - (size.height / 2) - camera->world_y) * camera->world_scale_y, 
                                         size.width * camera->world_scale_x, 
                                         size.height * camera->world_scale_y};
        

        SDL_RenderCopyExF(game->renderer, texture, &srcrect, &dstrect, angle_view.comparray[i].angle, NULL, SDL_FLIP_NONE);
    }
}


void RenderSystem::render_tracked_entity(game_data *game)
{
    if(game->trackedEntity != ENTITY_NULL)
    {
        auto pos = Registry_functions::get_component<Position>(game->registry, game->trackedEntity);
        auto size = Registry_functions::get_component<Size>(game->registry, game->trackedEntity);

        SDL_FRect rect = SDL_FRect{pos.x - (size.width / 2) - 1, pos.y - (size.height / 2) - 1, size.width + 1, size.height + 1};

        SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 0);
        SDL_RenderDrawRectF(game->renderer, &rect);
    }
}