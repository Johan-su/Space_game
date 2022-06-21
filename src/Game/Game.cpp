#include "Game.hpp"

#include "../files/EntryPoint.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/RenderSystem.hpp"
#include "systems/PlayerSystem.hpp"
#include "systems/AngleSystem.hpp"
#include "systems/EntityCreationSystem.hpp"
#include "systems/CameraController.hpp"




static void init_components(scene *scene)
{
    Ecs::init_component<Position>(scene->registry);
    Ecs::init_component<SizeComponent>(scene->registry);
    Ecs::init_component<Velocity>(scene->registry);
    Ecs::init_component<Angle>(scene->registry);
    Ecs::init_component<AnglularVelocity>(scene->registry);
    Ecs::init_component<RigidCollision>(scene->registry);
    Ecs::init_component<Collision>(scene->registry);
    Ecs::init_component<Player>(scene->registry);
    Ecs::init_component<SpriteComponent>(scene->registry);
}


static void fixed_update(Application_data *app, scene *scene, float Ts)
{

}



static void update(Application_data *app, scene *scene, float Ts)
{
    CameraController::update(scene);
    MovementSystem::update(scene->registry, Ts);
    PlayerSystem::update(app, scene->registry, Ts);
    AngleSystem::update(scene->registry, Ts);
}




static void render(Application_data *app, scene *scene, float Ts)
{
    RenderSystem::render(app, scene);
}


static void collision_debug(Ecs::Registry *registry, CollisionEvent *event)
{
    printf("collision between [%llu, %llu]", event->e1, event->e2);
}


static void init_events(scene *scene)
{
    Ecs::init_event(scene->registry, collision_debug); //TODO(Johan) change to real function pointers
    Ecs::init_event<void, SpawnEvent>(scene->registry, NULL);
    Ecs::init_event(scene->registry, EntityCreationSystem::create_player);
}


static void setup_scene(Application_data *app, scene *scene, const char *pwd)
{
    init_components(scene);
    init_events(scene);

    

    char *ship_path = Application::cat_string(pwd, "/resources/ships/placeholder.bmp");
    char *planet_path = Application::cat_string(pwd, "/resources/planets/placeholder_planet.bmp");


    Application::load_texture(app, SHIP_texture, ship_path);
    Application::load_texture(app, PLANET_texture, planet_path);
    Application::init_sprite(app, SHIP1, SHIP_texture, 0, 0, 114, 200);


    Camera_functions::set_camera_center(&scene->camera, 0.0f, 0.0f);

    PlayerSpawnEvent pse = PlayerSpawnEvent{0.0f, 0.0f, 114.0f, 200.0f, SHIP1};
    Entity player = Ecs::broadcast_event<Entity>(scene->registry, &pse);

    PlayerSystem::set_player_entity(player);  
}


void init(Application_data *app, const char *pwd)
{
    scene *main_scene = Application::create_add_scene(app, "GamePlay_scene");
    setup_scene(app, main_scene, pwd);



    Application::run(app, main_scene, update, fixed_update, render);
}


void clean(Application_data *app)
{

}