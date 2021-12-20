#include "../ecs/ecs.hpp"
#include "../ecs/globals.hpp"
#include "../ecs/Registry.hpp"
#include "../ecs/ecs_assert.hpp"

#include <string>
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
        if(fp[i] != sp[i])
        {
            result = false;
            break;
        }
    }

    return result;
}


Globaldata glo;


#define TEST_ARRAY_SIZE 10

void component_test()
{
    Entity elist[TEST_ARRAY_SIZE];
    for(int i = 0; i < TEST_ARRAY_SIZE; ++i)
    {
        elist[i] = glo.reg->create_entity();
    }

    PositionComponent plist[TEST_ARRAY_SIZE];
    for(int i = 0; i < TEST_ARRAY_SIZE; ++i)
    {
        plist[i] = {420.0f + (float)i, 69.0f + (float)i};
        glo.reg->set_component(elist[i], plist[i]);
    }

    PositionComponent prlist[TEST_ARRAY_SIZE];
    for(int i = 0; i < TEST_ARRAY_SIZE; ++i)
    {
        prlist[i] = glo.reg->get_component<PositionComponent>(elist[i]);
        assert(isSame(plist[i], prlist[i]), "p" + std::to_string(i) + "==pr" + std::to_string(i) + " does not match");
    }

//TODO(johan) improve component testing


    for(int i = 0; i < TEST_ARRAY_SIZE; ++i)
    {
        assert(isSame(plist[i], prlist[i]), "p" + std::to_string(i) + "==pr" + std::to_string(i) + " does not match");
    }    

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
















