#pragma once
#include "assert.hpp"
#include "platform/platform.hpp"



struct Memory_arena
{
    Usize max_size_commited; // with current allocation
    Usize max_size_reserved;
    Usize bytes_allocated;
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
    void init_top_arena(Memory_arena *arena, void *reserved_space_address, Usize pre_allocation, Usize max_size_reserved);
    void clean_arena(Memory_arena *arena);
    void *top_alloc_bytes(Memory_arena *arena, Usize bytes, Usize alignment);

    void clear_top_arena(Memory_arena *arena);



} // namespace Memory


namespace Arena
{
    template<typename T>
    T *top_alloc(Memory_arena *arena, Usize size = 1)
    {
        return (T *)top_alloc_bytes(arena, sizeof(T) * size, alignof(T));
    }
} // namespace Memory

