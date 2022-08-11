#pragma once

#include "int.hpp"
#include <SDL.h>

#define MAX_TEXTURE_TYPES 512
#define MAX_SPRITE_TYPES 512



struct Sprite
{
    U32 x;
    U32 y;
    U32 w;
    U32 h;

    U32 texture_index;
};

struct textures_data
{
    U32 texture_count;
    U32 sprite_count;

    SDL_Texture *texture_list[MAX_TEXTURE_TYPES]; //TODO(johan) maybe change to linked list
    U32 enum_to_texture[MAX_SPRITE_TYPES];
    
    Sprite sprite_list[MAX_SPRITE_TYPES];
    U32 enum_to_sprite[MAX_SPRITE_TYPES];
};


namespace Texture_functions
{
    void init(textures_data *td);
    void clean(textures_data *td);

    void load_texture(SDL_Renderer *renderer, textures_data *td, U32 id, const char *path);

    void init_sprite(textures_data *td, U32 sprite_id, U32 texture_id, U32 x, U32 y, U32 w, U32 h);

    SDL_Texture *get_texture(textures_data *td, U32 id);

    Sprite *get_sprite(textures_data *td, U32 id);


    U32 get_sprite_width(Sprite *sprite);
    U32 get_sprite_height(Sprite *sprite);


}