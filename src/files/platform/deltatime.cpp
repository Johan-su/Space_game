#include "deltatime.hpp"

#include <stdint.h>



#ifdef _WIN64
#include "./win64/win_deltatime.hpp"

uint64_t deltaTime::get_micro_time()
{
    return Windows::get_micro_time();
}


uint64_t deltaTime::get_mili_time()
{
    return Windows::get_mili_time();
}


uint64_t deltaTime::get_sec_time()
{
    return Windows::get_sec_time();
}

#endif

