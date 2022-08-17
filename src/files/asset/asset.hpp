#pragma once
#include "mesh.hpp"
#include "Texture.hpp"
#include "../core/core.hpp"




struct Sprite
{
    U32 x;
    U32 y;
    U32 width;
    U32 height;

    Texture *texture;
};





namespace Internal
{
    void init_asset(engine_data *engine);
    void clean_asset();
} // namespace Internal



namespace Real
{

    void load_mesh(const char *path, const char *name);
    void load_texture(const char *path, const char *name);
    void load_vertex_shader_src(const char *path, const char *name); //TODO(Johan) fix loading shaders/ loading stuff that comes from multiple files
    void load_fragment_shader_src(const char *path, const char *name);

    void init_sprite(const char *name, U32 x, U32 y, U32 w, U32 h, Texture *texture);


    Mesh *get_mesh(const char *name);
    Texture *get_texture(const char *name);
    Sprite *get_sprite(const char *name);



    U32 get_sprite_width(Sprite *sprite);
    U32 get_sprite_height(Sprite *sprite);


} // namespace Real
