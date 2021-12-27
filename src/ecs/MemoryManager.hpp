#pragma once
#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
#include <cstdint>
#include <cstdlib>
#include <cstddef>

struct Memory_pool
{
  void *m_runTimeData;
  uint64_t m_bytesAllocated;
  
  bool m_MemoryActive;

};

namespace Memory {


typedef uint8_t byte;



  void init(Memory_pool *mm);

  void clean(Memory_pool *mm);

  void dump(Memory_pool *mm,  const size_t size);
  
template <typename T>  
  T *alloc(Memory_pool *mm, const size_t amount = 1)
  {
    assert(amount > 0, "Cannot allocate 0 bytes");
    assert(mm->m_MemoryActive, "Inactive memory pool");
    const size_t type_size = sizeof(T);
    assert(type_size * amount + mm->m_bytesAllocated < MEMORY_POOL_SIZE, "Out of memory");
  
    uint64_t tmp = mm->m_bytesAllocated;
    mm->m_bytesAllocated += type_size * amount;
    
    return (T*)(((byte*)(mm->m_runTimeData))+ tmp); // C++ forcing this mess
  }
  
template <typename T>
  void dealloc(Memory_pool *mm, T *pointer, const size_t amount = 1)
  {
    assert(amount > 0, "Cannot deallocate 0 bytes");
    assert(mm->m_MemoryActive, "Inactive memory pool");
    const size_t size = sizeof(T);
    
    assert(mm->m_bytesAllocated - size * amount > 0, "Deallocation outside memory pool");
    
    assert(pointer >= mm->m_runTimeData, "Pointer outside memory pool");
    assert((byte*)pointer < (byte*)mm->m_runTimeData + MEMORY_POOL_SIZE, "Pointer outside memory pool");
  
    for(size_t i = 0; i < size * amount; ++i)
    {
      *((byte*)(pointer) + i) = 0;
    }
  }
  

}