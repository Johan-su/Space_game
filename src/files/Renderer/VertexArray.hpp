#pragma once

#include "../int.hpp"


struct VertexBuffer
{
    U32 id;
};



namespace Real
{
    void init_vbuffer(VertexBuffer *vb, Usize buffer_size, const void *data);
    void clean_vbuffer(VertexBuffer *vb);
    void bind(VertexBuffer *vb);
    void unbind(VertexBuffer *vb);    
} // namespace Real



#include "VertexLayout.hpp"

struct VertexArray
{
    U32 id;
};



namespace Real
{
    void init_vArray(VertexArray *va);    
    void clean_vArray(VertexArray *va);    
    void bind(VertexArray *va);    
    void unbind(VertexArray *va);

    void add_buffers(VertexArray *va, VertexBuffer *vb, VertexLayout *vlayout);
} // namespace Real
