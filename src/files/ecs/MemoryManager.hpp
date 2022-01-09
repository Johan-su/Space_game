#pragma once
#include "ecs_constants.hpp"
#include "ecs_assert.hpp"

struct Memory_pool
{
  void *m_runTimeData;
  uint64_t m_bytesAllocated;
  
  bool m_MemoryActive;

};

namespace Memory
{




  void init(Memory_pool *mm);

  void clean(Memory_pool *mm);

  void dump(Memory_pool *mm,  const size_t size, bool addr);
  
//TODO(johan) move header functions too cpp file

template <typename T>  
  T *alloc(Memory_pool *mm, size_t amount);
  
template <typename T>
  void dealloc(Memory_pool *mm, T *pointer, size_t amount);
  

}