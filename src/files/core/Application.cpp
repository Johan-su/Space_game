#include "Application.hpp"
#include "../platform/platform.hpp"
#include "Input.hpp"
#include "core.hpp"
#include "../assert.hpp"
#include "../Memory_arena.hpp"
#include "../scene/component.hpp"
#include "../scene/Camera.hpp"
#include "../asset/asset.hpp"
#include "../Renderer/Renderer.hpp"

#include <math.h>

struct Application_data
{
    engine_data *engine;
    Usize scene_count;
    scene *scenes[MAX_SCENE_COUNT];

    bool active;

};

Application_data *Application::n_app_instance = nullptr;




Application_data *Application::create_application()
{
    if (n_app_instance != nullptr)
    {
        fprintf(stderr, "ERROR: tried to create application while an application already exists");
        exit(1);
    }

    Internal::init_global_memory();

    


    n_app_instance = Arena::top_alloc<Application_data>(&g_memory.app_buffer);
    memset(n_app_instance, 0, sizeof(*n_app_instance));

    n_app_instance->engine = Internal::create_engine(&g_memory.app_buffer);

    n_app_instance->active = false;


    return n_app_instance;
}


void Application::destroy_application(Application_data *app)
{
    Internal::clean_engine(app->engine);
    n_app_instance = nullptr;
}


static void init_components(Ecs::Registry *reg)
{
    Ecs::init_component<Transform>(reg);
    Ecs::init_component<CameraComponent>(reg);
    Ecs::init_component<Velocity>(reg);
    Ecs::init_component<SpriteComponent>(reg);
    Ecs::init_component<MaterialComponent>(reg);
    Ecs::init_component<MeshComponent>(reg);
    Ecs::init_component<BoxCollider>(reg);
    Ecs::init_component<CircleCollider>(reg);
}


static void init_events(Ecs::Registry *reg)
{
    Ecs::init_event<CollisionEvent>(reg);
    Ecs::init_event<CameraSpawnEvent>(reg);
}


static void camera_spawn(Iter *it)
{
    CameraSpawnEvent *event = (CameraSpawnEvent *)it->event;

    Entity e = Ecs::create_entity(it->registry);

    Ecs::set_component<Transform>(it->registry, e, {
        event->transform,
    });

    Ecs::set_component<CameraComponent>(it->registry, e, {
        event->cc,
    });
}



static void init_event_listeners(Ecs::Registry *reg)
{
    Ecs::init_event_listener<CameraSpawnEvent>(reg, camera_spawn);
}


scene *Application::create_add_scene(const char *scene_name = "unnamed_scene")
{
    Application_data *app = Application::Get();
    int scene_pos = -1;

    // get unoccupied scene position in app
    for (int i = 0; i < MAX_SCENE_COUNT; ++i)
    {
        if (app->scenes[i] == nullptr)
        {
            scene_pos = i;
            break;
        }
    }

    if (scene_pos != -1)
    {
        scene *game_scene = Arena::top_alloc<scene>(&g_memory.scene_buffers[scene_pos]);

        Ecs::init(&game_scene->registry, &g_memory.scene_buffers[scene_pos], &g_memory.view_buffer, &g_memory.event_buffer);

        init_components(&game_scene->registry);
        init_events(&game_scene->registry);
        init_event_listeners(&game_scene->registry);

        {
            CameraSpawnEvent cse = {
                .transform = {
                    .pos = {0.0f, 0.0f, 0.0f},
                    .rot = {0.0f, 0.0f, 0.0f},
                    .scale = {1.0f, 1.0f, 1.0f},
                },
                .cc = {
                    .projection = Real::orthographic(0, app->engine->config->screen_width, 0, app->engine->config->screen_height, -200.0f, 200.0f),
                    .screen_width = app->engine->config->screen_width,
                    .screen_height = app->engine->config->screen_height,
                    .active = true,
                },

            };

            Ecs::push_event(&game_scene->registry, &cse);
        }

        
        game_scene->name = scene_name;
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
    scene *scene = nullptr;
    for(int i = 0; i < MAX_SCENE_COUNT; ++i)
    {
        if (strcmp(app->scenes[i]->name, scene_name) == 0)
        {
            scene = app->scenes[i];
            break;
        }
    }

    if (scene == nullptr)
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

    if (scene == nullptr)
    {
        fprintf(stderr, "ERROR: scene cannot be nullptr\n");
        return;
    }

    app->active = true;

    U64 print_timer = 0;
    U64 fixed_update_count = 0;
    U64 target_time = 1000000 / app->engine->config->FPS_target;
    U64 target_fixed_update = 1000000 / FIXED_UPDATE_FREQUENCY_PER_SEC;
    
    U64 curr;
    U64 prev = Platform::get_micro_time();
    U64 dt; // dt in microseconds 10^-6 seconds
    float ts; // time step in seconds
    

    // temporary hack to create camera before normal systems run
    Iter it = {
        .registry = &scene->registry,
    };

    Ecs::run_events(&scene->registry, &it);

    Entity camera = Application::get_first_active_camera(&scene->registry);


    Transform *camera_tr = Ecs::get_component<Transform>(&scene->registry, camera);
    CameraComponent *camera_cc = Ecs::get_component<CameraComponent>(&scene->registry, camera);


    while (app->active)
    {
        curr = Platform::get_micro_time();
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

        Renderer::set_blending();
        Renderer::set_depth_test(GL_LESS);

        // begin render
        Renderer::begin(camera_tr, camera_cc);
        Renderer::clear();
        
        // Renderer::draw(&transform, &meshc, material);

        Ecs::progress_systems(&scene->registry, ts);

        //vec2i mpos = Real::getMousePos();

        //printf("mouse_pos [%d, %d]\n", mpos.x, mpos.y);



        Renderer::end();
        // end render

        // wait if frame took less than 1 / maxFps seconds
        do
        {
            curr = Platform::get_micro_time();
            dt = curr - prev;
        } while (dt < target_time);

    }
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
