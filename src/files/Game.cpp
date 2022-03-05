#include <SDL.h>
#include <stdio.h>
#include <stdint.h>

#include "Components.hpp"
#include "./ecs/ecs.hpp" 





struct Game_data
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    Registry_data *registry;

    void *runTimeData;
    bool active;
};


namespace GameMemory
{
    T
}




namespace Game
{


void ecs_init()
{
    registry = (Registry_data*)malloc(sizeof(registry));
    if(registry == NULL)
    {
        fprintf(stderr, "ERROR: not enough memory");
        exit(1);
    }

    Registry_functions::init_component<Position>(registry);
    Registry_functions::init_component<Size>(registry);
    Registry_functions::init_component<Velocity>(registry);
    Registry_functions::init_component<Player>(registry);


}


void ecs_clean()
{
    assert(registry != NULL, "Registry is already null");

    free(registry);
    registry = NULL;
}


void sdl_init()
{
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        fprintf(stderr, "ERROR: SDL_INITALIZATION FAILED, %s", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("Space_game", 0, 0, 100, 100, NULL);

    if(!window)
    {
        fprintf(stderr, "ERROR: SDL_CreateWindow FAILED, %s", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, NULL);

    if(!renderer)
    {
        fprintf(stderr, "ERROR: SDL_CreateRenderer FAILED, %s", SDL_GetError());
        exit(1);
    }
}


void sdl_clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);




    SDL_Quit();
}



void init()
{
    ecs_init();
    sdl_init();
    
}


void clean()
{
    sdl_clean();
    ecs_clean();
}


void update()
{



}


void render()
{

    
}


void run()
{


    while(true)
    {
        update();
        render();
    }
}


}
