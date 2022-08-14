#include "platform.hpp"


#include <stdio.h>



#ifdef _WIN64

#include "win64/win64_layer.hpp"

void Platform::init()
{
    Windows::init();
}


Usize Platform::get_page_size()
{
    return Windows::get_page_size();
}


Usize Platform::bytes_to_page_amount(Usize bytes)
{
    return 1 + (bytes / (get_page_size() + 1));
}


Usize Platform::page_amount_to_bytes(Usize page_amount)
{
    return page_amount * get_page_size();
}


void Platform::get_abs_path(const char *src_path, char *buf, U32 buf_len)
{
    return Windows::get_abs_path(src_path, buf, buf_len);
}


U64 deltaTime::get_micro_time()
{
    return Windows::get_micro_time();
}


U64 deltaTime::get_mili_time()
{
    return Windows::get_mili_time();
}


U64 deltaTime::get_sec_time()
{
    return Windows::get_sec_time();
}


void *memory_map::reserve(void *address, Usize page_amount)
{
    return Windows::reserve(address, page_amount);
}


void *memory_map::commit(void *address, Usize page_amount)
{
    fprintf(stderr, "DEBUG: commit [%p, %llu]\n", address, page_amount);
    return Windows::commit(address, page_amount);
}


void memory_map::free(void *address, Usize page_amount)
{
    Windows::free(address, page_amount);
}

#endif









#ifdef __linux__

#include "linux/linux_layer.hpp"

void Platform::init()
{
    Linux::init();
}


Usize Platform::get_page_size()
{
    return Linux::get_page_size();
}


Usize Platform::bytes_to_page_amount(Usize bytes)
{
    return 1 + (bytes / (get_page_size() + 1));
}


Usize Platform::page_amount_to_bytes(Usize page_amount)
{
    return page_amount * get_page_size();
}


U64 deltaTime::get_micro_time()
{
    return Linux::get_micro_time();
}


U64 deltaTime::get_mili_time()
{
    return Linux::get_mili_time();
}


U64 deltaTime::get_sec_time()
{
    return Linux::get_sec_time();
}


void *memory_map::reserve(void *address, Usize page_amount)
{
    return Linux::reserve(address, page_amount);
}


void *memory_map::commit(void *address, Usize page_amount)
{
    fprintf(stderr, "DEBUG: commit [%p, %llu]\n", address, page_amount);
    return Linux::commit(address, page_amount);
}


void memory_map::free(void *address, Usize page_amount)
{
    Linux::free(address, page_amount);
}




#endif