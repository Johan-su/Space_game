#pragma once


#include "../int.hpp"

struct IndexBuffer
{
    U32 count;
    U32 id;
};


namespace Real
{
    void init_ibuffer(IndexBuffer *ib, U32 count, const U32 *data);
    void clean_ibuffer(IndexBuffer *ib);
    void bind(IndexBuffer *ib);
    void unbind(IndexBuffer *ib);        
} // namespace Real

