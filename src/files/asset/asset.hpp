#pragma once
#include "mesh.hpp"
#include "Texture.hpp"
#include "../core/core.hpp"



struct Shader;


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

    void load_mesh(const char *name, const char *path);
    void load_texture(const char *name, const char *path);
    void load_vertex_shader_src(const char *name, const char *path);
    void load_fragment_shader_src(const char *name, const char *path);
    void load_shader(const char *name, const char *vert_src, const char *frag_src);

    void init_sprite(const char *name, U32 x, U32 y, U32 w, U32 h, Texture *texture);


    Mesh *get_mesh(const char *name);
    Texture *get_texture(const char *name);
    Sprite *get_sprite(const char *name);

    const char *get_vertex_src(const char *name);
    const char *get_fragment_src(const char *name);

    Shader *get_shader(const char *name);



    U32 get_sprite_width(Sprite *sprite);
    U32 get_sprite_height(Sprite *sprite);


} // namespace Real
