#define _CRT_SECURE_NO_WARNINGS
#include "Application.hpp"
#include "../platform/platform.hpp"
#include "../input/Input.hpp"
#include "../core.hpp"
#include "../assert.hpp"
#include "../Memory_arena.hpp"
#include "../scene/component.hpp"
#include "../scene/Camera.hpp"


struct Application_data
{
    engine_data *engine;
    size_t scene_count;
    scene *scenes[MAX_SCENE_COUNT];

    bool active;

};

Application_data *Application::n_app_instance = NULL;






Application_data *Application::create_application(const char *pwd)
{
    if (n_app_instance != NULL)
    {
        fprintf(stderr, "ERROR: tried to create application while an application already exists");
        exit(1);
    }

    Internal::init_global_memory();

    


    n_app_instance = Arena::top_alloc<Application_data>(&g_memory.app_buffer);
    memset(n_app_instance, 0, sizeof(*n_app_instance));

    n_app_instance->engine = Internal::create_engine(&g_memory.app_buffer, pwd);

    n_app_instance->active = false;


    return n_app_instance;
}


void Application::destroy_application(Application_data *app)
{
    for(int i = 0; i < MAX_SCENE_COUNT; ++i)
    {
        Arena::clean_arena(&g_memory.scene_buffers[i]);
    }
    Internal::clean_engine(app->engine);

    Arena::clean_arena(&g_memory.app_buffer);

    n_app_instance = NULL;
}


scene *Application::create_add_scene(const char *scene_name = "unnamed_scene")
{
    Application_data *app = Application::Get();
    int scene_pos = -1;

    // get unoccupied scene position in app
    for (int i = 0; i < MAX_SCENE_COUNT; ++i)
    {
        if (app->scenes[i] == NULL)
        {
            scene_pos = i;
            break;
        }
    }

    if (scene_pos != -1)
    {
        scene *game_scene = Arena::top_alloc<scene>(&g_memory.scene_buffers[scene_pos]);

        Ecs::init(&game_scene->registry, &g_memory.scene_buffers[scene_pos], &g_memory.view_buffer, &g_memory.event_buffer);

        Ecs::init_component<Transform>(&game_scene->registry);
        Ecs::init_component<CameraComponent>(&game_scene->registry);
        Ecs::init_component<Velocity>(&game_scene->registry);
        Ecs::init_component<SpriteComponent>(&game_scene->registry);
        Ecs::init_component<BoxCollider>(&game_scene->registry);
        Ecs::init_component<CircleCollider>(&game_scene->registry);

        {
            Transform camera_transform = {};
            CameraComponent camera_comp = {};

            Real::init_camera(&camera_transform, &camera_comp, true, app->engine->config->screen_width, app->engine->config->screen_height);

            Entity main_camera = Ecs::create_entity(&game_scene->registry);
            Ecs::set_component<Transform>(&game_scene->registry, main_camera, camera_transform);
            Ecs::set_component<CameraComponent>(&game_scene->registry, main_camera, camera_comp);

        }

        
        game_scene->name = "scene_name";
        app->scenes[scene_pos] = game_scene;
        ++app->scene_count;
    }
    else
    {
        fprintf(stderr, "ERROR: failed to create scene, max scene amount %d reached\n", MAX_SCENE_COUNT);
        exit(1);
    }


    return app->scenes[scene_pos];
}


scene *Application::get_scene_by_name(const char *scene_name)
{
    Application_data *app = Application::Get();
    scene *scene = NULL;
    for(int i = 0; i < MAX_SCENE_COUNT; ++i)
    {
        if (strcmp(app->scenes[i]->name, scene_name) == 0)
        {
            scene = app->scenes[i];
            break;
        }
    }

    if (scene == NULL)
    {
        fprintf(stderr, "WARNING: failed to find scene by name");
    }
    return scene;
}



static void handle_input_events()
{
    Internal::handle_input();
}



#define FIXED_UPDATE_FREQUENCY_PER_SEC 60

