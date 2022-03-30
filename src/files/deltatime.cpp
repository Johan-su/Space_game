#include "deltatime.hpp"

#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS
    #include <sys/timeb.h>
#endif


#include <stdint.h>

static __timeb64 time;


uint64_t deltaTime::get_milis_time()
{
    _ftime64(&time);

    return (uint64_t)(time.time * 1000 + time.millitm);
}


uint64_t deltaTime::get_sec_time()
{
    _ftime64(&time);

    return (uint64_t)(time.time + time.millitm / 1000);
}

