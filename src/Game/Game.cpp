#include "Game.hpp"

#include "../files/EntryPoint.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/RenderSystem.hpp"
#include "systems/PlayerSystem.hpp"
#include "systems/AngleSystem.hpp"
#include "systems/EntityCreationSystem.hpp"
#include "systems/CameraController.hpp"
#include "systems/GravitySystem.hpp"
#include "systems/CollisionSystem.hpp"



static void init_components(scene *scene)
{
    Ecs::init_component<AnglularVelocity>(&scene->registry);
    Ecs::init_component<Player>(&scene->registry);
    Ecs::init_component<MassComponent>(&scene->registry);
    Ecs::init_component<GravityAttractor>(&scene->registry);
    Ecs::init_component<GravityAffected>(&scene->registry);
}


static void init_systems(scene *scene)
{
    Ecs::init_system(&scene->registry, Phase::OnUpdate, CameraController::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, PlayerSystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, MovementSystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, AngleSystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, GravitySystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, BoxCollisionSystem::update);
    Ecs::init_system(&scene->registry, Phase::PostUpdate, RenderSystem::render);
}


static void collision_debug(Iter *iter)
{
    CollisionEvent *event = (CollisionEvent *)iter->event;
    printf("collision between [%llu, %llu]", event->e1, event->e2);
}


static void init_events(scene *scene)
{
    Ecs::init_event<CollisionEvent>(&scene->registry); 
    Ecs::init_event<SpawnEvent>(&scene->registry);
    Ecs::init_event<PlanetSpawnEvent>(&scene->registry);
    Ecs::init_event<PlayerSpawnEvent>(&scene->registry);
}


static void init_event_listeners(scene *scene)
{
    Ecs::init_event_listener<PlayerSpawnEvent>(&scene->registry, EntityCreationSystem::create_player);
    Ecs::init_event_listener<PlanetSpawnEvent>(&scene->registry, EntityCreationSystem::create_planet); 
}


static void setup_scene(scene *scene, const char *pwd)
{
    init_components(scene);
    init_events(scene);
    init_event_listeners(scene);
    init_systems(scene);

    

    char *ship_path = Application::cat_string(pwd, "/resources/ships/placeholder.bmp");
    char *planet_path = Application::cat_string(pwd, "/resources/planets/placeholder_planet.bmp");


    Application::load_texture(SHIP_texture, ship_path);
    Application::load_texture(PLANET_texture, planet_path);
    
    Application::init_sprite(SHIP1, SHIP_texture, 0, 0, 114, 200);
    Application::init_sprite(PLANET1, PLANET_texture, 0, 0, 132, 132);


    // Real::set_camera_center(&scene->camera, 0.0f, 0.0f);

    PlayerSpawnEvent pse = {
        .x         = 0.0f,
        .y         = 0.0f,
        .width     = 114.0f,
        .height    = 200.0f,
        .ship_type = SHIP1,
    };

    Ecs::push_event<PlayerSpawnEvent>(&scene->registry, &pse);

    srand(0);
    
    for (int i = 0; i < 500; ++i)
    {

        float x = 100000.0f * ( 2 * ((float)(rand()) / RAND_MAX - 0.5f));
        float y = 100000.0f * ( 2 * ((float)(rand()) / RAND_MAX - 0.5f));

        float radius = 25.0f * ( 2 * ((float)(rand()) / RAND_MAX - 0.5));
        float mass = 1E20 * ((float)(rand()) / RAND_MAX);



        PlanetSpawnEvent planetSE = {
            .x           = x,
            .y           = y,
            .rot_x       = 0.0f,
            .rot_y       = 0.0f,
            .vel_x       = 0.0f,
            .vel_y       = 0.0f,
            .radius      = radius,
            .mass        = mass,
            .planet_type = PLANET1,
        };


        Ecs::push_event<PlanetSpawnEvent>(&scene->registry, &planetSE);
    }
    
    
}


void init(const char *pwd)
{
    scene *main_scene = Application::create_add_scene("GamePlay_scene");
    setup_scene(main_scene, pwd);

    Application::run(Application::Get(), main_scene); //TODO(Johan) deprecated
}


void clean()
{

}