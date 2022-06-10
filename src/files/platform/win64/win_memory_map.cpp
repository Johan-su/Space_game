#ifdef _WIN64

#include "win_memory_map.hpp"
#include "win_init.hpp"
#include <stdio.h>

#include <Windows.h>


void *Windows::reserve(void *address, size_t page_amount)
{
    size_t page_size = g_info.dwPageSize;

    LPVOID V_address = VirtualAlloc(address, page_amount * page_size, MEM_RESERVE, PAGE_READWRITE);
    if (V_address == NULL)
    {
        fprintf(stderr, "failed reserving memory with %lu\n", GetLastError());
        exit(1);
    }

    return V_address;
}


void *Windows::commit(void *address, size_t page_amount)
{
    size_t page_size = g_info.dwPageSize;

    LPVOID V_address = VirtualAlloc(address, page_amount * page_size, MEM_COMMIT, PAGE_READWRITE);
    if (V_address == NULL)
    {
        fprintf(stderr, "failed commiting memory with %lu\n", GetLastError());
        exit(1);
    }


    return V_address;
}

void Windows::free(void *address, size_t page_amount)
{
    size_t page_size = g_info.dwPageSize;

    if (VirtualFree(address, page_amount * page_size, MEM_DECOMMIT) == 0)
    {
        fprintf(stderr, "failed freeing memory with %lu\n", GetLastError());
        exit(1);
    }
}



size_t Windows::get_page_size()
{
    return g_info.dwPageSize;
}


#endif