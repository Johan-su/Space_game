#pragma once
#include "../src/ecs/MemoryManager.h"
#include <iostream>
#include <cassert>

//TODO(johan) Improve testing and make it easier to create new tests.
template <typename T, typename... Args>
auto run_and_print(T val, T expectedval)
{
  std::cout << "--- value " << val << " expected value "<< expectedval  << std::endl;
  assert(val == expectedval);
  return val;
}

void init_clean_test(MemoryManager *mm);

void MemoryManager_test();
