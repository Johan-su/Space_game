#ifdef _WIN64
#include "win_memory_map.hpp"

#include <stdio.h>

#include <Windows.h>


void *Windows::reserve(void *address, size_t size)
{
    LPVOID V_address = VirtualAlloc(NULL, size, MEM_RESERVE, NULL);
    if(V_address == NULL)
    {
        fprintf(stderr, "failed reserving memory");
        exit(1);
    }

    return V_address;
}


void *Windows::commit(void *address, size_t size)
{
    LPVOID V_address = VirtualAlloc(NULL, size, MEM_COMMIT, NULL);
    if(V_address == NULL)
    {
        fprintf(stderr, "failed commiting memory");
        exit(1);
    }


    return V_address;
}

#endif