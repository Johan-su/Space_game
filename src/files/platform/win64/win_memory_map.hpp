#pragma once
#ifdef _WIN64

namespace Windows
{
    void *reserve(void *address, size_t size);
    void *commit(void *address, size_t size);
} // namespace Windows


#endif