#include "../ecs/ecs.h"


#include <cstdint>
#include <iostream>
#include <SDL.h>


void mem_test()
{
  auto mm = new MemoryManager();
  mm->init();
  //char *data = mm->alloc<char>();
  auto *data = mm->alloc<uint8_t>(1000);
  for(int i = 0; i < 1000; ++i)
  {
    *(data + i) = i;
  }
  //printf("%d \n", data[4]);

  //mm->dealloc<int>(data);
  
  mm->dump(1000);











  mm->clean();
  delete mm;
  mm = nullptr;
}


void component_test()
{
  auto mm = new MemoryManager();
  mm->init();
  std::cout <<" sizeof " << sizeof(Component_data) << std::endl;
  auto cd = mm->alloc<Component_data>();

  for(int i = 0; i < 50; ++i)
  {
   *((uint8_t*)(cd) + i) = i;
  }
  mm->dump(100);









  mm->clean();
  delete mm;
  mm = nullptr;
}



int main(int argc, char *argv[])
{
  // std::cout << "Hello, World" << std::endl;
  if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
  {
    std::cout << "SDL_INITALIZATION FAILED " << std::endl;
    std::cout << SDL_GetError() << std::endl;
    exit(1);
  }

  //mem_test();
  component_test();
  return 0;
}

















