#pragma once
#include "ecs_constants.h"
#include "ecs_assert.h"
#include <cstdint>
#include <cstdlib>
#include <cstddef>
typedef uint8_t byte;



class MemoryManager
{
public:

  MemoryManager();
  
  void init();

  void clean();

  void dump(const size_t size);
  
template <typename T>  
  T *alloc(const size_t amount = 1)
  {
    assert(amount > 0, "Cannot allocate 0 bytes");
    assert(m_MemoryActive, "Inactive memory pool");
    const size_t type_size = sizeof(T);
    assert(type_size * amount + m_bytesAllocated < MEMORY_POOL_SIZE, "Out of memory");
  
    uint64_t tmp = m_bytesAllocated;
    m_bytesAllocated += type_size * amount;
    
    return (T*)(((byte*)(m_runTimeData))+ tmp); // C++ forcing this mess
  }
  
template <typename T>
  void dealloc(T *pointer, const size_t amount = 1)
  {
    assert(amount > 0, "Cannot deallocate 0 bytes");
    assert(m_MemoryActive, "Inactive memory pool");
    const size_t size = sizeof(T);
    
    assert(m_bytesAllocated - size * amount > 0, "Deallocation outside memory pool");
    
    assert(pointer >= m_runTimeData, "Pointer outside memory pool");
    assert((byte*)pointer < (byte*)m_runTimeData + MEMORY_POOL_SIZE, "Pointer outside memory pool");
  
    for(size_t i = 0; i < size * amount; ++i)
    {
      *((byte*)(pointer) + i) = 0;
    }
  }
  

private:
  
  void *m_runTimeData;

  uint64_t m_bytesAllocated;
  
  bool m_MemoryActive;

};



