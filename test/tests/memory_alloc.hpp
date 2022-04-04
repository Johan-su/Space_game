#pragma once
#include "../../src/files/ecs/MemoryManager.hpp"

namespace memory_alloc
{
    using namespace Ecs;
    int test()
    {

        Memory_pool *mm = new Memory_pool();
        Memory::init(mm);

        auto *data  = MEMORY_ALLOC(mm, uint64_t, 1);
        auto *data2 = MEMORY_ALLOC(mm, uint8_t, 100);
        auto *data3 = MEMORY_ALLOC(mm, uint64_t, 1);

        *data = UINT64_MAX;

        for(size_t i = 0; i < 100; ++i)
        {
            *(data2 + i) = i;
        }
        *data3 = 0x11111111ABCDEF01; // little endian memory pattern
        

        Memory::dump(mm, 140, false);
        Memory::clean(mm);
        delete mm;
        mm = nullptr;
        return 0;
    }
}