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
#include "systems/SpawnerSystem.hpp"
#include "systems/AIControllerSystem.hpp"
#include "systems/HealthSystem.hpp"

static void init_components(scene *scene)
{
    //Ecs::init_component<AnglularVelocity>(&scene->registry);
    Ecs::init_component<Player>(&scene->registry);
    Ecs::init_component<MassComponent>(&scene->registry);
    Ecs::init_component<GravityAttractor>(&scene->registry);
    Ecs::init_component<GravityAffected>(&scene->registry);
    Ecs::init_component<HealthComponent>(&scene->registry);
    Ecs::init_component<DamageComponent>(&scene->registry);
    Ecs::init_component<Planet>(&scene->registry);
    Ecs::init_component<EnemyAI>(&scene->registry);
}


static void init_systems(scene *scene)
{
    Ecs::init_system(&scene->registry, Phase::OnUpdate, AIControllerSystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, CameraController::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, PlayerSystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, MovementSystem::update);
    //Ecs::init_system(&scene->registry, Phase::OnUpdate, AngleSystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, GravitySystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, CollisionSystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, SpawnerSystem::update);
    Ecs::init_system(&scene->registry, Phase::OnUpdate, HealthSystem::update);
    Ecs::init_system(&scene->registry, Phase::PostUpdate, RenderSystem::render);
}


static void init_events(scene *scene)
{
    Ecs::init_event<CollisionEvent>(&scene->registry); 
    Ecs::init_event<AiSpawnEvent>(&scene->registry);
    Ecs::init_event<PlanetSpawnEvent>(&scene->registry);
    Ecs::init_event<PlayerSpawnEvent>(&scene->registry);
    Ecs::init_event<BulletSpawnEvent>(&scene->registry);
}


static void collision_debug(Iter *iter)
{
    CollisionEvent *event = (CollisionEvent *)iter->event;
    printf("collision between [%llu, %llu]", event->e1, event->e2);
}


static void init_event_listeners(scene *scene)
{
    Ecs::init_event_listener<PlayerSpawnEvent>(&scene->registry, EntityCreationSystem::create_player);
    Ecs::init_event_listener<PlanetSpawnEvent>(&scene->registry, EntityCreationSystem::create_planet);
    Ecs::init_event_listener<BulletSpawnEvent>(&scene->registry, EntityCreationSystem::create_bullet); 
    Ecs::init_event_listener<AiSpawnEvent>(&scene->registry, EntityCreationSystem::create_ai);
    Ecs::init_event_listener<CollisionEvent>(&scene->registry, collision_debug); 
}


static void setup_scene(scene *scene)
{
    init_components(scene);
    init_events(scene);
    init_event_listeners(scene);
    init_systems(scene);

    

    const char *ship_path = "./resources/ships/placeholder.bmp";
    const char *planet_path = "./resources/planets/placeholder_planet.bmp";


    Application::load_texture(SHIP_texture, ship_path);
    Application::load_texture(PLANET_texture, planet_path);
    
    Application::init_sprite(SHIP1, SHIP_texture, 0, 0, 114, 200);
    Application::init_sprite(PLANET1, PLANET_texture, 0, 0, 132, 132);

    {
        Entity active_camera = Application::get_first_active_camera(&scene->registry);

        Transform *camera_transform = Ecs::get_component<Transform>(&scene->registry, active_camera);
        CameraComponent *camera_component = Ecs::get_component<CameraComponent>(&scene->registry, active_camera);

        Real::set_camera_center(camera_transform, camera_component, 1000.0f, 1000.0f);
    }


    PlayerSpawnEvent pse = {
        .pos = {1000.0f, 1000.0f},
        .scale = 1.0f,
        .ship_type = SHIP1,
    };

    Ecs::push_event<PlayerSpawnEvent>(&scene->registry, &pse);

    
    PlanetSpawnEvent planetSE = {
        .pos          = {5000.0f, 5000.0f},
        .rot          = {0.0f, 0.0f},
        .scale        = 80.0f,
        .mass         = 100000.0f,
        .planet_type  = PLANET1,
        .health       = 1000000.0f,
        .health_regen = 0.0f,
    };


    Ecs::push_event<PlanetSpawnEvent>(&scene->registry, &planetSE);
}


void init()
{
    scene *main_scene = Application::create_add_scene("GamePlay_scene");
    setup_scene(main_scene);

    Application::run(Application::Get(), main_scene); //TODO(Johan) deprecated
}


void clean()
{

}