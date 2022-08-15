#include "mesh.hpp"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>




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


static void move_past_whitespace(const char *&src)
{
    while (is_whitespace(*src))
    {
        src += 1;
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


static void is_word_and_move_or_error(const char *&src, const char *word, const char *error_msg)
{
    if (!is_word(src, word))
    {
        fprintf(stderr, "ERROR: %s\n", error_msg);
        exit(1);
    }
    src += strlen(word);    
}



static I32 parse_I32(const char *&src)
{
    char I32_buffer[256];

    // move past leading whitespace
    move_past_whitespace(src);

    // parse float
    U32 count = 0;
    while (!is_whitespace(*src) && !is_word(src, ",") && !is_word(src, "}"))
    {
        I32_buffer[count] = *src;
        count += 1;
        src += 1;
    }
    I32_buffer[count] = '\0';

    // if not at comma, move to comma
    move_past_whitespace(src);

    // move past comma
    if (!is_word(src, "}"))
        src += 1;

    return atoi(I32_buffer);
}



static float parse_float(const char *&src)
{
    char float_buffer[256];

    // move past leading whitespace
    move_past_whitespace(src);

    // parse float
    U32 count = 0;
    while (!is_whitespace(*src) && !is_word(src, ",") && !is_word(src, "}"))
    {
        float_buffer[count] = *src;
        count += 1;
        src += 1;
    }
    float_buffer[count] = '\0';

    // if not at comma, move to comma
    move_past_whitespace(src);

    // move past comma
    if (!is_word(src, "}"))
        src += 1;

    return (float)atof(float_buffer);
}


static float clamp(float min, float val, float max)
{
    if (val < min)
    {
        return min;
    }

    if (val > max)
    {
        return max;
    }

    return val;
}


static I32 clamp(I32 min, I32 val, I32 max)
{
    if (val < min)
    {
        return min;
    }

    if (val > max)
    {
        return max;
    }

    return val;
}


void MeshN::init(Mesh *mesh, const char *mesh_src)
{
    mesh->index_buffer.index_count = 0;
    for (Usize i = 0; i < MAX_VERTICIES; ++i)
    {
        mesh->vertex_buffer.verticies[i] = {
            .pos = {
                .x = VERTEX_NULL,
                .y = VERTEX_NULL,
                .z = VERTEX_NULL,
            },
            .tex_coords = {
                .u = VERTEX_NULL,
                .v = VERTEX_NULL,
            },
        };
    }


    for (Usize i = 0; i < MAX_INDICIES; ++i)
    {
        mesh->index_buffer.indicies[i] = INDEX_NULL;
    }

    Usize vertex_count = 0;
    Usize index_count = 0;

    move_past_whitespace(mesh_src);

    is_word_and_move_or_error(mesh_src, "Vertex", "First word is not Vertex");


    move_past_whitespace(mesh_src);

    
    is_word_and_move_or_error(mesh_src, "{", "did not find { after Vertex");


    for (/**/;!is_word(mesh_src, "}"); ++vertex_count)
    {
        mesh->vertex_buffer.verticies[vertex_count].pos.x = clamp(-1.0f, parse_float(mesh_src), 1.0f);
        mesh->vertex_buffer.verticies[vertex_count].pos.y = clamp(-1.0f, parse_float(mesh_src), 1.0f);
        mesh->vertex_buffer.verticies[vertex_count].pos.z = clamp(-1.0f, parse_float(mesh_src), 1.0f);
        mesh->vertex_buffer.verticies[vertex_count].tex_coords.u = clamp(0.0f, parse_float(mesh_src), 1.0f);
        mesh->vertex_buffer.verticies[vertex_count].tex_coords.v = clamp(0.0f, parse_float(mesh_src), 1.0f);
    }
    mesh->vertex_buffer.vertex_count = vertex_count;
    mesh_src += 1;

    move_past_whitespace(mesh_src);


    is_word_and_move_or_error(mesh_src, ";", "{} blocks has to end with ;");


    move_past_whitespace(mesh_src);


    is_word_and_move_or_error(mesh_src, "Index", "Second word is not Index");


    move_past_whitespace(mesh_src);


    is_word_and_move_or_error(mesh_src, "{", "did not find { after Index");


    move_past_whitespace(mesh_src);


    for (/**/; !is_word(mesh_src, "}"); ++index_count)
    {
        mesh->index_buffer.indicies[index_count] = clamp(0, parse_I32(mesh_src), _I32_MAX);
    }
    mesh->index_buffer.index_count = index_count;
    mesh_src += 1;


    move_past_whitespace(mesh_src);


    is_word_and_move_or_error(mesh_src, ";", "{} blocks has to end with ;");


    while (!is_word(mesh_src, "\0"))
    {
        mesh_src += 1;
    }

    if (*mesh_src != '\0')
    {
        fprintf(stderr, "ERROR: extra unaccounted for characters is not allowed");
        exit(1);
    }
    
}