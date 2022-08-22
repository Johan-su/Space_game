#pragma once

#include "Shader.hpp"
#include "Texture.hpp"


typedef void (shader_data_func)(Shader *);

struct Material
{
    Shader *shader;
    Texture *texture;
    shader_data_func *uniform_set_func;
};



namespace MaterialN
{
    void init(Material *material, Shader *shader, Texture *texture, shader_data_func *func);
} // namespace Real
