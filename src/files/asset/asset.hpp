#pragma once
#include "../Renderer/Mesh.hpp"
#include "../core/core.hpp"

#include "../Renderer/Texture.hpp"
#include "../Renderer/Material.hpp"



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

    void init_shader(const char *name, const char *vert_src, const char *frag_src);
    void init_sprite(const char *name, U32 x, U32 y, U32 w, U32 h, Texture *texture);
    void init_material(const char *name, Shader *shader, Texture *texture, shader_data_func *func);


    Mesh *get_mesh(const char *name);
    Texture *get_texture(const char *name);
    Sprite *get_sprite(const char *name);
    Material *get_material(const char *name);

    const char *get_vertex_src(const char *name);
    const char *get_fragment_src(const char *name);

    Shader *get_shader(const char *name);



    U32 get_sprite_width(Sprite *sprite);
    U32 get_sprite_height(Sprite *sprite);


} // namespace Real
