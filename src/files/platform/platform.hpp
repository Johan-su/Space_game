#pragma once




#include <stdint.h>


namespace Platform
{
    void init();
    size_t get_page_size();
    /**
     * @return gives page amount rounded up
     */ 
    size_t bytes_to_page_amount(size_t bytes);
    size_t page_amount_to_bytes(size_t page_amount);
} // namespace Platform



namespace deltaTime
{
    uint64_t get_micro_time();
    uint64_t get_mili_time();
    uint64_t get_sec_time();
}


namespace memory_map
{
    void *reserve(void *address, size_t page_amount);
    void *commit(void *address, size_t page_amount);
    void free(void *address, size_t page_amount);
} // namespace memory_map