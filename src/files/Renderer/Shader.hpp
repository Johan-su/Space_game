#pragma once

#include "../int.hpp"
#include "../datastructures/hashmap.hpp"


#include "../math/math_types.hpp"


#define MAX_UNIFORM_TYPE_LENGTH 64
#define MAX_UNIFORM_NAME_LENGTH 128

enum class ShaderType
{
    Vertex,
    Fragment,
};


struct UniformElement
{
    ShaderType shader_type;
    I32 location;
    char type[MAX_UNIFORM_TYPE_LENGTH];
    char name[MAX_UNIFORM_NAME_LENGTH];
};


struct Shader
{
    U32 id;
    HashMap<UniformElement> uniform_map;
};

namespace ShaderN
{
    void init(Shader *shader, const char *vert_src, const char *frag_src);
} // namespace ShaderN


namespace Real
{

   void bind(Shader *shader);
   void unbind(Shader *shader);


    void set_uniform_I32(Shader *shader, I32 value, const char *name);
    void set_uniform_float(Shader *shader, float value, const char *name);
    void set_uniform_vec3f(Shader *shader, Vector3f value, const char *name);
    void set_uniform_vec4f(Shader *shader, Vector4f value, const char *name);
    void set_uniform_mat4(Shader *shader, Mat4 *mat, const char *name);

} // namespace Real


