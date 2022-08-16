#pragma once
#include "asset/Texture.hpp"
#include "Config.hpp"

#include "ecs/ecs.hpp"
#include "Memory_arena.hpp"


#include "datastructures/hashmap.hpp"

#define MAX_SCENE_COUNT 32
struct global_memory
{
    top_memory_arena app_buffer; // only gets cleared at app destruction

    top_memory_arena asset_buffer; // only gets cleared at app destruction

    top_memory_arena scratch_buffer; // temporary memory

    top_memory_arena view_buffer; // gets cleared after a game system function

    top_memory_arena event_buffer; // gets cleared after all events have been processed



    top_memory_arena scene_buffers[32]; // buffers used for game scenes
};



struct engine_data
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    
    config_data *config;
};


extern global_memory g_memory;

namespace Internal
{
    void init_global_memory();
    void clean_global_memory();

    engine_data *create_engine(top_memory_arena *arena);
    void clean_engine(engine_data *engine);
}




