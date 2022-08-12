#include <chrono>
#ifdef __linux__

#include "lin_deltatime.hpp"
#include "chrono"
#include "sys/time.h"

using namespace std::chrono;

uint64_t Linux::get_micro_time() 
{
    using time_stamp = time_point<system_clock, microseconds>;

    time_stamp ts = time_point_cast<microseconds>(system_clock::now());
    auto microseconds = ts.time_since_epoch().count();

    return microseconds;
}

uint64_t Linux::get_mili_time() 
{
    using time_stamp = time_point<system_clock, milliseconds>;

    time_stamp ts = time_point_cast<milliseconds>(system_clock::now());
    auto milliseconds = ts.time_since_epoch().count();

    return milliseconds;
}

uint64_t Linux::get_sec_time() 
{
    using time_stamp = time_point<system_clock, seconds>;

    time_stamp ts = time_point_cast<seconds>(system_clock::now());
    auto seconds = ts.time_since_epoch().count();

    return seconds;
}

#endif
