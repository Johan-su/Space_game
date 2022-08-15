#pragma once
#include <stdint.h>
#include <string.h>

template<typename T>
struct HashMap
{
    //uint64_t hash[8192];

    uint64_t size;
    uint64_t count;
    
    uint64_t keys[8192];
    T values[8192];
};

namespace HashMapN // TODO(johan) implement good and real hash map
{
    template<typename T>
    void init(HashMap<T> *map)
    {
        memset(map, 0, sizeof(*map));
        memset(map->keys, 0xFF, sizeof(map->keys));
    }


    template<typename T>
    T *get_pointer(HashMap<T> *map, uint64_t key)
    {
        uint64_t pos = UINT64_MAX;
        for(uint64_t i = 0; i < map->count; ++i)
        {
            if (map->keys[i] == key)
            {
                pos = i;
                break;
            }
        }

        if (pos == SIZE_MAX)
        {
            return nullptr;
        }
        else
        {
            return &map->values[pos];
        }

    }


    template<typename T>
    void set(HashMap<T> *map, uint64_t key, T value)
    {
        T *value_pointer = get_pointer(map, key);

        if (value_pointer == nullptr) // check if map does not include key
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
    T get_value(HashMap<T> *map, uint64_t key) // Super sketchy function
    {
        T *value_pointer = get_pointer(map, key);

        if (value_pointer)
        {
            return *value_pointer;
        }

        return T{};
    }


    inline uint64_t hash_string(const char *str) //TODO(Johan): do real hashing
    {
        uint64_t str_len = strlen(str);

        uint64_t hash = 0;

        for (int i = 0; i < str_len; ++i)
        {
            hash += str[i];
        }

        return hash;
    }

}
