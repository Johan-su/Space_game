#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[])
{
  std::cout << "Hello, World" << std::endl;
  if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
  {
    std::cout << "SDL_INITALIZATION FAILED" << std::endl;
    std::cout << SDL_GetError() << std::endl;
    exit(1);
  }



  return 0;
}
