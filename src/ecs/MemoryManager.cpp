#include "MemoryManager.hpp"
#include "ecs_assert.hpp"
#include <iostream>
#include <cstdlib>

typedef uint8_t byte;

void Memory::init(Memory_pool *mm)
{
  assert(!mm->m_MemoryActive, "Memory pool already active");
  mm->m_runTimeData = malloc(MEMORY_POOL_SIZE);
  mm->m_MemoryActive = true;
}

void Memory::clean(Memory_pool *mm)
{
  assert(mm->m_MemoryActive, "Memory pool already inactive");
  free(mm->m_runTimeData);
  mm->m_runTimeData = nullptr;
  mm->m_MemoryActive = false;
}

void Memory::dump(Memory_pool *mm, const size_t size = 512)
{
  assert(mm->m_MemoryActive, "uninitalized memory pool");
  assert(size < MEMORY_POOL_SIZE, "Dump size greater than pool size");

  size_t rowsize = 16;
  for(size_t i = 0; i < size / rowsize; ++i)
  {
    printf("%p ", ((byte*)(mm->m_runTimeData) + rowsize * i));
    for(size_t j = 0; j < rowsize; ++j)
    {
      printf("%x ", *((byte*)(mm->m_runTimeData) + rowsize * i + j));
    }
    printf("\n");
  }
}
