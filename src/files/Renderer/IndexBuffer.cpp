#include "IndexBuffer.hpp"


#include "../core/loadgl/load_gl.hpp"


void Real::init_ibuffer(IndexBuffer *ib, U32 count, const U32 *data)
{
    glGenBuffers(1, &ib->id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(U32), data, GL_STATIC_DRAW);
    ib->count = count;
}


void Real::clean_ibuffer(IndexBuffer *ib)
{
    glDeleteBuffers(1, &ib->id);
}


void Real::bind(IndexBuffer *ib)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->id);
}


void Real::unbind(IndexBuffer *ib)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}   


