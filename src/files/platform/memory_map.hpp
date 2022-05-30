#pragma once


#include <stdint.h>

namespace memory_map
{
    void *reserve(void *address, size_t size);
    void *commit(void *address, size_t size);
} // namespace memory
