#include "core.hpp"
#include "../assert.hpp"


#include "../platform/platform.hpp"
#include "Input.hpp"

#include "../Memory_arena.hpp"
#include "../asset/asset.hpp"


#include "../ecs/ecs.hpp"
#include "../int.hpp"
#include "../Renderer/Renderer.hpp"



#include <stdio.h>
#include <limits.h>


const Usize KiB = 1024llu;
const Usize MiB = 1024llu * KiB;
const Usize GiB = 1024llu * MiB;
const Usize TiB = 1024llu * GiB;





static void *reserve_memory_begin;
static void *reserve_memory_end;

global_memory g_memory = {};


void Internal::init_global_memory()
{
    Platform::init();
    reserve_memory_begin = memory_map::reserve(nullptr, Platform::bytes_to_page_amount(10 * TiB)); // 100 TiB
    reserve_memory_end = (char *)reserve_memory_begin + 10 * TiB;

    void *app_buffer_start = reserve_memory_begin;
    Arena::init_top_arena(&g_memory.app_buffer, app_buffer_start, Platform::bytes_to_page_amount(4 * KiB),  Platform::bytes_to_page_amount(2 * MiB)); // 2 MiB

    void *asset_buffer_start = (char *)app_buffer_start + 2 * MiB;
    Arena::init_top_arena(&g_memory.asset_buffer, asset_buffer_start, Platform::bytes_to_page_amount(4 * KiB), Platform::bytes_to_page_amount(10 * MiB));

    void *scratch_buffer_start = (char *)asset_buffer_start + 10 *MiB;
    Arena::init_top_arena(&g_memory.scratch_buffer, scratch_buffer_start, Platform::bytes_to_page_amount(2 * MiB),  Platform::bytes_to_page_amount(2 * MiB)); // 2 MiB

    void *event_buffer_start = (char *)scratch_buffer_start + 2 * MiB;
    Arena::init_top_arena(&g_memory.event_buffer, event_buffer_start, Platform::bytes_to_page_amount(10 * MiB), Platform::bytes_to_page_amount(1 * GiB));

    void *view_buffer_start = (char *)event_buffer_start + 1 * GiB;
    Arena::init_top_arena(&g_memory.view_buffer, view_buffer_start,  Platform::bytes_to_page_amount(10 * MiB),  Platform::bytes_to_page_amount(1 * GiB));


    // scene buffers
    {
        void *base = (char *)reserve_memory_end - 512 * GiB; // 512 GiB from end
        for(int i = 0; i < MAX_SCENE_COUNT; ++i)
        {
            Arena::init_top_arena(&g_memory.scene_buffers[i], (char *)base + i * 16 * GiB, Platform::bytes_to_page_amount(4 * KiB), Platform::bytes_to_page_amount(16 * GiB));
        }
    }
}

void Internal::clean_global_memory()
{
    Arena::clean_arena(&g_memory.app_buffer);
    Arena::clean_arena(&g_memory.asset_buffer);
    Arena::clean_arena(&g_memory.scratch_buffer);
    Arena::clean_arena(&g_memory.view_buffer);
    Arena::clean_arena(&g_memory.event_buffer);

    for (top_memory_arena *ar = g_memory.scene_buffers; ar != (g_memory.scene_buffers + MAX_SCENE_COUNT); ++ar)
    {
        Arena::clean_arena(ar);
    }
}

static void glfw_error_callback(int error, const char *desc)
{
    fprintf(stderr, "ERROR: GLFW %s", desc);
}


static void init_glfw()
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
    {
        fprintf(stderr, "ERROR: failed to initalize glfw");
        exit(1);
    }
}


static void clean_glfw()
{
    glfwTerminate();
}


engine_data *Internal::create_engine(top_memory_arena *arena)
{
    engine_data *engine = Arena::top_alloc<engine_data>(arena);

    engine->config = Arena::top_alloc<config_data>(arena);

    const char *config_path = "./config.ini";
    Internal::init_config(engine->config, config_path);
    init_glfw();
    engine->window = Internal::create_window(engine->config->screen_width, engine->config->screen_height, "Space_game");
    Internal::init_renderer(engine->window);

    Internal::init_input(engine->window);
    Internal::init_asset(engine);

    return engine;
}


void Internal::clean_engine(engine_data *engine) 
{
    engine->config = nullptr;

    // exists because SDL uses its own allocators
    Internal::clean_asset();
    Internal::clean_renderer();
    clean_glfw();

    Internal::clean_global_memory();    
}