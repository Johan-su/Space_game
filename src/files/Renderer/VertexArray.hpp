#pragma once

#include "../int.hpp"

#include "VertexBuffer.hpp"
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
