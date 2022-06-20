#pragma once




#include "../int.hpp"


namespace Platform
{
    void init();
    Usize get_page_size();
    /**
     * @return gives page amount rounded up
     */ 
    Usize bytes_to_page_amount(Usize bytes);
    Usize page_amount_to_bytes(Usize page_amount);
} // namespace Platform



namespace deltaTime
{
    U64 get_micro_time();
    U64 get_mili_time();
    U64 get_sec_time();
}


namespace memory_map
{
    void *reserve(void *address, Usize page_amount);
    void *commit(void *address, Usize page_amount);
    void free(void *address, Usize page_amount);
} // namespace memory_map