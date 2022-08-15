#include "Texture.hpp"
#include "../assert.hpp"
#include "../datastructures/hashmap.hpp"
#include "../Memory_arena.hpp"

#include <stdio.h>


static HashMap<SDL_Texture *> sdl_texture_map;


void Internal::init_textures()
{
    HashMapN::init(&sdl_texture_map);
}


void Internal::clean_textures()
{
    for (int i = 0; i < 8192; ++i)
    {
        SDL_Texture *key = sdl_texture_map.values[i];
        if (key != nullptr)
        {
            SDL_DestroyTexture(key);
        }
    }
}



void Internal::init_texture(SDL_Renderer *renderer, Texture *texture, const char *path, U64 abs_path_hash)
{
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (surface)
    {
        printf("NOTE: Loaded texture file from %s\n", path);
    } 
    else
    {
        fprintf(stderr, "ERROR: failed to load surface : %s\n", SDL_GetError());
        exit(1);
    }
    SDL_Texture *sdl_texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!sdl_texture)
    {
        fprintf(stderr, "ERROR: failed to load texture : %s\n", SDL_GetError());
        exit(1);
    }


    assert(HashMapN::get_pointer(&sdl_texture_map, abs_path_hash) == nullptr, "Texture cannot already loaded");

    HashMapN::set(&sdl_texture_map, abs_path_hash, sdl_texture);


    I32 width;
    I32 height;
    SDL_QueryTexture(sdl_texture, nullptr, nullptr, &width, &height);

    texture->width = width;
    texture->height = height;
    texture->internal_tex = sdl_texture;
}


