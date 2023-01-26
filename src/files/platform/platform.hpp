#pragma once




#include "../int.hpp"


namespace Platform
{
    void init();

    Usize get_page_size();

    // returns page amount rounded up
    inline Usize bytes_to_page_amount(Usize bytes)
    {
        return 1 + (bytes / (get_page_size() + 1));
    }

    inline Usize page_amount_to_bytes(Usize page_amount)
    {
        return page_amount * get_page_size();
    }



    void *reserve(void *address, Usize page_amount);
    void *commit(void *address, Usize page_amount);
    void free(void *address, Usize page_amount);


    U64 get_micro_time();
    U64 get_mili_time();
    U64 get_sec_time();

    void get_abs_path(const char *src_path, char *buf, U32 buf_len);
} // namespace Platform
