#define _CRT_SECURE_NO_WARNINGS
#include "Application.hpp"
#include "../platform/platform.hpp"
#include "../Input.hpp"
#include "../core.hpp"
#include "../assert.hpp"
#include "../Memory_arena.hpp"



struct Application_data
{
    engine_data *engine;
    size_t scene_count;
    scene *scenes[MAX_SCENE_COUNT];
};


static bool app_created = false;




Application_data *Application::create_application(const char *pwd)
{
    if(app_created)
    {
        fprintf(stderr, "ERROR: tried to create application while already existing");
        exit(1);
    }
    app_created = true;

    Real::init_global_memory();

    


    Application_data *app_data = Arena::top_alloc<Application_data>(&g_memory.app_buffer);
    memset(app_data, 0, sizeof(*app_data));

    app_data->engine = Real::create_engine(&g_memory.app_buffer, pwd);

    app_data->engine->active = false;


    return app_data;
}


void Application::destroy_application(Application_data *app)
{
    for(int i = 0; i < MAX_SCENE_COUNT; ++i)
    {
        Arena::clean_arena(&g_memory.scene_buffers[i]);
    }
    Real::clean_engine(app->engine);

    Arena::clean_arena(&g_memory.app_buffer);
}


scene *Application::create_add_scene(Application_data *app, const char *scene_name = "unnamed_scene")
{

    int scene_pos = -1;

    // get unoccupied scene position in app
    for(int i = 0; i < MAX_SCENE_COUNT; ++i)
    {
        if(app->scenes[i] == NULL)
        {
            scene_pos = i;
            break;
        }
    }

    if(scene_pos != -1)
    {
        scene *game_scene = Arena::top_alloc<scene>(&g_memory.scene_buffers[scene_pos]);
        game_scene->registry = Arena::top_alloc<Ecs::Registry>(&g_memory.scene_buffers[scene_pos]);

        Ecs::init(game_scene->registry, &g_memory.scene_buffers[scene_pos], &g_memory.view_buffer);
        Camera_functions::init(&game_scene->camera, app->engine->config->screen_width, app->engine->config->screen_height);
        
        
        game_scene->name = "scene_name";
        app->scenes[scene_pos] = game_scene;
    }
    else
    {
        fprintf(stderr, "ERROR: failed to create scene, max scene amount %d reached\n", MAX_SCENE_COUNT);
        exit(1);
    }


    return app->scenes[scene_pos];
}


scene *Application::get_scene_by_name(Application_data *app, const char *scene_name)
{
    scene *scene = NULL;
    for(int i = 0; i < MAX_SCENE_COUNT; ++i)
    {
        if(strcmp(app->scenes[i]->name, scene_name) == 0)
        {
            break;
        }
    }

    if(scene == NULL)
    {
        fprintf(stderr, "WARNING: failed to find scene by name");
    }
    return scene;
}



static void handle_input_events(engine_data *engine, float Ts)
{
    Input::handle_input(engine);
}



#define FIXED_UPDATE_FREQUENCY_PER_SEC 60

void Application::run(Application_data *app, scene *scene, void (*update_func)(Application_data *, struct scene *, float), void (*fixed_update_func)(Application_data *, struct scene *, float), void (*render_func)(Application_data *, struct scene *, float))
{

    if(scene == NULL)
    {
        fprintf(stderr, "ERROR: scene cannot be NULL\n");
        return;
    }

    app->engine->active = true;

    uint64_t print_timer = 0;
    uint64_t fixed_update_count = 0;
    uint64_t target_time = 1000000 / app->engine->config->FPS_target;
    uint64_t target_fixed_update = 1000000 / FIXED_UPDATE_FREQUENCY_PER_SEC;
    
    uint64_t curr;
    uint64_t prev = deltaTime::get_micro_time();
    uint64_t dt; // dt in microseconds 10^-6 seconds
    float ts; // time step in seconds

    while(app->engine->active)
    {
        curr = deltaTime::get_micro_time();
        dt = curr - prev;
        prev = curr;


        
        print_timer += dt;
        if(print_timer > 1000000)
        {
            printf("fps: %-7.1f frametime: %f\n", 1000000.0f / dt, dt / 1000000.0f);
            print_timer -= 1000000;
        }
        
        ts = dt / 1000000.0f;

        handle_input_events(app->engine, ts);
        update_func(app, scene, ts);

        fixed_update_count += dt;
        while(fixed_update_count >= target_fixed_update)
        {
            fixed_update_func(app, scene, target_fixed_update / 1000000.0f);
            fixed_update_count -= target_fixed_update;
        }

        // begin render

        SDL_RenderClear(app->engine->renderer);
    

        SDL_SetRenderDrawColor(app->engine->renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(app->engine->renderer, (app->engine->config->screen_width / 2), (app->engine->config->screen_height / 2));
        SDL_SetRenderDrawColor(app->engine->renderer, 0, 0, 0, 255);
        render_func(app, scene, ts);

        SDL_RenderPresent(app->engine->renderer);

        // end render


        do
        {
            curr = deltaTime::get_micro_time();
            dt = curr - prev;
        } while(dt < target_time);

    }
}


int Application::RenderCopyExF(Application_data *app,
                               Texture *texture,
                               const Rect *srcrect,
                               const FRect *dstrect,
                               const double angle,
                               const FPoint *center,
                               const Flip_flag flip)
{

    return SDL_RenderCopyExF(app->engine->renderer, (SDL_Texture*)texture, (SDL_Rect*)srcrect, (const SDL_FRect*)dstrect, angle, (const SDL_FPoint*)center, (const SDL_RendererFlip)flip);
}



void Application::load_texture(Application_data *app, uint32_t id, const char *path)
{
    Texture_functions::load_texture(app->engine->renderer, app->engine->texture, id, path);
}


void Application::init_sprite(Application_data *app, uint32_t sprite_id, uint32_t texture_id, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
    Texture_functions::init_sprite(app->engine->texture, sprite_id, texture_id, x, y, w, h);
}



Texture *Application::get_texture(Application_data *app, uint32_t id)
{
    return (Texture*)Texture_functions::get_texture(app->engine->texture, id);
}


Texture_Sprite *Application::get_sprite(Application_data *app, uint32_t id)
{
    return (Texture_Sprite*)Texture_functions::get_sprite(app->engine->texture, id);
}


bool Application::IsKeyPressed(Application_data *app, int keyCode)
{
    return Hashmap::get_value(app->engine->key_map, keyCode);
}


char *Application::cat_string(const char *str1, const char *str2) //TODO(Johan) change to not use C string functions
{
    char *buf = (char *)Arena::top_alloc_bytes(&g_memory.scratch_buffer, strlen(str1) + strlen(str2) + 10, 1);

    strcpy(buf, str1);
    strcat(buf, str2);

    return buf;
}


void Application::clear_view_buffer()
{
    Arena::clear_top_arena(&g_memory.view_buffer);
}
