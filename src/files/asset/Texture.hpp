#pragma once

#include "../int.hpp"


struct Texture
{
    U32 width;
    U32 height;
    SDL_Texture *internal_tex;
};



namespace Internal
{
    void init_textures();
    void clean_textures();
    void init_texture(SDL_Renderer *renderer, Texture *texture, const char *path, U64 abs_path_hash);
} // namespace Internal



namespace TextureN
{
} // namespace TextureN