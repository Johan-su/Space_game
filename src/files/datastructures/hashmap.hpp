#pragma once
#include <stdint.h>
#include <string.h>

template<typename T>
struct hash_map
{
    //size_t hash[8192];

    size_t size;
    size_t count;
    
    size_t keys[8192];
    T values[8192];
};

namespace Hashmap // TODO(johan) implement good and real hash map
{
    template<typename T>
    void init(hash_map<T> *map)
    {
        memset(map, 0, sizeof(*map));
        memset(map->keys, 0xFF, sizeof(map->keys));
    }


    template<typename T>
    T *get_pointer(hash_map<T> *map, size_t key)
    {
        size_t pos = SIZE_MAX;
        for(size_t i = 0; i < map->count; ++i)
        {
            if (map->keys[i] == key)
            {
                pos = i;
                break;
            }
        }

        if (pos == SIZE_MAX)
        {
            return NULL;
        }
        else
        {
            return &map->values[pos];
        }

    }


    template<typename T>
    void set(hash_map<T> *map, size_t key, T value)
    {
        T *value_pointer = get_pointer(map, key);

        if (value_pointer == NULL) // check if map does not include key
        {
            map->values[map->count] = value;
            map->keys[map->count] = key;
            ++map->count;
        }
        else
        {
            *value_pointer = value;
        }
    }


    template<typename T>
    T get_value(hash_map<T> *map, size_t key) // Super sketchy function
    {
        T *value_pointer = get_pointer(map, key);

        if (value_pointer)
        {
            return *value_pointer;
        }

        return T();
    }

}
