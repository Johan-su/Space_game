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
#include "systems/FiringSystem.hpp"
#include "systems/DamageSystem.hpp"

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
    Ecs::init_component<FiringComponent>(&scene->registry);
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
    Ecs::init_system(&scene->registry, Phase::OnUpdate, FiringSystem::update);



    Ecs::init_system(&scene->registry, Phase::PostUpdate, HealthSystem::update);
    Ecs::init_system(&scene->registry, Phase::PostUpdate, RenderSystem::render);
}


static void init_events(scene *scene)
{
    Ecs::init_event<AiSpawnEvent>(&scene->registry);
    Ecs::init_event<PlanetSpawnEvent>(&scene->registry);
    Ecs::init_event<PlayerSpawnEvent>(&scene->registry);
    Ecs::init_event<BulletSpawnEvent>(&scene->registry);
    Ecs::init_event<KillEvent>(&scene->registry);
}


static void collision_debug(Iter *it)
{
    CollisionEvent *event = (CollisionEvent *)it->event;
    //printf("collision between [%llu, %llu]\n", event->e1, event->e2);

    if (event->e1 != 1 && event->e1 != 2)
    {
        printf("DEBUG: destroyed entity %llu\n", event->e1);
        Ecs::destroy_entity(it->registry, event->e1);
    }
    if (event->e2 != 1 && event->e2 != 2)
    {
        printf("DEBUG: destroyed entity %llu\n", event->e2);
        Ecs::destroy_entity(it->registry, event->e2);
    }
}


Entity game_active_camera = ENTITY_NULL;
static void set_active_camera(Iter *it)
{
    CameraSpawnEvent *event = (CameraSpawnEvent *)it->event;
    if (event->active == false)
    {
        return;
    }

    ::game_active_camera = Application::get_first_active_camera(it->registry);

    Transform *camera_transform = Ecs::get_component<Transform>(it->registry, game_active_camera);
    CameraComponent *camera_component = Ecs::get_component<CameraComponent>(it->registry, game_active_camera);
    Real::set_camera_center(camera_transform, camera_component, 7000.0f, 0.0f);
}


static void init_event_listeners(scene *scene)
{
    Ecs::init_event_listener<PlayerSpawnEvent>(&scene->registry, EntityCreationSystem::create_player);
    Ecs::init_event_listener<PlanetSpawnEvent>(&scene->registry, EntityCreationSystem::create_planet);
    Ecs::init_event_listener<BulletSpawnEvent>(&scene->registry, EntityCreationSystem::create_bullet); 
    Ecs::init_event_listener<AiSpawnEvent>(&scene->registry, EntityCreationSystem::create_ai);
    //Ecs::init_event_listener<CollisionEvent>(&scene->registry, collision_debug);
    Ecs::init_event_listener<CollisionEvent>(&scene->registry, DamageSystem::onCollision);
    Ecs::init_event_listener<CameraSpawnEvent>(&scene->registry, set_active_camera);
    Ecs::init_event_listener<KillEvent>(&scene->registry, HealthSystem::on_kill);
}


static void setup_scene(scene *scene)
{
    init_components(scene);
    init_events(scene);
    init_event_listeners(scene);
    init_systems(scene);

    

    const char *ship_path = "./resources/ships/placeholder.bmp";
    const char *planet_path = "./resources/planets/placeholder_planet.bmp";

//    Real::load_texture(ship_path, "placeholder_ship_texture");
//    Real::load_texture(planet_path, "placeholder_planet_texture");

//    Real::init_sprite("ship1_sprite", 0, 0, 114, 200, Real::get_texture("placeholder_ship_texture"));
//    Real::init_sprite("planet1_sprite", 0, 0, 132, 132, Real::get_texture("placeholder_planet_texture"));
    
    Real::load_vertex_shader_src("vshader_source1", "./resources/shaders/placeholder.vert");
    Real::load_fragment_shader_src("fshader_source1", "./resources/shaders/placeholder.frag");

    Real::load_shader("shader1", Real::get_vertex_src("vshader_source1"), Real::get_fragment_src("fshader_source1"));


    Real::load_mesh("square_mesh", "./resources/meshes/square.mesh");

    
    /*PlayerSpawnEvent pse = {
        .pos = {7000.0f, 0.0f},
        .scale = 1.0f,
        .ship_sprite = Real::get_sprite("ship1_sprite"),
    };

    Ecs::push_event<PlayerSpawnEvent>(&scene->registry, &pse);

    
    PlanetSpawnEvent planetSE = {
        .pos           = {0.0f, 0.0f},
        .rot           = {0.0f, 0.0f},
        .scale         = 80.0f,
        .mass          = 100000.0f,
        .planet_sprite = Real::get_sprite("planet1_sprite"),
        .health        = 1000000.0f,
        .health_regen  = 0.0f,
    };*/


    //Ecs::push_event<PlanetSpawnEvent>(&scene->registry, &planetSE);
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