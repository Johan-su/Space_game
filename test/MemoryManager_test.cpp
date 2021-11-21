#include "../src/ecs/MemoryManager.h"
#include "MemoryManager_test.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstdint>

//TODO(johan) Improve testing and make it easier to create new tests.

void init_clean_test(MemoryManager *mm)
{
  std::cout << "init_clean_test:" << std::endl;
  run_and_print(mm->clean(), false);
  run_and_print(mm->init(), true);
  run_and_print(mm->init(), false);
  run_and_print(mm->init(), false);
  run_and_print(mm->clean(), true);
  run_and_print(mm->clean(), false);
  run_and_print(mm->init(), true);
}

void alloc_dealloc_test(MemoryManager *mm)
{
  std::cout << "alloc_dealloc_test:" << std::endl;

  

  
}

void MemoryManager_test()
{
  auto mm = new MemoryManager();
  init_clean_test(mm);
  alloc_dealloc_test(mm);









  delete mm;
  mm = nullptr;
}
