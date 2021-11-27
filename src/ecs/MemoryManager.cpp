#include "MemoryManager.h"
#include <cassert>
#include <iostream>
#include <cstdlib>

typedef uint8_t byte;
MemoryManager::MemoryManager()
    : m_runTimeData(nullptr), m_bytesAllocated(0), m_MemoryActive(false)
{  
}

void MemoryManager::init()
{
  assert(!m_MemoryActive);
  m_runTimeData = malloc(MEMORY_POOL_SIZE);
  m_MemoryActive = true;
}

void MemoryManager::clean()
{
  assert(m_MemoryActive);
  free(m_runTimeData);
  m_runTimeData = nullptr;
  m_MemoryActive = false;
}

void MemoryManager::dump(const size_t size = 512)
{
  assert(m_MemoryActive);
  assert(size < MEMORY_POOL_SIZE);

  size_t rowsize = 16;
  for(size_t i = 0; i < size / rowsize; ++i)
  {
    printf("%p ", ((byte*)(m_runTimeData) + rowsize * i));
    for(size_t j = 0; j < rowsize; ++j)
    {
      printf("%x ", *((byte*)(m_runTimeData) + rowsize * i + j));
    }
    printf("\n");
  }
}
