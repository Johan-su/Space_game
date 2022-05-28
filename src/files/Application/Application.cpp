#include "Application.hpp"
#include "../platform/deltatime.hpp"
#include "../Input.hpp"
#include "../core.hpp"

struct Application_data
{
    engine_data *engine;
    size_t scene_count;
    scene *scenes[128];
};




Application_handle *Application::create_application(const char *pwd)
{
    
}




static void clean_scene(scene *scene)
{
    Ecs::destroy_registry(scene->registry);
    scene->registry = NULL;
}


void Application::destroy_application(Application_handle *app)
{
    Application_data *app_data = (Application_data *)(app);
    for(int i = 0; i < app_data->scene_count; ++i)
    {
        clean_scene(app_data->scenes[i]);
    }
    free(app_data);
}


scene *create_scene()
{

}


static void handle_input_events(engine_data *engine, float Ts)
{
    Input::handle_input(engine);
}


#define FIXED_UPDATE_FREQUENCY_PER_SEC 60

void Application::run(Application_handle *app, uint16_t scene_id, void (*update_func)(Application_handle *, scene *, float), void (*fixed_update_func)(Application_handle *, scene *, float), void (*render_func)(Application_handle *, scene *, float))
{
    Application_data *app_data = (Application_data *)(app);

    if(scene_id >= app_data->scene_count)
    {
        fprintf(stderr, "ERROR: scene_id out of bounds with value %u", scene_id);
        return;
    }

    app_data->engine->active = true;

    //uint64_t print_timer = 0;
    uint64_t fixed_update_count = 0;
    uint64_t target_time = 1000000 / app_data->engine->config->FPS_target;
    uint64_t target_fixed_update = 1000000 / FIXED_UPDATE_FREQUENCY_PER_SEC;
    
    uint64_t curr;
    uint64_t prev = deltaTime::get_micro_time();
    uint64_t dt; // dt in microseconds 10^-6 seconds
    float ts; // time step in seconds

    while(app_data->engine->active)
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

        handle_input_events(app_data->engine, ts);
        update_func(app, app_data->scenes[scene_id], ts);

        fixed_update_count += dt;
        while(fixed_update_count >= target_fixed_update)
        {
            fixed_update_func(app, app_data->scenes[scene_id], target_fixed_update / 1000000.0f);
            fixed_update_count -= target_fixed_update;
        }

        render_func(app, app_data->scenes[scene_id], ts);

        do
        {
            curr = deltaTime::get_micro_time();
            dt = curr - prev;
        } while(dt < target_time);

    }
}






int Application::RenderCopyExF(Application_handle *app,
                               Texture *texture,
                               const Rect *srcrect,
                               const FRect *dstrect,
                               const double angle,
                               const FPoint *center,
                               const Flip_flag flip)
{
    Application_data *app_data = (Application_data*)app;

    return SDL_RenderCopyExF(app_data->engine->renderer, (SDL_Texture*)texture, (SDL_Rect*)srcrect, (const SDL_FRect*)dstrect, angle, (const SDL_FPoint*)center, (const SDL_RendererFlip)flip);
}


Texture *Application::get_texture(Application_handle *app, uint32_t id)
{
    Application_data *app_data = (Application_data*)app;
    return (Texture*)Texture_functions::get_texture(app_data->engine->texture, id);
}


Texture_Sprite *Application::get_sprite(Application_handle *app, uint32_t id)
{
    Application_data *app_data = (Application_data*)app;
    return (Texture_Sprite*)Texture_functions::get_sprite(app_data->engine->texture, id);
}


bool Application::IsKeyPressed(Application_handle *app, int keyCode)
{
    Application_data *app_data = (Application_data*)app;

    return Hashmap::get_value(app_data->engine->key_map, keyCode);
}
