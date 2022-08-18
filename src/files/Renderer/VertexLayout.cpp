#include "VertexLayout.hpp"


#include "../assert.hpp"
#include <GLFW/glfw3.h>


void Real::init_layout(VertexLayout *layout)
{
    layout->count = 0;
    layout->stride = 0;
}






void Real::add_type(VertexLayout *layout, U32 count, U32 type, bool normalized)
{
    layout->attributes[layout->count] = {
        .type = type,
        .count = count,
        .normalized = normalized,
    };
    layout->stride += count * sizeof_gltype(type);
    layout->count += 1; 
}


void Real::add_float(VertexLayout *layout, U32 count)
{
    add_type(layout, count, GL_FLOAT, false);
}


void Real::add_U32(VertexLayout *layout, U32 count)
{
    add_type(layout, count, GL_UNSIGNED_INT, false);
}


void Real::add_U8(VertexLayout *layout, U32 count)
{
    add_type(layout, count, GL_UNSIGNED_BYTE, false);
}


void Real::add_I8(VertexLayout *layout, U32 count)
{
    add_type(layout, count, GL_BYTE, false);
}


void Real::add_I32(VertexLayout *layout, U32 count)
{
    add_type(layout, count, GL_INT, false);
}


Usize Real::sizeof_gltype(U32 type)
{
    switch (type)
    {
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_SHORT: return 2;
        case GL_UNSIGNED_BYTE: return 1;
        
        case GL_INT: return 4;
        case GL_SHORT: return 2;
        case GL_BYTE: return 1;

        case GL_FLOAT: return 4;
    
        default: assert(false, "ERROR: unknown gl type"); return 0;
    }
}