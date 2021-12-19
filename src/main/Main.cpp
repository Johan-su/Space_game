#include "../ecs/ecs.h"
#include "../ecs/globals.h"
#include "../ecs/ecs_assert.h"

#include <cstdint>
#include <iostream>
#include <SDL.h>




Globaldata g_data;

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
    
}


void ecs_test()
{

}

bool ecs_init()
{
    //std::cout << "size of mem " << sizeof(MemoryManager) << "\n";
    g_data.mem = new MemoryManager();
    g_data.mem->init();
    g_data.compm = g_data.mem->alloc<ComponentManager>();
    g_data.compm->init(g_data.mem);
    g_data.enm = g_data.mem->alloc<EntityManager>();
    g_data.enm->init(g_data.mem);
    return 0;
}
bool ecs_clean()
{
    g_data.compm->clean(g_data.mem);
    g_data.mem->clean();

    delete g_data.mem;

    g_data.compm = nullptr;
    g_data.mem = nullptr;
    return 0;
}
bool init()
{
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
      std::cout << "SDL_INITALIZATION FAILED " << std::endl;
      std::cout << SDL_GetError() << std::endl;
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

















