#pragma once
#include "../../src/files/ecs/MemoryManager.hpp"
#include "../../src/files/ecs/ComponentManager.hpp"

namespace memory_double_init
{
    int test()
    {
        Memory_pool *mm = new Memory_pool();
        Memory::init(mm);
        Memory::init(mm);



        return 0;
    }
}