void Application::run(Application_data *app, scene *scene)
{

    if (scene == NULL)
    {
        fprintf(stderr, "ERROR: scene cannot be NULL\n");
        return;
    }

    app->active = true;

    U64 print_timer = 0;
    U64 fixed_update_count = 0;
    U64 target_time = 1000000 / app->engine->config->FPS_target;
    U64 target_fixed_update = 1000000 / FIXED_UPDATE_FREQUENCY_PER_SEC;
    
    U64 curr;
    U64 prev = deltaTime::get_micro_time();
    U64 dt; // dt in microseconds 10^-6 seconds
    float ts; // time step in seconds

    while (app->active)
    {
        curr = deltaTime::get_micro_time();
        dt = curr - prev;
        prev = curr;
      


        print_timer += dt;
        if (print_timer > 1000000)
        {
            printf("fps: %-7.1f frametime: %f\n", 1000000.0f / dt, dt / 1000000.0f);
            print_timer -= 1000000;
        }
        
        ts = dt / 1000000.0f;

        handle_input_events();
        

        fixed_update_count += dt;
        while (fixed_update_count >= target_fixed_update)
        {
            // TODO(Johan): figure out a way to do fixed_update for certain systems
            fixed_update_count -= target_fixed_update;
        }

        // begin render
        SDL_RenderClear(app->engine->renderer);
    
        Ecs::progress_systems(&scene->registry, ts);

        SDL_SetRenderDrawColor(app->engine->renderer, 255, 0, 0, 0);
        vec2i mpos = Real::getMousePos();

        SDL_Rect rect = {
            .x = mpos.x - 5,
            .y = mpos.y - 5,
            .w = 5,
            .h = 5
        };

        SDL_RenderFillRect(app->engine->renderer, &rect);

        SDL_SetRenderDrawColor(app->engine->renderer, 0, 0, 0, 0);

        SDL_RenderPresent(app->engine->renderer);

        // end render

        // wait if frame took less than 1 / maxFps seconds
        do
        {
            curr = deltaTime::get_micro_time();
            dt = curr - prev;
        } while (dt < target_time);

    }
}


static inline float RadToDeg(float angle)
{
    return angle * 57.2957786667f; // 180 / pi
}


int Application::RenderCopyExF(Ecs::Registry *registry, Transform *transform, SpriteComponent *sprite_comp)
{
        Entity camera_e = get_first_active_camera(registry); //TODO(Johan): probably move this call outside render
        if (camera_e == ENTITY_NULL)
        {
            return 0;
        }
        Application_data *app = Application::Get();


        Sprite *sprite = Texture_functions::get_sprite(app->engine->texture, sprite_comp->texture_id);
        SDL_Texture *texture = Texture_functions::get_texture(app->engine->texture, sprite->texture_index);


        Transform *camera_transform  = Ecs::get_component<Transform>(registry, camera_e);
        CameraComponent *camera_comp = Ecs::get_component<CameraComponent>(registry, camera_e);



        SDL_Rect srcrect = {
            .x = (int)sprite->x,
            .y = (int)sprite->y,

            .w = (int)sprite->w,
            .h = (int)sprite->h,
        };


        float width  = transform->scale.x * sprite->w * camera_comp->world_scale.x;
        float height = transform->scale.y * sprite->h * camera_comp->world_scale.y;

        SDL_FRect dstrect = {
            .x = (float)Real::world_to_screen_x(camera_transform, camera_comp, transform->pos.x) - width / 2.0f,
            .y = (float)Real::world_to_screen_y(camera_transform, camera_comp, transform->pos.y) - height / 2.0f,

            .w = width,
            .h = height,
        };


        double angle = RadToDeg(atan2(transform->rot.y, transform->rot.x)) + 90.0f;

    return SDL_RenderCopyExF(app->engine->renderer, texture, &srcrect, &dstrect, angle, NULL, SDL_FLIP_NONE);
}



void Application::load_texture(U32 id, const char *path)
{
    Application_data *app = Application::Get();
    Texture_functions::load_texture(app->engine->renderer, app->engine->texture, id, path);
}


void Application::init_sprite(U32 sprite_id, U32 texture_id, U32 x, U32 y, U32 w, U32 h)
{
    Application_data *app = Application::Get();
    Texture_functions::init_sprite(app->engine->texture, sprite_id, texture_id, x, y, w, h);
}


Application_data *Application::Get()
{
    return n_app_instance;
}


void Application::quit_app(Application_data *app)
{
    app->active = false;
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


Entity Application::get_first_active_camera(Ecs::Registry *registry)
{
    View<CameraComponent> *camera_view = Ecs::get_view<CameraComponent, Transform>(registry);
    Entity active_camera = ENTITY_NULL;

    for (int i = 0; i < camera_view->size; ++i)
    {
        if (camera_view->comparray[i].active == true)
        {
            active_camera = camera_view->entity_list[i];
            break;
        }
    }

    return active_camera;
}
