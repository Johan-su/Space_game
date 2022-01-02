#pragma once
#include "../../src/ecs/MemoryManager.hpp"
#include "../../src/ecs/ComponentManager.hpp"

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