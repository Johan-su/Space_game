#pragma once
#ifdef _WIN64

#include <stdint.h>

namespace Windows
{
    // initalization if needed
    void init();

    // timestamp functions
    uint64_t get_micro_time();
    uint64_t get_mili_time();
    uint64_t get_sec_time();

    // memory functions
    void *reserve(void *address, size_t size);
    void *commit(void *address, size_t size);
    void free(void *address, size_t size);
    size_t get_page_size();



} // namespace Windows

#endif