#include "MemoryManager.h"
#include <cassert>
#include <cstdlib>


MemoryManager::MemoryManager()
    : m_runTimeData(nullptr), m_bytesAllocated(0), m_MemoryActive(false)
{  
}

bool MemoryManager::init()
{
  if(m_MemoryActive) return false;
  m_runTimeData = malloc(MEMORY_POOL_SIZE);
  m_MemoryActive = true;
  return true;
}

bool MemoryManager::clean()
{
  if(!m_MemoryActive) return false;
  free(m_runTimeData);
  m_runTimeData = nullptr;
  m_MemoryActive = false;
  return true;
}

void *MemoryManager::alloc(size_t size)
{
  assert(size + m_bytesAllocated < MEMORY_POOL_SIZE);
  uint64_t tmp = m_bytesAllocated;
  
  m_bytesAllocated += size;
  return (void*)((uint8_t*)(m_runTimeData) + tmp); // C++ forcing this mess
}

void MemoryManager::dealloc(void *pointer, size_t size)
{
  assert(m_bytesAllocated - size > 0);
  assert((uint8_t*)pointer > m_runTimeData);
  assert((uint8_t*)pointer < (uint8_t*)m_runTimeData + MEMORY_POOL_SIZE);
  
  for(size_t i = 0; i < size; ++i)
  {
    *((uint8_t*)(pointer) + i) = 0;
  }

}
