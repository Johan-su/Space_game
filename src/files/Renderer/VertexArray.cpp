#include "VertexArray.hpp"


#include "../core/loadgl/load_gl.hpp"

void Real::init_vArray(VertexArray *va)
{
    glGenVertexArrays(1, &va->id);
}   


void Real::clean_vArray(VertexArray *va)
{
    glDeleteVertexArrays(1, &va->id);
}   


void Real::bind(VertexArray *va)
{
    glBindVertexArray(va->id);
}   


void Real::unbind(VertexArray *va)
{
    glBindVertexArray(0);
}   


void Real::add_buffers(VertexArray *va, VertexBuffer *vb, VertexLayout *vlayout)
{
    bind(va);
    bind(vb);

    U64 offset = 0;

    for (Usize i = 0; i < vlayout->count; ++i)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, vlayout->attributes[i].count, vlayout->attributes[i].type, vlayout->attributes[i].normalized, vlayout->stride, (const void *)offset);
        
        offset += vlayout->attributes[i].count * sizeof_gltype(vlayout->attributes[i].type);
    }
}