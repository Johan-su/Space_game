#include "Texture.hpp"
#include "../assert.hpp"
#include "../datastructures/hashmap.hpp"
#include "../Memory_arena.hpp"

#include <stdio.h>


//static HashMap<SDL_Texture *> sdl_texture_map;


void Internal::init_textures()
{
    //HashMapN::init(&sdl_texture_map);
}


void Internal::clean_textures()
{

}



void Internal::init_texture(Texture *texture, const char *path, U64 abs_path_hash)
{
    /*
    assert(HashMapN::get_pointer(&sdl_texture_map, abs_path_hash) == nullptr, "Texture cannot already loaded");

    HashMapN::set(&sdl_texture_map, abs_path_hash, sdl_texture);


    //I32 width;
    //I32 height;
    //SDL_QueryTexture(sdl_texture, nullptr, nullptr, &width, &height);

    //texture->width = width;
    texture->height = height;
    //texture->internal_tex = sdl_texture;

    */
}


