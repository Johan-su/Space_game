#ifdef __linux__

#include "lin_deltatime.hpp"
#include "cstdint"
#include "chrono"

uint64_t Linux::get_micro_time() 
{
    auto start = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(
            elapsed).count();

    return microseconds;
}

uint64_t Linux::get_mili_time() 
{
    auto start = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    long long microseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
            elapsed).count();

    return microseconds;
}

uint64_t Linux::get_sec_time() 
{
    auto start = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    long long microseconds = std::chrono::duration_cast<std::chrono::seconds>(
            elapsed).count();

    return microseconds;
}

#endif
