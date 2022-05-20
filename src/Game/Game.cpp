#include "Game.hpp"

struct scene;

#include "systems/MovementSystem.hpp"
#include "systems/RenderSystem.hpp"
#include "systems/PlayerSystem.hpp"
#include "systems/AngleSystem.hpp"
#include "systems/EntityCreationSystem.hpp"

static void init_components(scene *scene)
{
    // Ecs::init_component<Position>(scene->registry);
    // Ecs::init_component<Size>(scene->registry);
    // Ecs::init_component<Velocity>(scene->registry);
    // Ecs::init_component<Angle>(scene->registry);
    // Ecs::init_component<AnglularVelocity>(scene->registry);
    // Ecs::init_component<RigidCollision>(scene->registry);
    // Ecs::init_component<Collision>(scene->registry);
    // Ecs::init_component<Player>(scene->registry);
    // Ecs::init_component<Sprite>(scene->registry);
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




static void update()
{
    // MovementSystem::update(Ts);
    // PlayerSystem::update(Ts);
    // AngleSystem::update(Ts);
}




static void render()
{
    // RenderSystem::render();
}



static void init_events(scene *scene)
{
    // Ecs::init_event<CollisionEvent, void>(scene->registry, NULL); //TODO(Johan) change to real function pointers
    // Ecs::init_event<SpawnEvent, void>(scene->registry, NULL);
    // Ecs::init_event<Entity>(scene->registry, EntityCreationSystem::create_player);
}


static void setup_scene(scene *scene, const char *pwd)
{
    // init_components(scene);
    // init_systems(scene);
    // init_events(scene);


    // std::string ship_path = std::string(pwd) + "/resources/ships/placeholder.bmp"; //TODO(Johan) replace std::string

    // Texture::load_texture(scene->renderer, scene->texture, SHIP_texture, ship_path.c_str());
    // Texture::init_sprite(scene->texture, SHIP1, SHIP_texture, 0, 0, 114, 200);


    // Camera_functions::set_camera_center(scene->camera, 0.0f, 0.0f);

    // PlayerSpawnEvent pse = PlayerSpawnEvent{0.0f, 0.0f, 114.0f, 200.0f, SHIP1};

    // Entity player = Ecs::broadcast_event<Entity>(scene->registry, &pse);

    // PlayerSystem::set_player_entity(player);  
}