#include "Components_Events.hpp"
#include "Game.hpp"
#include "assert.hpp"
#include "Camera.hpp"

#include "systems/MovementSystem.hpp"
#include "systems/RenderSystem.hpp"
#include "systems/TrackSystem.hpp"
#include "systems/PlayerSystem.hpp"
#include "systems/AngleSystem.hpp"

#include "/platform/deltatime.hpp"
#include "Input.hpp"


#include "/ecs/ecs.hpp"

#include <SDL.h>

#include <string>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>



#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define FPS_TARGET 144
#define FIXED_UPDATE_FREQUENCY_PER_SEC 60

template<typename T>
T *alloc(size_t amount = 1)
{
    T *mem = (T*)malloc(sizeof(T) * amount);
    if(mem == NULL)
    {
        fprintf(stderr, "ERROR: not enough memory");
        exit(1);
    }
    return mem;
}




game_data *Game::create_game()
{
    return alloc<game_data>();
}


void Game::ecs_init(game_data *game)
{
    game->registry = Ecs::create_registry();
    Ecs::init(game->registry);
}


void Game::ecs_clean(game_data *game)
{
    assert(game->registry, "Registry cannot be null");

    Ecs::clean(game->registry);
    free(game->registry);
    game->registry = NULL;
}


void Game::sdl_init(game_data *game)
{
    assert(game, "Game cannot be null");

    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        fprintf(stderr, "ERROR: SDL_INITALIZATION FAILED, %s", SDL_GetError());
        exit(1);
    }

    int flags = 0;
    game->window = SDL_CreateWindow("Space Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    if(!game->window)
    {
        fprintf(stderr, "ERROR: SDL_CreateWindow FAILED, %s", SDL_GetError());
        exit(1);
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if(!game->renderer)
    {
        fprintf(stderr, "ERROR: SDL_CreateRenderer FAILED, %s", SDL_GetError());
        exit(1);
    }
}


void Game::sdl_clean(game_data *game)
{
    assert(game, "game cannot be NULL");
    assert(game->renderer, "renderer cannot be NULL");
    assert(game->window, "window cannot be NULL");

    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);

    game->renderer = NULL;
    game->window = NULL;

    SDL_Quit();
}


void Game::texture_init(game_data *game)
{   
    assert(game, "game cannot be null");
    game->texture = alloc<textures_data>();

    Texture::init(game->texture);
}


void Game::texture_clean(game_data *game)
{
    assert(game, "game cannot be null");

    Texture::clean(game->texture);
    free(game->texture);
    game->texture = NULL;
}


void Game::camera_init(game_data *game)
{
    game->camera = alloc<Camera>();

    Camera_functions::init(game->camera, SCREEN_WIDTH, SCREEN_HEIGHT);
}


void Game::camera_clean(game_data *game)
{
    Camera_functions::clean(game->camera);
    free(game->camera);
    game->camera = NULL;
}


void Game::input_init(game_data *game)
{
    game->key_map = alloc<hash_map<bool>>();
    game->mouse_map = alloc<hash_map<bool>>();

    Hashmap::init(game->key_map);
    Hashmap::init(game->mouse_map);
}


void Game::input_clean(game_data *game)
{
    free(game->key_map);
    free(game->mouse_map);

    game->key_map = NULL;
    game->mouse_map = NULL;
}


void Game::init(game_data *game)
{
    ecs_init(game);
    sdl_init(game);
    texture_init(game);
    camera_init(game);
    input_init(game);

    game->trackedEntity = ENTITY_NULL;
}


void Game::clean(game_data *game)
{
    ecs_clean(game);
    sdl_clean(game);
    texture_clean(game);
    camera_clean(game);
    input_clean(game);
}


void Game::update(game_data *game, float Ts)
{
    MovementSystem::update(Ts);
    PlayerSystem::update(Ts);
    AngleSystem::update(Ts);
}


void Game::fixed_update(game_data *game, float Ts)
{

}


void Game::render(game_data *game, float Ts)
{
    SDL_RenderClear(game->renderer);
    RenderSystem::render();
    RenderSystem::render_tracked_entity();


    SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(game->renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);




    SDL_RenderPresent(game->renderer);
}




