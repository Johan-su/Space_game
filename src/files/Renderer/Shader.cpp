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


void Real::init_shader(Shader *shader, const char *vert_src, const char *frag_src)
{
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
}




void Real::bind(Shader *shader)
{
    glUseProgram(shader->id);
}


void Real::unbind(Shader *shader)
{
    glUseProgram(0);
}