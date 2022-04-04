#include "MemoryManager.hpp"
#include "ecs_assert.hpp"
#include <cstring>

using namespace Ecs;


void Memory::init(Memory_pool *mm)
{
    ECS_assert(mm != nullptr, "Memory pool cannot be NULL");

    mm->m_runTimeData = malloc(MEMORY_POOL_SIZE);
    if(mm->m_runTimeData != nullptr)
    {
        memset(mm->m_runTimeData, 0, MEMORY_POOL_SIZE);
        mm->m_bytesAllocated = 0;
        mm->m_MemoryActive = true;
    }
    else
    {
        fprintf(stderr, "malloc failed, out of memory\n");
        exit(1);
    }
}


void Memory::clean(Memory_pool *mm)
{
    ECS_assert(mm->m_MemoryActive, "Memory pool already inactive");
    free(mm->m_runTimeData);
    mm->m_runTimeData = nullptr;
    mm->m_MemoryActive = false;
}


void *Memory::alloc(Memory_pool *mm, size_t type_size, size_t type_alignment, size_t amount)
{
    ECS_assert(amount > 0, "Cannot allocate 0 bytes");
    ECS_assert(mm->m_MemoryActive, "Inactive memory pool");
    ECS_assert(type_size * amount + mm->m_bytesAllocated < MEMORY_POOL_SIZE, "Out of memory");
    
    size_t padding = mm->m_bytesAllocated % type_size;
    size_t tmp = mm->m_bytesAllocated + padding;
    mm->m_bytesAllocated += padding + type_size * amount;
        
    return (void*)((char*)(mm->m_runTimeData) + tmp); // C++ forcing this mess
}


void Memory::dealloc(Memory_pool *mm, size_t type_size, size_t type_alignment, void *ptr, size_t amount)
{
    ECS_assert(amount > 0, "Cannot deallocate 0 bytes");
    ECS_assert(mm->m_MemoryActive, "Inactive memory pool");
            
    ECS_assert(mm->m_bytesAllocated - type_size * amount > 0, "Deallocation outside memory pool");
            
    ECS_assert(ptr >= mm->m_runTimeData, "Pointer outside memory pool");
    ECS_assert((char*)ptr < (char*)mm->m_runTimeData + MEMORY_POOL_SIZE, "Pointer outside memory pool");
            
    for(size_t i = 0; i < type_size * amount; ++i) // only sets the allocated values to zeroes.
    {
        *((char*)(ptr) + i) = 0;
    }

    //TODO(Johan) add real allocation/deallocation
}


void Memory::dump(Memory_pool *mm, const size_t size = 512, bool addr = true)
{
    ECS_assert(mm->m_MemoryActive, "uninitalized memory pool");
    ECS_assert(size < MEMORY_POOL_SIZE, "Dump size greater than pool size");

    if(addr)
    {
        size_t rowsize = 16;
        for(size_t i = 0; i < size / rowsize; ++i)
        {
            printf("0x%08x : ", ((uint32_t)((uint64_t)((char*)(mm->m_runTimeData) + rowsize * i)))); // nice casting to suppress warnings
            for(size_t j = 0; j < rowsize; ++j)
            {
                auto val = (uint8_t)*((char*)(mm->m_runTimeData) + rowsize * i + j);
                printf("%02x ", val);
            }
            printf("\n");
        }
    }
    else
    {
        size_t rowsize = 16;
        for(size_t i = 0; i < size / rowsize; ++i)
        {
            for(size_t j = 0; j < rowsize; ++j)
            {
                auto val = (uint8_t)*((char*)(mm->m_runTimeData) + rowsize * i + j);
                printf("%02x ", val);
            }
            printf("\n");
        }
    }
}