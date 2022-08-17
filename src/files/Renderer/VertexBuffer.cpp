#include "VertexBuffer.hpp"

#include "../core/loadgl/load_gl.hpp"



void Real::init_vbuffer(VertexBuffer *vb, Usize buffer_size, const void *data)
{
    glGenBuffers(1, &vb->id);
    glBindBuffer(GL_ARRAY_BUFFER, vb->id);
    glBufferData(GL_ARRAY_BUFFER, buffer_size, data, GL_STATIC_DRAW);
}


void Real::clean_vbuffer(VertexBuffer *vb)
{
    glDeleteBuffers(1, &vb->id);
}


void Real::bind(VertexBuffer *vb)
{
    glBindBuffer(GL_ARRAY_BUFFER, vb->id);
}


void Real::unbind(VertexBuffer *vb)
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

