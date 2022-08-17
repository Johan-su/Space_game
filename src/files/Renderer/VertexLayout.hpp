#pragma once

#include "../int.hpp"

struct VertexElement
{
    U32 type;
    U32 count;
    bool normalized;
};


#define MAX_LAYOUT_ELEMENTS 256

struct VertexLayout
{
    U64 stride;
    Usize count;
    VertexElement elements[MAX_LAYOUT_ELEMENTS];
};



namespace Real
{
    void init_layout(VertexLayout *layout);


    void add_type(VertexLayout *layout, U32 count, U32 type, bool normalized);
    void add_float(VertexLayout *layout, U32 count);
    void add_U32(VertexLayout *layout, U32 count);
    void add_U8(VertexLayout *layout, U32 count);
    void add_I8(VertexLayout *layout, U32 count);
    void add_I32(VertexLayout *layout, U32 count);

    Usize sizeof_gltype(U32 type);
} // namespace Real
