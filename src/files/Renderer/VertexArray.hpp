#pragma once

#include "../int.hpp"

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
} // namespace Real
