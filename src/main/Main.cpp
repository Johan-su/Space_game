#include "../ecs/ecs.hpp"
#include "../ecs/globals.hpp"
#include "../ecs/Registry.hpp"
#include "../ecs/ecs_assert.hpp"

#include <cstdint>
#include <iostream>
#include <SDL.h>


typedef byte uint8_t;

template<typename T>
bool isSame(T first, T second)
{
    size_t typesize =  sizeof(T);

    auto *fp = (byte*)&first;
    auto *sp = (byte*)&second;

    bool result = true;

    for(size_t i = 0; i < typesize; ++i)
    {
        if(*fp != *sp)
        {
            result = false;
            break;
        }
    }

    return result;
}


Globaldata glo;

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
    Entity e =  glo.reg->create_entity();
    auto pc = PositionComponent();
    pc = {420.0f, 69.0f};
    glo.reg->set_component(e, pc);

    auto pc1 = glo.reg->get_component<PositionComponent>(e);

    bool test = isSame<PositionComponent>(pc, pc1);
    std::cout << "pc == pc1: " << test << "\n";

}


void ecs_test()
{
}

bool ecs_init()
{
    glo.reg = new Registry();

    if(glo.reg->init())
    {
        return 1;
    }
    return 0;
}
bool ecs_clean()
{
    glo.reg->clean();

    delete glo.reg;
    glo.reg = nullptr;

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
    //ecs_test();
    component_test();




    int clean_exit_code = clean();
    std::cout << "clean exit code: " << clean_exit_code << "\n";
    exit(clean_exit_code);
    return 0;
}
















