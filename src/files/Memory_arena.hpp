#pragma once
#include "assert.hpp"
#include "platform/platform.hpp"
#include <stdint.h>



struct top_memory_arena
{
    size_t max_size_commited; // with current allocation
    size_t max_size_reserved;
    size_t bytes_allocated;
    void *data;
};


namespace Arena  
{
    /**
     * 
     * 
     * 
     * @param pre_allocation current commit size in bytes (gets converted to pages)
     * @param max_size_reserved max reserved size in bytes (gets converted to pages)
     * 
     */
    void init_top_arena(top_memory_arena *arena, void *reserved_space_address, size_t pre_allocation, size_t max_size_reserved);
    void clean_arena(top_memory_arena *arena);
    void *top_alloc_bytes(top_memory_arena *arena, size_t bytes, size_t alignment);

    void clear_top_arena(top_memory_arena *arena);



} // namespace Memory


namespace Arena
{
    template<typename T>
    T *top_alloc(top_memory_arena *arena, size_t size = 1)
    {
        return (T *)top_alloc_bytes(arena, sizeof(T) * size, alignof(T));
    }
} // namespace Memory

