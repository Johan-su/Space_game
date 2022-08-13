#pragma once
#ifdef __linux__
#include <stdint.h>


typedef uint64_t size_t;

namespace Linux
{
    // initalization if needed
    void init();

    // timestamp functions
    uint64_t get_micro_time();
    uint64_t get_mili_time();
    uint64_t get_sec_time();

    // memory functions
    void *reserve(void *address, size_t page_amount);
    void *commit(void *address, size_t page_amount);
    void free(void *address, size_t page_amount);
    size_t get_page_size();



} // namespace Linux

#endif