#include "core.hpp"
#include "assert.hpp"
#include "Camera.hpp"


#include "/platform/deltatime.hpp"
#include "Input.hpp"


#include "/ecs/ecs.hpp"

#include <SDL.h>

#include <string>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>




#define FIXED_UPDATE_FREQUENCY_PER_SEC 60

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


engine_handle *Real::create_context()
{
    return (engine_handle*)alloc<engine_data>();
}


static void sdl_init(engine_data *game)
{
    assert(game, "Game cannot be null");

    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        fprintf(stderr, "ERROR: SDL_INITALIZATION FAILED, %s", SDL_GetError());
        exit(1);
    }

    int flags = 0;
    game->window = SDL_CreateWindow("Space Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game->config->screen_width, game->config->screen_height, flags);
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


static void sdl_clean(engine_data *engine)
{
    assert(engine, "engine cannot be NULL");
    assert(engine->renderer, "renderer cannot be NULL");
    assert(engine->window, "window cannot be NULL");

    SDL_DestroyRenderer(engine->renderer);
    SDL_DestroyWindow(engine->window);

    engine->renderer = NULL;
    engine->window = NULL;

    SDL_Quit();
}


void Real::init(engine_data *engine, const char *pwd)
{
    engine->config = alloc<config_data>();
    std::string config_path = std::string(pwd) + "/config.ini";
    Config::init(engine->config, config_path.c_str());


    sdl_init(engine);

    engine->texture = alloc<textures_data>();
    Texture::init(engine->texture);


    engine->key_map = alloc<hash_map<bool>>();
    engine->mouse_map = alloc<hash_map<bool>>();

    Hashmap::init(engine->key_map);
    Hashmap::init(engine->mouse_map);

}


void Real::clean(engine_data *engine)
{
    Config::clean(engine->config);
    free(engine->config);
    engine->config = NULL;

    sdl_clean(engine);

    Texture::clean(engine->texture);
    free(engine->texture);
    engine->texture = NULL;
    

    free(engine->key_map);
    free(engine->mouse_map);

    engine->key_map = NULL;
    engine->mouse_map = NULL;
}


static void update(engine_data *engine, float Ts, void* func)
{

}


static void fixed_update(engine_data *engine, float Ts, void* func)
{

}


static void render(engine_data *engine, float Ts, void* func)
{
    SDL_RenderClear(engine->renderer);
    


    SDL_SetRenderDrawColor(engine->renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(engine->renderer, (engine->config->screen_width / 2), (engine->config->screen_height / 2));
    SDL_SetRenderDrawColor(engine->renderer, 0, 0, 0, 255);




    SDL_RenderPresent(engine->renderer);
}




static void handle_input_events(engine_data *game, float Ts) //TODO(Johan) move to different file
{
    Input::handle_input(game);
}


void Real::run(engine_data *engine)
{
    engine->active = true;
    
    //uint64_t print_timer = 0;
    uint64_t fixed_update_count = 0;
    uint64_t target_time = 1000000 / engine->config->FPS_target;
    uint64_t target_fixed_update = 1000000 / FIXED_UPDATE_FREQUENCY_PER_SEC;
    
    uint64_t curr;
    uint64_t prev = deltaTime::get_micro_time();
    uint64_t dt; // dt in microseconds 10^-6 seconds
    float ts; // time step in seconds

    while(engine->active)
    {
        curr = deltaTime::get_micro_time();
        dt = curr - prev;
        prev = curr;


        /*
        print_timer += dt;
        if(print_timer > 1000000)
        {
            printf("count %-5llu fps: %-7.1f frametime: %f\n", count, 1000000.0f / dt, dt / 1000000.0f);
            print_timer -= 1000000;
        }
        */
        ts = dt / 1000000.0f;

        handle_input_events(engine, ts);
        update(engine, ts, NULL);

        fixed_update_count += dt;
        while(fixed_update_count >= target_fixed_update)
        {
            fixed_update(engine, target_fixed_update / 1000000.0f, NULL);
            fixed_update_count -= target_fixed_update;
        }

        render(engine, ts, NULL);

        do
        {
            curr = deltaTime::get_micro_time();
            dt = curr - prev;
        } while(dt < target_time);

    }
}











