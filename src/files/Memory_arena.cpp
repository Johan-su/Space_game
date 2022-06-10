#include "Memory_arena.hpp"
#include <string.h>

#include "platform/platform.hpp"


void Arena::init_top_arena(top_memory_arena *arena, void *reserved_space_address, size_t page_pre_allocation, size_t max_pages_reserved)
{
    size_t page_size       = Platform::get_page_size();
    
    arena->data = memory_map::commit(reserved_space_address, page_pre_allocation);

    if(page_pre_allocation > max_pages_reserved)
    {
        fprintf(stderr, "ERROR: resulting commit size %llu cannot be greater than max reserved size %llu\n", page_pre_allocation, max_pages_reserved);
        exit(1);
    }
    arena->bytes_allocated = 0;
    arena->max_size_commited = page_pre_allocation * page_size;
    arena->max_size_reserved = max_pages_reserved * page_size;



    clear_top_arena(arena);
}


void Arena::clean_arena(top_memory_arena *arena)
{
    memory_map::free(arena->data, arena->max_size_commited);
    arena->data = NULL;
    arena->bytes_allocated = 0;
    arena->max_size_commited = 0;
    arena->max_size_reserved = 0;
}



void *Arena::top_alloc_bytes(top_memory_arena *arena, size_t bytes, size_t alignment)
{
    // dbg(fprintf(stderr, "DEBUG: top Allocation [%p, %llu %llu]\n", arena, bytes, alignment));

    void *non_aligned_data = (char *)arena->data + arena->bytes_allocated;
    size_t alignment_shift = (size_t)non_aligned_data % alignment;
       
    size_t aligned_bytes = bytes + alignment_shift;

    if(aligned_bytes + arena->bytes_allocated > arena->max_size_commited)
    {
        // if byte allocation is out of top_arena bounds, commit more from reserved memory.
        size_t page_size = Platform::get_page_size();
        size_t page_amount = Platform::bytes_to_page_amount(arena->max_size_commited + aligned_bytes);


        if(arena->bytes_allocated + page_amount * page_size > arena->max_size_reserved)
        {
            fprintf(stderr, "ERROR: allocation out of top arena reserved bounds");
            exit(1);
        }
        memory_map::commit((char *)arena->data + arena->max_size_commited, page_amount);
        arena->max_size_commited += page_amount * page_size;

    }


    void *data = (char *)non_aligned_data + alignment_shift;

    arena->bytes_allocated += aligned_bytes;

    return data;
}



void Arena::grow_arena(top_memory_arena *arena, size_t page_amount)
{
    size_t page_size = Platform::get_page_size();

    void *last_data = (char *)arena->data + arena->max_size_commited;

    memory_map::commit(last_data, page_amount * page_size);
    arena->max_size_commited += page_amount * page_size;

}


memory_arena *Arena::create_sub_arena(top_memory_arena *parent_arena, size_t max_size)
{
    assert(false, "TODO: implement"); //TODO(Johan): implement
    return NULL;
    memory_arena *arena = top_alloc<memory_arena>(parent_arena);
    arena->max_size = max_size;

    arena->data = (char *)parent_arena->data + parent_arena->bytes_allocated; // cast to char * to do pointer arithmetic
    parent_arena->bytes_allocated += max_size; // add bytes allocated from sub arena size

    clear_arena(arena);


    return arena;
}


void Arena::clear_arena(memory_arena *arena)
{
    memset(arena->data, 0, arena->max_size);
    arena->bytes_allocated = 0;
}


void Arena::clear_top_arena(top_memory_arena *arena)
{
   // memset(arena->data, 0, arena->max_size_commited);
    arena->bytes_allocated = 0;
}