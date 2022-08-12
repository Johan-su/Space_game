#ifdef _WIN64
#define _CRT_SECURE_NO_WARNINGS
#include "win64_layer.hpp"
#include <Windows.h>
#include <sys/timeb.h>

#include <stdio.h>

SYSTEM_INFO g_info;

void Windows::init()
{

    GetSystemInfo(&g_info);
}





static FILETIME time;

uint64_t Windows::get_micro_time()
{
    GetSystemTimePreciseAsFileTime(&time);

    return ((((uint64_t)time.dwHighDateTime) << 32) + (uint64_t)time.dwLowDateTime) / 10;    
}

uint64_t Windows::get_mili_time()
{
    GetSystemTimePreciseAsFileTime(&time);

    return ((((uint64_t)time.dwHighDateTime) << 32) + (uint64_t)time.dwLowDateTime) / 10000;
}


uint64_t Windows::get_sec_time()
{
    GetSystemTimePreciseAsFileTime(&time);

    return ((((uint64_t)time.dwHighDateTime) << 32) + (uint64_t)time.dwLowDateTime) / 10000000; 
}






void *Windows::reserve(void *address, size_t page_amount)
{
    size_t page_size = g_info.dwPageSize;

    LPVOID V_address = VirtualAlloc(address, page_amount * page_size, MEM_RESERVE, PAGE_READWRITE);
    if (V_address == NULL)
    {
        fprintf(stderr, "ERROR: failed reserving memory with %lu\n", GetLastError());
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
        fprintf(stderr, "ERROR: failed commiting memory with %lu\n", GetLastError());
        exit(1);
    }


    return V_address;
}

void Windows::free(void *address, size_t page_amount)
{
    size_t page_size = g_info.dwPageSize;

    if (VirtualFree(address, page_amount * page_size, MEM_DECOMMIT) == 0)
    {
        fprintf(stderr, "ERROR: failed freeing memory with %lu\n", GetLastError());
        exit(1);
    }
}



size_t Windows::get_page_size()
{
    return g_info.dwPageSize;
}





#endif
