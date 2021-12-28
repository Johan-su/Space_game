#include "../ecs/ecs.hpp"
#include "../ecs/globals.hpp"
#include "../ecs/ecs_assert.hpp"

#include <string>
#include <cstdint>
#include <iostream>
#include <SDL.h>


typedef uint8_t byte;

template<typename T>
bool isSame(T *first, T *second)
{
    size_t typesize =  sizeof(T);

    auto *fp = (byte*)first;
    auto *sp = (byte*)second;

    bool result = true;

    for(size_t i = 0; i < typesize; ++i)
    {
        if(fp[i] != sp[i])
        {
            result = false;
            break;
        }
    }

    return result;
}


Globaldata _g;


void component_test()
{
//TODO(johan) improve component testing
}


void ecs_test()
{
}

bool ecs_init()
{
    _g.mm = new Memory_pool();
    Memory::init(_g.mm);
    _g.edata = Memory::alloc<Entity_data>(_g.mm);
    _g.compdata = Memory::alloc<Component_data>(_g.mm);
    _g.sysdata = Memory::alloc<System_data>(_g.mm);

   Entity_functions::init(_g.mm, _g.edata);
   Component_functions::init(_g.mm, _g.compdata);
   System_functions::init(_g.mm, _g.sysdata);
   

    return 0;
}
bool ecs_clean()
{

    delete _g.mm;
    return 0;
}
bool init()
{
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
      std::cout << "SDL_INITALIZATION FAILED " << "\n";
      std::cerr << SDL_GetError() << std::endl;
      return 1;
    }

    if(ecs_init())
    {
        return 1;
    }
    return 0;
}
bool clean()
{
    if(ecs_clean())
    {

    }
    return 0;
}




int main(int argc, char *argv[])
{
    int init_exit_code = init();
    std::cout << "init exit code: " << init_exit_code << "\n";
    if(init_exit_code)
    {
        exit(init_exit_code);
    }
    ecs_test();
    component_test();




    int clean_exit_code = 0;//clean();
    std::cout << "clean exit code: " << clean_exit_code << "\n";
    exit(clean_exit_code);
    return 0;
}
















