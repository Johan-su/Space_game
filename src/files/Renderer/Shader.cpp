#include "Shader.hpp"


#include "../core/loadgl/load_gl.hpp"


#include <stdio.h>
#include <stdlib.h>

static U32 compile_shader(U32 type, const char *src)
{
    U32 shader_id = glCreateShader(type);

    glShaderSource(shader_id, 1, &src, nullptr);
    glCompileShader(shader_id);

    I32 compiled;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compiled);

    if (compiled == GL_FALSE)
    {
        I32 log_length = 0;
        char message[2048];

        glGetShaderInfoLog(shader_id, 2048, &log_length, message);

        const char *type_s;

        switch (type)
        {
            case GL_VERTEX_SHADER:
            {
                type_s = "Vertex";
            } break;


            case GL_FRAGMENT_SHADER:
            {
                type_s = "Fragment";
            } break;      


            default:
            {
                type_s = "Unknown";
            } break;
        }

        fprintf(stderr, "ERROR: Failed to compile %s shader: %s\n", type_s, message);
        glDeleteShader(shader_id);
        exit(1);
    }
    return shader_id;
}


static bool is_whitespace(const char val)
{
    switch (val)
    {
        case '\r': return true;
        case '\n': return true;
        case '\t': return true;
        case '\b': return true;
        case ' ':  return true;

        default: return false;        
    }
}


static void move_past_whitespace(const char *src, U32 *index)
{
    while (is_whitespace(*(src + *index)))
    {
        *index += 1;
    }
}


static bool is_word(const char *src, const char *word)
{

    while (*word != '\0')
    {
        if (*src != *word)
        {
            return false;
        }
        src += 1;
        word += 1;
    }
    return true;
}


static void parse_and_add_uniforms(Shader *shader, const char *src, ShaderType shader_type)
{
    for (U32 index = 0;*(src + index) != '\0'; ++index)
    {
        if (is_word(src + index, "uniform"))
        {
            UniformElement element = {
                .shader_type = shader_type,
            };

            index += strlen("uniform");

            move_past_whitespace(src, &index);

            for (U32 i = 0; !is_whitespace(*(src + index)); ++i)
            {
                element.type[i] = *(src + index);
                index += 1;
            }

            move_past_whitespace(src, &index);

            for (U32 i = 0; !is_whitespace(*(src + index)) && !is_word(src + index, "[") && !is_word(src + index, ";"); ++i)
            {
                element.name[i] = *(src + index);
                index += 1;
            }

            element.location =  glGetUniformLocation(shader->id, element.name);
            
            HashMapN::set(&shader->uniform_map, HashMapN::hash_string(element.name), element);
        }
    }
}



void ShaderN::init(Shader *shader, const char *vert_src, const char *frag_src)
{
    HashMapN::init(&shader->uniform_map);


    shader->id = glCreateProgram();

    U32 vs = compile_shader(GL_VERTEX_SHADER, vert_src);
    U32 fs = compile_shader(GL_FRAGMENT_SHADER, frag_src);


    glAttachShader(shader->id, vs);
    glAttachShader(shader->id, fs);


    glLinkProgram(shader->id);
    glValidateProgram(shader->id);


    glDetachShader(shader->id, vs);
    glDetachShader(shader->id, fs);

    glDeleteShader(vs);
    glDeleteShader(fs);


    parse_and_add_uniforms(shader, vert_src, ShaderType::Vertex);
    parse_and_add_uniforms(shader, frag_src, ShaderType::Fragment);
}




void Real::bind(Shader *shader)
{
    glUseProgram(shader->id);
}


void Real::unbind(Shader *shader)
{
    glUseProgram(0);
}




void Real::set_uniform_I32(Shader *shader, I32 value, const char *name)
{
    U64 hash = HashMapN::hash_string(name);
    UniformElement *element = HashMapN::get_pointer(&shader->uniform_map, hash);
    if (element == nullptr)
    {
        fprintf(stderr, "WARNING: could not find uniform %s\n", name);
        return;
    }
    
    bind(shader);
    glUniform1i(element->location, value);
}


void Real::set_uniform_float(Shader *shader, float value, const char *name)
{
    U64 hash = HashMapN::hash_string(name);
    UniformElement *element = HashMapN::get_pointer(&shader->uniform_map, hash);
    if (element == nullptr)
    {
        fprintf(stderr, "WARNING: could not find uniform %s\n", name);
        return;
    }

    bind(shader);
    glUniform1f(element->location, value);
}


void Real::set_uniform_vec3f(Shader *shader, Vector3f value, const char *name)
{
    U64 hash = HashMapN::hash_string(name);
    UniformElement *element = HashMapN::get_pointer(&shader->uniform_map, hash);
    if (element == nullptr)
    {
        fprintf(stderr, "WARNING: could not find uniform %s\n", name);
        return;
    }

    bind(shader);
    glUniform3f(element->location, value.x, value.y, value.z);
}


void Real::set_uniform_vec4f(Shader *shader, Vector4f value, const char *name)
{
    U64 hash = HashMapN::hash_string(name);
    UniformElement *element = HashMapN::get_pointer(&shader->uniform_map, hash);
    if (element == nullptr)
    {
        fprintf(stderr, "WARNING: could not find uniform %s\n", name);
        return;
    }

    bind(shader);
    glUniform4f(element->location, value.x, value.y, value.z, value.w);
}


void Real::set_uniform_mat4(Shader *shader, Mat4 *mat, const char *name)
{
    U64 hash = HashMapN::hash_string(name);
    UniformElement *element = HashMapN::get_pointer(&shader->uniform_map, hash);
    if (element == nullptr)
    {
        fprintf(stderr, "WARNING: could not find uniform %s\n", name);
        return;
    }

    bind(shader);
    glUniformMatrix4fv(element->location, 1, GL_FALSE, (float *)mat);
}