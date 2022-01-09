#include "MemoryManager.hpp"
#include "ecs_assert.hpp"
#include <cstring>

void Memory::init(Memory_pool *mm)
{
  assert(!mm->m_MemoryActive, "Memory pool already active");
  mm->m_runTimeData = malloc(MEMORY_POOL_SIZE);
  memset(mm->m_runTimeData, 0, MEMORY_POOL_SIZE);
  mm->m_MemoryActive = true;
}

void Memory::clean(Memory_pool *mm)
{
  assert(mm->m_MemoryActive, "Memory pool already inactive");
  free(mm->m_runTimeData);
  mm->m_runTimeData = nullptr;
  mm->m_MemoryActive = false;
}

void Memory::dump(Memory_pool *mm, const size_t size = 512, bool addr = true)
{
  assert(mm->m_MemoryActive, "uninitalized memory pool");
  assert(size < MEMORY_POOL_SIZE, "Dump size greater than pool size");

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


template <typename T>  
T *Memory::alloc(Memory_pool *mm, size_t amount) //TODO(johan) fix, memory alignment
{
    assert(amount > 0, "Cannot allocate 0 bytes");
    assert(mm->m_MemoryActive, "Inactive memory pool");
    const size_t type_size = sizeof(T);
    assert(type_size * amount + mm->m_bytesAllocated < MEMORY_POOL_SIZE, "Out of memory");
  
    uint64_t tmp = mm->m_bytesAllocated;
    mm->m_bytesAllocated += type_size * amount;
    
    return (T*)(((char*)(mm->m_runTimeData))+ tmp); // C++ forcing this mess
}



template <typename T>
void Memory::dealloc(Memory_pool *mm, T *pointer, size_t amount)
{
    assert(amount > 0, "Cannot deallocate 0 bytes");
    assert(mm->m_MemoryActive, "Inactive memory pool");
    const size_t size = sizeof(T);
    
    assert(mm->m_bytesAllocated - size * amount > 0, "Deallocation outside memory pool");
    
    assert(pointer >= mm->m_runTimeData, "Pointer outside memory pool");
    assert((char*)pointer < (char*)mm->m_runTimeData + MEMORY_POOL_SIZE, "Pointer outside memory pool");
  
    for(size_t i = 0; i < size * amount; ++i)
    {
        *((char*)(pointer) + i) = 0;
    }
}
  
