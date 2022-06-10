#pragma once
#ifdef _WIN64

namespace Windows
{
    void *reserve(void *address, size_t size);
    void *commit(void *address, size_t size);
    void free(void *address, size_t size);
    size_t get_page_size();
} // namespace Windows


#endif