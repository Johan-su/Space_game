#pragma once


#include "../int.hpp"


struct Texture
{
    I32 width;
    I32 height;
    I32 bpp;
    U32 texture_id;
};






namespace Real
{
    void init_texture(Texture *texture, const char *path);
    void clean_texture(Texture *texture);
    void bind(Texture *texture, U32 slot);
    void unbind(Texture *texture);

} // namespace Real
