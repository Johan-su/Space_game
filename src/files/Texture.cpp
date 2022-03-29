#include "Texture.hpp"
#include "assert.hpp"


#include <string.h>
#include <stdio.h>
void Texture::init(textures_data *td)
{
    memset(td->enum_to_texture, 0xFF, sizeof(td->enum_to_texture[0]) * MAX_TEXTURE_TYPES);
    memset(td->texture_list, 0, sizeof(td->texture_list[0]) * MAX_TEXTURE_TYPES);
    td->texture_count = 0;
}


void Texture::clean(textures_data *td)
{
    for(size_t i = 0; i < td->texture_count; ++i)
    {
        SDL_DestroyTexture(td->texture_list[i]);
    }
}


void Texture::load_texture(SDL_Renderer *renderer, textures_data *td, uint32_t enum_id, const char *path)
{
    

    SDL_Surface *surface = SDL_LoadBMP(path);
    if(!surface)
    {
        fprintf(stderr, "ERROR: failed to load surface : %s\n", SDL_GetError());
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture)
    {
        fprintf(stderr, "ERROR: failed to load texture : %s\n", SDL_GetError());
    }

    td->enum_to_texture[enum_id] = td->texture_count;
    td->texture_list[td->texture_count++] = texture;
}


SDL_Texture *Texture::get_texture(textures_data *td, uint32_t enum_id)
{
    assert(enum_id >= MAX_TEXTURE_TYPES, "enum_id cannot be greater than MAX_TEXTURE TYPES");
    return td->texture_list[td->enum_to_texture[enum_id]];
}


