#include "Components.hpp"
#include "./ecs/ecs.hpp"
#include "Game.hpp"

#include <SDL.h>
#include <stdio.h>
#include <stdint.h>

template<typename T>
T *alloc(size_t amount = 1)
{
    T *mem = (T *)malloc(sizeof(T) * amount);
    if(mem == NULL)
    {
        fprintf(stderr, "ERROR: not enough memory");
        exit(1);
    }
    return mem;
}


Game_data *Game::create_game()
{
    return alloc<Game_data>();
}



void Game::ecs_init(Registry_data *registry)
{
    registry = alloc<Registry_data>();
    Registry_functions::init(registry);

    Registry_functions::init_component<Position>(registry);
    Registry_functions::init_component<Size>(registry);
    Registry_functions::init_component<Velocity>(registry);
    Registry_functions::init_component<Player>(registry);


}


void Game::ecs_clean(Registry_data *registry)
{
    assert(registry != NULL, "Registry is null");

    Registry_functions::clean(registry);
    free(registry);
    registry = NULL;
}


void Game::sdl_init(SDL_Renderer *renderer, SDL_Window *window)
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


void Game::sdl_clean(SDL_Renderer *renderer, SDL_Window *window)
{
    assert(renderer, "renderer is NULL");
    assert(window, "window is NULL");

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);




    SDL_Quit();
}



void Game::init(Game_data *game)
{
    ecs_init(game->registry);
    sdl_init(game->renderer, game->window);

    game->active = true;
    
}


void Game::clean(Game_data *game)
{
    ecs_clean(game->registry);
    sdl_clean(game->renderer, game->window);
}


void Game::update(Game_data *game)
{


}


void Game::handle_events(Game_data *game)
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                game->active = false;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) //TODO(johan) implemented hash table for keys
                {
                    case SDLK_w:
                    break;
                    case SDLK_a:
                    break;
                    case SDLK_s:
                    break;
                    case SDLK_d:
                    break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_w:
                    break;
                    case SDLK_a:
                    break;
                    case SDLK_s:
                    break;
                    case SDLK_d:
                    break;
                }
                break;
        }
    }

}


void Game::render(Game_data *game)
{
    
}


void Game::run(Game_data *game)
{

    while(game->active)
    {
        update(game);
        handle_events(game);
        render(game);
    }
}
