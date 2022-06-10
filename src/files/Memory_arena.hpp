#pragma once
#include "assert.hpp"
#include "platform/platform.hpp"
#include <stdint.h>



struct memory_arena
{
    size_t max_size;
    size_t bytes_allocated;
    void *data;
};



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
    /**
     * 
     * grow arena by bytes
     * @param bytes amount to grow the arena with (gets converted to pages)
     * 
     */

    void *top_alloc_bytes(top_memory_arena *arena, size_t bytes, size_t alignment);

    void grow_arena(top_memory_arena *arena, size_t bytes);

    memory_arena *create_sub_arena(top_memory_arena *parent_arena, size_t max_size);

    void clear_arena(memory_arena *arena);
    void clear_top_arena(top_memory_arena *arena);



} // namespace Memory


namespace Arena
{
    template<typename T>
    T *top_alloc(top_memory_arena *arena, size_t size = 1)
    {
        return (T *)top_alloc_bytes(arena, sizeof(T) * size, alignof(T));
    }


    template<typename T>
    T *alloc(memory_arena *arena, size_t size = 1)
    {

        size_t byte_allocation = sizeof(T) * size;
        if(byte_allocation + arena->bytes_allocated > arena->max_size)
        {
            fprintf(stderr, "WARNING: allocation out of arena bounds returning NULL");
            return (T *)NULL;
        }

        T *data = (T *)((char *)arena->data + arena->bytes_allocated);

        arena->bytes_allocated += byte_allocation;

        return data;
    }
} // namespace Memory

