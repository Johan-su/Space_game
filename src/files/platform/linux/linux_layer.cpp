#ifdef __linux__
#include "linux_layer.hpp"

#include <chrono>
#include <sys/time.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void Linux::init()
{

}


uint64_t Linux::get_micro_time()
{
    using namespace std::chrono;
    using time_stamp = time_point<system_clock, microseconds>;

    time_stamp ts = time_point_cast<microseconds>(system_clock::now());
    auto microseconds = ts.time_since_epoch().count();

    return microseconds;
}


uint64_t Linux::get_mili_time()
{
    using namespace std::chrono;
    using time_stamp = time_point<system_clock, milliseconds>;

    time_stamp ts = time_point_cast<milliseconds>(system_clock::now());
    auto milliseconds = ts.time_since_epoch().count();

    return milliseconds;
}


uint64_t Linux::get_sec_time()
{
    using namespace std::chrono;
    using time_stamp = time_point<system_clock, seconds>;

    time_stamp ts = time_point_cast<seconds>(system_clock::now());
    auto seconds = ts.time_since_epoch().count();

    return seconds;
}











void *Linux::reserve(void *address, size_t size)
{
    void  *V_address = mmap(address, size * get_page_size(), PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    if (V_address == MAP_FAILED)
    {
        fprintf(stderr, "ERROR: failed reserving memory with %lu\n", errno);
        exit(1);
    }

    return V_address;
}


void *Linux::commit(void *address, size_t size)
{
    if (mprotect(address, size * get_page_size(), PROT_READ|PROT_WRITE) == -1)
    {
        fprintf(stderr, "ERROR: failed committing memory with %lu\n", errno);
        exit(1);
    }

    return address;
}


void Linux::free(void *address, size_t size)
{
    if (munmap(address, size * get_page_size()) == -1)
    {
        fprintf(stderr, "ERROR: failed freeing memory with %lu\n", errno);
        exit(1);
    }
}


size_t Linux::get_page_size()
{
    int page_size = getpagesize();

    return (size_t)page_size;
}



















#endif
