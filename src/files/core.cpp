#include "core.hpp"
#include "assert.hpp"
#include "Camera.hpp"


#include "platform/platform.hpp"
#include "Input.hpp"

#include "Memory_arena.hpp"

#include "ecs/ecs.hpp"

#include <SDL.h>

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define KiB 1024llu
#define MiB 1024llu * KiB
#define GiB 1024llu * MiB
#define TiB 1024llu * GiB





static void *reserve_memory_begin;
static void *reserve_memory_end;

global_memory g_memory = {};


void Real::init_global_memory()
{
    Platform::init();
    reserve_memory_begin = memory_map::reserve(NULL, Platform::bytes_to_page_amount(10 * TiB)); // 100 TiB
    reserve_memory_end = (char *)reserve_memory_begin + 10 * TiB;

    void *app_buffer_start = reserve_memory_begin;
    Arena::init_top_arena(&g_memory.app_buffer, app_buffer_start, 4 * KiB, 2 * MiB); // 2 MiB

    void *scratch_buffer_start = (char *)app_buffer_start + 2 * MiB;
    Arena::init_top_arena(&g_memory.scratch_buffer, scratch_buffer_start, 2 * MiB, 2 * MiB); // 2 MiB


    void *view_buffer_start = (char *)scratch_buffer_start + 2 * MiB;
    Arena::init_top_arena(&g_memory.view_buffer, view_buffer_start, 10 * MiB, 1 * GiB);






    // scene buffers
    {
        void *base = (char *)reserve_memory_end - 512 * GiB; // 512 GiB from end
        for(int i = 0; i < MAX_SCENE_COUNT; ++i)
        {
            Arena::init_top_arena(&g_memory.scene_buffers[i], (char *)base + i * 16 * GiB, Platform::bytes_to_page_amount(4 * KiB), Platform::bytes_to_page_amount(16 * GiB));
        }
    }

}


static void sdl_init(engine_data *engine)
{
    assert(engine, "Game cannot be null");

    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        fprintf(stderr, "ERROR: SDL_INITALIZATION FAILED, %s", SDL_GetError());
        exit(1);
    }

    int flags = 0;
    engine->window = SDL_CreateWindow("Space Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, engine->config->screen_width, engine->config->screen_height, flags);
    if(!engine->window)
    {
        fprintf(stderr, "ERROR: SDL_CreateWindow FAILED, %s", SDL_GetError());
        exit(1);
    }

    engine->renderer = SDL_CreateRenderer(engine->window, -1, SDL_RENDERER_ACCELERATED);
    if(!engine->renderer)
    {
        fprintf(stderr, "ERROR: SDL_CreateRenderer FAILED, %s", SDL_GetError());
        exit(1);
    }
}


static void sdl_clean(engine_data *engine)
{
    SDL_DestroyRenderer(engine->renderer);
    SDL_DestroyWindow(engine->window);

    engine->renderer = NULL;
    engine->window = NULL;
}


engine_data *Real::create_engine(top_memory_arena *arena, const char *pwd)
{
    engine_data *engine = Arena::top_alloc<engine_data>(arena);

    engine->config = Arena::top_alloc<config_data>(arena);

    Arena::clear_top_arena(&g_memory.scratch_buffer);

    char *config_path = (char *)Arena::top_alloc_bytes(&g_memory.scratch_buffer, 500, 1);

    strcpy(config_path, pwd);
    strcat(config_path, "/config.ini");

    Config::init(engine->config, config_path);




    sdl_init(engine);

    engine->texture = Arena::top_alloc<textures_data>(arena);
    Texture_functions::init(engine->texture);


    engine->key_map = Arena::top_alloc<hash_map<bool>>(arena);
    engine->mouse_map = Arena::top_alloc<hash_map<bool>>(arena);

    Hashmap::init(engine->key_map);
    Hashmap::init(engine->mouse_map);


    return engine;

}


void Real::clean_engine(engine_data *engine) // exists because SDL uses its own allocators
{
    engine->config = NULL;

    sdl_clean(engine);

    Texture_functions::clean(engine->texture);
    engine->texture = NULL;

    engine->key_map = NULL;
    engine->mouse_map = NULL;
}




