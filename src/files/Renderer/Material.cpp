#include "Material.hpp"




void MaterialN::init(Material *material, Shader *shader, Texture *texture, shader_data_func *func)
{
    material->shader = shader;
    material->texture = texture;
    material->uniform_set_func = func;
}