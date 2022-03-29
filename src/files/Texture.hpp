#pragma once

#include <SDL.h>
#include <stdint.h>

#define MAX_TEXTURE_TYPES 512

enum Texture_id_map
{
    SHIP1, SHIP2
};

struct textures_data
{
    SDL_Texture *texture_list[MAX_TEXTURE_TYPES]; //TODO(johan) maybe change to linked list
    
    uint32_t enum_to_texture[MAX_TEXTURE_TYPES];

    size_t texture_count;
};


namespace Texture
{
    void init(textures_data *td);
    void clean(textures_data *td);

    void load_texture(SDL_Renderer *renderer, textures_data *td, uint32_t enum_id, const char *path);
    SDL_Texture *get_texture(textures_data *td, uint32_t enum_id);




}