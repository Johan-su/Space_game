#pragma once

#include <SDL.h>
#include <stdint.h>

#define MAX_TEXTURE_TYPES 512
#define MAX_SPRITE_TYPES 512



struct Tex_Sprite
{
    uint32_t x;
    uint32_t y;
    uint32_t w;
    uint32_t h;

    uint32_t texture_index;
};

struct textures_data
{
    uint32_t texture_count;
    uint32_t sprite_count;

    SDL_Texture *texture_list[MAX_TEXTURE_TYPES]; //TODO(johan) maybe change to linked list
    uint32_t enum_to_texture[MAX_SPRITE_TYPES];
    
    Tex_Sprite sprite_list[MAX_SPRITE_TYPES];
    uint32_t enum_to_sprite[MAX_SPRITE_TYPES];
};


namespace Texture_functions
{
    void init(textures_data *td);
    void clean(textures_data *td);

    void load_texture(SDL_Renderer *renderer, textures_data *td, uint32_t id, const char *path);

    void init_sprite(textures_data *td, uint32_t sprite_id, uint32_t texture_id, uint32_t x, uint32_t y, uint32_t w, uint32_t h);

    SDL_Texture *get_texture(textures_data *td, uint32_t id);

    Tex_Sprite *get_sprite(textures_data *td, uint32_t id);




}