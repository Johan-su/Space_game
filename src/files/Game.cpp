#include "Components_Events.hpp"
#include "./ecs/ecs.hpp"
#include "Game.hpp"

#include "assert.hpp"

#include <SDL.h>
#include <stdio.h>
#include <stdint.h>





template<typename T>
T *alloc(size_t amount = 1)
{
    T *mem = (T*)malloc(sizeof(T) * amount);
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



ECS_DECLARE_EVENT(CollisionEvent);
ECS_DECLARE_EVENT(SpawnEvent);


void Game::ecs_init(game_data *game)
{
    game->registry = alloc<Registry_data>();
    Registry_functions::init(game->registry, GameEvents::event_listener);

    Registry_functions::init_component<Position>(game->registry);
    Registry_functions::init_component<Size>(game->registry);
    Registry_functions::init_component<Velocity>(game->registry);
    Registry_functions::init_component<Player>(game->registry);

    ECS_INIT_EVENT(game->registry, CollisionEvent);
    ECS_INIT_EVENT(game->registry, SpawnEvent);


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
    assert(game->renderer, "renderer cannot be NULL");
    assert(game->window, "window cannot be NULL");

    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);

    game->renderer = NULL;
    game->window = NULL;

    SDL_Quit();
}


void Game::texture_init(game_data *game)
{   
    assert(game, "game cannot be null");
    game->texture = alloc<textures_data>();

    Texture::init(game->texture);
}


void Game::texture_clean(game_data *game)
{
    assert(game, "game cannot be null");

    Texture::clean(game->texture);
    free(game->texture);
    game->texture = NULL;
}


void Game::init(game_data *game)
{
    ecs_init(game);
    sdl_init(game);
    texture_init(game);
    
}


void Game::clean(game_data *game)
{
    ecs_clean(game);
    sdl_clean(game);
    texture_clean(game);

}


void Game::load_texture(game_data *game, uint32_t enum_id,  const char *path)
{
    Texture::load_texture(game->renderer, game->texture, enum_id, path);
}


SDL_Texture *Game::get_texture(game_data *game, uint32_t enum_id)
{
    return Texture::get_texture(game->texture, enum_id);
}


void Game::update(game_data *game)
{


}


void Game::render(game_data *game)
{
    SDL_RenderClear(game->renderer);

    SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);

    SDL_RenderDrawLineF(game->renderer, 0.0f, 0.0f, 100.0f, 100.0f);


    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);





    SDL_RenderPresent(game->renderer);
}


void Game::handle_input_events(game_data *game)
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        //printf("event type: %d\n", event.type);
        switch(event.type)
        {
            case SDL_QUIT:
                game->active = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {

                    default:
                        printf("%d\n", event.button.button);
                        break;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                switch(event.button.button)
                {

                    default:
                        printf("%d\n", event.button.button);
                        break;
                }
                break;

            case SDL_MOUSEWHEEL:
                if(event.wheel.y > 0)
                {
                    printf("scroll up: %d\n", event.wheel.y);
                }
                else
                {
                    printf("scroll down: %d\n", event.wheel.y);
                }
                break;

            case SDL_MOUSEMOTION:

                printf("Mouse [ %d, %d ]\n", event.motion.x, event.motion.y);
                
                break;


            //

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




void Game::run(game_data *game)
{
    game->active = true;

    while(game->active)
    {
        handle_input_events(game);
        update(game);
        render(game);
    }
}

void Game::setup_game_state(game_data *game)
{
    
}



void GameEvents::event_listener(size_t eventid, const void *event)
{

    switch (eventid)
    {
        case ECS_ID(CollisionEvent):
        {
            auto *coll_event = (CollisionEvent*)event;
            dbg(printf("event_listener with CollisionEvent val: %lld , %lld\n", coll_event->e1, coll_event->e2));
            break;
        }
        case ECS_ID(SpawnEvent):
        {
            auto *spawn_event = (SpawnEvent*)event;
            dbg(printf("event_listener with SpawnEvent\n val: %f , %f\n", spawn_event->x, spawn_event->y));
            break;
        }
            
        
        default:
            break;
    }
}






Entity Entity_creator::create_player(float x, float y)
{
    return 0;
}


Entity Entity_creator::create_planet(float x, float y)
{
    return 0;
}



