#pragma once

#ifdef __linux__
#include <stdint.h>

namespace Linux 
{
    uint64_t get_micro_time();
    uint64_t get_mili_time();
    uint64_t get_sec_time();
}

#endif
