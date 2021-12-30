#pragma once
#include "../../src/ecs/MemoryManager.hpp"
#include "../../src/ecs/ComponentManager.hpp"

namespace ComponentManager_test
{
    int test()
    {
        Memory_pool *mm = new Memory_pool;
        Memory::init(mm);
        auto *cdata = Memory::alloc<Component_data>(mm);

        Component_functions::clean(mm, cdata);
        Component_functions::init(mm, cdata);
        Component_functions::init(mm, cdata);



        return 69;
    }
}