#pragma once
#include "../Config.hpp"

#include "../ecs.hpp"
#include "../Memory_arena.hpp"
#include "window.hpp"

#include "../datastructures/hashmap.hpp"


#define MAX_SCENE_COUNT 32
struct global_memory
{
    Memory_arena app_buffer; // only gets cleared at app destruction

    Memory_arena asset_buffer; // only gets cleared at app destruction

    Memory_arena scratch_buffer; // temporary memory

    Memory_arena view_buffer; // gets cleared after a game system function

    Memory_arena event_buffer; // gets cleared after all events have been processed



    Memory_arena scene_buffers[32]; // buffers used for game scenes
};



struct engine_data
{
    // SDL_Renderer *renderer;
    Window *window;
    
    config_data *config;
};


extern global_memory g_memory;

namespace Internal
{
    void init_global_memory();
    void clean_global_memory();

    engine_data *create_engine(Memory_arena *arena);
    void clean_engine(engine_data *engine);
}




