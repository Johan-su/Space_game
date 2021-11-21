#pragma once
#include <cstdint>
#include <cstddef>



const uint64_t MEMORY_POOL_SIZE = 1024 * 1024;

class MemoryManager
{
 public:

  MemoryManager();
  
  bool init();

  bool clean();
  
  void *alloc(size_t size);

  void dealloc(void *pointer, size_t size);

  

 private:
  
  void *m_runTimeData;

  uint64_t m_bytesAllocated;
  
  bool m_MemoryActive;

};



