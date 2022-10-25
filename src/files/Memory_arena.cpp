#include "Memory_arena.hpp"
#include <string.h>
#include <stdlib.h>
#include "platform/platform.hpp"
#include "utils.hpp"

void Arena::init_top_arena(Memory_arena *arena, void *reserved_space_address, Usize page_pre_allocation, Usize max_pages_reserved)
{
    Usize page_size = Platform::get_page_size();
    
    arena->data = memory_map::commit(reserved_space_address, page_pre_allocation);

    if (page_pre_allocation > max_pages_reserved)
    {
        fprintf(stderr, "ERROR: resulting commit size %llu cannot be greater than max reserved size %llu\n", page_pre_allocation, max_pages_reserved);
        exit(1);
    }
    arena->bytes_allocated = 0;
    arena->max_size_commited = page_pre_allocation * page_size;
    arena->max_size_reserved = max_pages_reserved * page_size;



    clear_top_arena(arena);
}


void Arena::clean_arena(Memory_arena *arena)
{
    memory_map::free(arena->data, arena->max_size_commited);
    arena->data = nullptr;
    arena->bytes_allocated = 0;
    arena->max_size_commited = 0;
    arena->max_size_reserved = 0;
}


void *Arena::top_alloc_bytes(Memory_arena *arena, Usize bytes, Usize alignment)
{
    #if 1
    // dbg(fprintf(stderr, "DEBUG: top Allocation [%p, %llu %llu]\n", arena, bytes, alignment));

    void *non_aligned_data = (char *)arena->data + arena->bytes_allocated;
    Usize alignment_shift = (Usize)Utils::align_pointer(non_aligned_data, alignment) - (Usize)non_aligned_data;
       
    Usize aligned_bytes = bytes + alignment_shift;

    if (aligned_bytes + arena->bytes_allocated > arena->max_size_commited)
    {
        // if byte allocation is out of top_arena bounds, commit more from reserved memory.
        Usize page_size = Platform::get_page_size();
        Usize page_amount = Platform::bytes_to_page_amount(arena->max_size_commited + aligned_bytes);


        if (arena->bytes_allocated + page_amount * page_size > arena->max_size_reserved)
        {
            fprintf(stderr, "ERROR: allocation out of top arena's reserved bounds\n");
            exit(1);
        }
        memory_map::commit((char *)arena->data + arena->max_size_commited, page_amount);
        arena->max_size_commited += page_amount * page_size;

    }


    void *data = (char *)non_aligned_data + alignment_shift;

    arena->bytes_allocated += aligned_bytes;

    return data;
    #else
    return malloc(bytes);
    #endif
}


void Arena::clear_top_arena(Memory_arena *arena)
{
   // memset(arena->data, 0, arena->max_size_commited);
    arena->bytes_allocated = 0;
}