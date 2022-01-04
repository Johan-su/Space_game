#pragma once
#include "../../src/files/ecs/MemoryManager.hpp"

namespace memory_alloc
{
    int test()
    {

        Memory_pool *mm = new Memory_pool();
        Memory::init(mm);

        auto *data = Memory::alloc<uint64_t>(mm);
        auto *data2 = Memory::alloc<uint8_t>(mm, 100);

        *data = UINT64_MAX;

        for(int i = 0; i < 100; ++i)
        {
            *(data2 + i) = i;
        }

        Memory::dump(mm, 120, false);
        return 0;
    }
}