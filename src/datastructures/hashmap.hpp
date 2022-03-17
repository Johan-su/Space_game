#pragma once
#include <stdint.h>
template<size_t S, typename T>
struct hash_map
{
    size_t keys[S];
    T values[S];
    size_t hash[S];

    size_t count;
    const size_t size;
};

namespace Internal // TODO(johan) implement hash function
{
    template<typename T>
    void add(hash_map<0, T> *map, size_t key, T value)
    {

    }


    template<typename T>
    T get(hash_map<0, T> *map, size_t key)
    {

    }


    void hash(size_t map_size, size_t index)
    {

    }

}
