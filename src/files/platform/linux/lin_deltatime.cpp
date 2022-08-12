#include <bits/chrono.h>
#include <ctime>
#ifdef __linux__

#include "lin_deltatime.hpp"
#include "cstdint"
#include "sys/time.h"

uint64_t Linux::get_micro_time() 
{
    time_t now = time(nullptr);
    time_t microseconds = now * 1_000_000;

    return microseconds;
}

uint64_t Linux::get_mili_time() 
{
    time_t now = time(nullptr);
    time_t milliseconds = now * 1_000;

    return milliseconds;
}

uint64_t Linux::get_sec_time() 
{
    time_t now = time(nullptr);

    return now;
}

#endif
