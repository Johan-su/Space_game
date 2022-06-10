#ifdef _WIN64

#include "win_deltatime.hpp"

#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <sys/timeb.h>
#include <stdint.h>

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

#endif