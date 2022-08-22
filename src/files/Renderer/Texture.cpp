#include "Texture.hpp"


#include "../core/core.hpp"

#include "../core/loadgl/load_gl.hpp"

#include <stb_image.h>




void Real::init_texture(Texture *texture, const char *path) //TODO(Johan) maybe redefine stb_alloc, stb_free to use memory arenas
{
    stbi_set_flip_vertically_on_load(1);

    U8 *texture_buffer = stbi_load(path, &texture->width, &texture->height, &texture->bpp, 4);


    glGenTextures(1, &texture->texture_id);
    glBindTexture(GL_TEXTURE_2D, texture->texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_buffer);
    glBindTexture(GL_TEXTURE_2D, 0);



    if (texture_buffer != nullptr)
        stbi_image_free(texture_buffer);
}


void Real::clean_texture(Texture *texture)
{
    glDeleteTextures(1, &texture->texture_id);
}


void Real::bind(Texture *texture, U32 slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture->texture_id);
}


void Real::unbind(Texture *texture)
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

