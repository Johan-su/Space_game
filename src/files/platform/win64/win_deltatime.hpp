#pragma once
#ifdef _WIN64




#include <stdint.h>
namespace Windows
{
    uint64_t get_micro_time();
    uint64_t get_mili_time();
    uint64_t get_sec_time();
}
#endif