void Game::handle_input_events(game_data *game, float Ts) //TODO(Johan) move to different file
{
    Input::handle_input(game);
}


void Game::run(game_data *game)
{
    game->active = true;
    
    //uint64_t print_timer = 0;
    uint64_t fixed_update_count = 0;
    uint64_t target_time = 1000000 / FPS_TARGET;
    uint64_t target_fixed_update = 1000000 / FIXED_UPDATE_FREQUENCY_PER_SEC;
    
    uint64_t curr;
    uint64_t prev = deltaTime::get_micro_time();
    uint64_t dt; // dt in microseconds 10^-6 seconds
    float ts; // time step in seconds

    while(game->active)
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

        handle_input_events(game, ts);
        update(game, ts);

        fixed_update_count += dt;
        while(fixed_update_count >= target_fixed_update)
        {
            fixed_update(game, target_fixed_update / 1000000.0f);
            fixed_update_count -= target_fixed_update;
        }

        render(game, ts);

        do
        {
            curr = deltaTime::get_micro_time();
            dt = curr - prev;
        } while(dt < target_time);

    }
}


void Game::init_components(game_data *game)
{
    Ecs::init_component<Position>(game->registry);
    Ecs::init_component<Size>(game->registry);
    Ecs::init_component<Velocity>(game->registry);
    Ecs::init_component<Angle>(game->registry);
    Ecs::init_component<AnglularVelocity>(game->registry);
    Ecs::init_component<RigidCollision>(game->registry);
    Ecs::init_component<Collision>(game->registry);
    Ecs::init_component<Player>(game->registry);
    Ecs::init_component<Sprite>(game->registry);
}


void Game::init_systems(game_data *game)
{
    MovementSystem::init(game);
    RenderSystem::init(game);
    TrackSystem::init(game);
    PlayerSystem::init(game);
    AngleSystem::init(game);
}


void Game::init_events(game_data *game)
{
    Ecs::init_event<CollisionEvent>(game->registry, NULL); //TODO(Johan) change to real function pointers
    Ecs::init_event<SpawnEvent>(game->registry, NULL);
}


void Game::setup_game_state(game_data *game, const char *resources_path)
{
    init_components(game);
    init_systems(game);
    init_events(game);

    std::string r_path = resources_path; //TODO(Johan) replace std::string
    std::string ship_path = r_path + "/ships/placeholder.bmp";

    Texture::load_texture(game->renderer, game->texture, SHIP_texture, ship_path.c_str());
    Texture::init_sprite(game->texture, SHIP1, SHIP_texture, 0, 0, 114, 200);


    Camera_functions::set_camera_center(game->camera, 0.0f, 0.0f);
    Entity player = Entity_creator::create_player(game, 0.0f, 0.0f, 114.0f, 200.0f, SHIP1);

    PlayerSystem::set_player_entity(player);

    
}


Entity Entity_creator::create_player(game_data *game, float x, float y, float width, float height, uint32_t ship_type)
{
    Entity e = Ecs::create_entity(game->registry);

    auto collision_comp = Collision();
    
    auto player_comp    = Player();
    auto position_comp  = Position();
    auto velocity_comp  = Velocity();
    auto size_comp      = Size();

    auto angle_comp     = Angle();
    auto angleVel_comp  = AnglularVelocity();
    
    auto sprite_comp    = Sprite();

    position_comp.x = x;
    position_comp.y = y;

    velocity_comp.x = 0.0f;
    velocity_comp.y = 0.0f;

    size_comp.width = width;
    size_comp.height = height;

    angle_comp.angle = 0.0f;
    angleVel_comp.angleV = 0.0f;

    sprite_comp.texture_id = ship_type;

    Ecs::set_component(game->registry, e, player_comp);
    Ecs::set_component(game->registry, e, collision_comp);
    Ecs::set_component(game->registry, e, position_comp);
    Ecs::set_component(game->registry, e, velocity_comp);
    Ecs::set_component(game->registry, e, size_comp);
    Ecs::set_component(game->registry, e, angle_comp);
    Ecs::set_component(game->registry, e, angleVel_comp);
    Ecs::set_component(game->registry, e, sprite_comp);


    return e;
}


Entity Entity_creator::create_planet(game_data *game, float x, float y)
{
    return 0;
}



