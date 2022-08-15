#ifdef _WIN64
#include "win64_layer.hpp"
#include <Windows.h>
#include <sys/timeb.h>

#include <stdio.h>
#include <string.h>

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
    if (V_address == nullptr)
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
    if (V_address == nullptr)
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


void Windows::get_abs_path(const char *src_path, char *buf, uint32_t buf_len)
{

    // normal buf_len wont include space for filename so we subtract the filename length to require more memory
    DWORD shortened_buf_len = buf_len;

    uint32_t filename_pos = strlen(src_path);
    {
        while (filename_pos > 0)
        {
            if (*(src_path + filename_pos) == '/')
            {
                break;
            }
            filename_pos -= 1;
        }
        shortened_buf_len -= (strlen(src_path) - filename_pos);
    }

   DWORD path_length = GetFullPathNameA(src_path, shortened_buf_len, buf, nullptr);

   if (path_length > shortened_buf_len)
   {
        fprintf(stderr, "ERROR: getting full path name failed with %lu\n", GetLastError());
        exit(1);
   }
}








#endif
