#include "Game.hpp"

#include "../files/EntryPoint.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/RenderSystem.hpp"
#include "systems/PlayerSystem.hpp"
#include "systems/AngleSystem.hpp"
#include "systems/EntityCreationSystem.hpp"
#include "systems/BoidSystem.hpp"

#include <string>

#include <assert.h>





static void init_components(scene *scene)
{
    Ecs::init_component<Position>(scene->registry);
    Ecs::init_component<Size>(scene->registry);
    Ecs::init_component<Velocity>(scene->registry);
    Ecs::init_component<Angle>(scene->registry);
    Ecs::init_component<AnglularVelocity>(scene->registry);
    Ecs::init_component<RigidCollision>(scene->registry);
    Ecs::init_component<Collision>(scene->registry);
    Ecs::init_component<Player>(scene->registry);
    Ecs::init_component<SpriteComponent>(scene->registry);
    Ecs::init_component<Boid>(scene->registry);
}


static void init_systems(scene *scene)
{
    // MovementSystem::init(game);
    // RenderSystem::init(game);
    // TrackSystem::init(game);
    // PlayerSystem::init(game);
    // AngleSystem::init(game);
    // EntityCreationSystem::init(game);
}


static void fixed_update(Application_data *app, scene *scene, float Ts)
{

}

static void update(Application_data *app, scene *scene, float Ts)
{
    MovementSystem::update(scene->registry, Ts);
    PlayerSystem::update(app, scene->registry, Ts);
    AngleSystem::update(scene->registry, Ts);
    BoidSystem::update(scene->registry, Ts);
    
    
}




static void render(Application_data *app, scene *scene, float Ts)
{
    RenderSystem::render(app, scene);
}



static void init_events(scene *scene)
{
    Ecs::init_event<CollisionEvent, void>(scene->registry, NULL); //TODO(Johan) change to real function pointers
    Ecs::init_event<SpawnEvent, void>(scene->registry, NULL);
    Ecs::init_event<Entity>(scene->registry, EntityCreationSystem::create_player);
    Ecs::init_event<Entity>(scene->registry, EntityCreationSystem::create_boid);
}


static void setup_scene(Application_data *app, scene *scene, const char *pwd)
{
    init_components(scene);
    init_systems(scene);
    init_events(scene);


    

    std::string ship_path = std::string(pwd) + "/resources/ships/placeholder.bmp"; //TODO(Johan) replace std::string


    Application::load_texture(app, SHIP_texture, ship_path.c_str());
    Application::init_sprite(app, SHIP1, SHIP_texture, 0, 0, 114, 200);


    Camera_functions::set_camera_center(&scene->camera, 0.0f, 0.0f);
    Camera_functions::zoom(&scene->camera, 0.10f);

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