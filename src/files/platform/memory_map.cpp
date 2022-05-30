#include "memory_map.hpp"



#ifdef _WIN64

#include "win64/win_memory_map.hpp"

void *memory_map::reserve(void *address, size_t size)
{
    return Windows::reserve(address, size);
}


void *memory_map::commit(void *address, size_t size)
{
    return Windows::commit(address, size);
}

#endif