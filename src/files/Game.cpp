#include "Components.hpp"
#include "./ecs/ecs.hpp"
#include "../datastructures/hashmap.hpp"
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


game_data *Game::create_game()
{
    return alloc<game_data>();
}



void Game::ecs_init(game_data *game)
{
    game->registry = alloc<Registry_data>();
    Registry_functions::init(game->registry);

    Registry_functions::init_component<Position>(game->registry);
    Registry_functions::init_component<Size>(game->registry);
    Registry_functions::init_component<Velocity>(game->registry);
    Registry_functions::init_component<Player>(game->registry);


}


void Game::ecs_clean(game_data *game)
{
    assert(game->registry != NULL, "Registry is null");

    Registry_functions::clean(game->registry);
    free(game->registry);
    game->registry = NULL;
}


void Game::sdl_init(game_data *game)
{
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        fprintf(stderr, "ERROR: SDL_INITALIZATION FAILED, %s", SDL_GetError());
        exit(1);
    }

    int flags = 0;
    game->window = SDL_CreateWindow("Space Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, flags);
    if(!game->window)
    {
        fprintf(stderr, "ERROR: SDL_CreateWindow FAILED, %s", SDL_GetError());
        exit(1);
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if(!game->renderer)
    {
        fprintf(stderr, "ERROR: SDL_CreateRenderer FAILED, %s", SDL_GetError());
        exit(1);
    }
}


void Game::sdl_clean(game_data *game)
{
    assert(game->renderer, "renderer is NULL");
    assert(game->window, "window is NULL");

    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);


    SDL_Quit();
}



void Game::init(game_data *game)
{
    ecs_init(game);
    sdl_init(game);

    game->active = true;
    
}


void Game::clean(game_data *game)
{
    ecs_clean(game);
    sdl_clean(game);
}


void Game::update(game_data *game)
{


}


void Game::handle_events(game_data *game)
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
                switch(event.key.keysym.sym)
                {
                   /*case SDLK_w:
                    break;
                    case SDLK_a:
                    break;
                    case SDLK_s:
                    break;
                    case SDLK_d:
                    break;*/

                    default:
                    printf("%d\n", event.key.keysym.sym);
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


void Game::render(game_data *game)
{
    SDL_RenderClear(game->renderer);










    SDL_RenderPresent(game->renderer);
}


void Game::run(game_data *game)
{

    while(game->active)
    {
        update(game);
        handle_events(game);
        render(game);
    }
}
