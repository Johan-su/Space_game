#include "Components_Events.hpp"
#include "Game.hpp"
#include "assert.hpp"
#include "Camera.hpp"
#include "RenderSystem.hpp"
#include "deltatime.hpp"

#include "./ecs/ecs.hpp"

#include <SDL.h>

#include <string>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>


#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define MOUSE_ZOOM_SCALE_SPEED 1.4f
#define FPS_TARGET 144

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



ECS_DECLARE_EVENT(CollisionEvent);
ECS_DECLARE_EVENT(SpawnEvent);


void Game::ecs_init(game_data *game)
{
    game->registry = alloc<Registry_data>();
    Registry_functions::init(game->registry, GameEvents::event_listener);

    Registry_functions::init_component<Position>(game->registry);
    Registry_functions::init_component<Size>(game->registry);
    Registry_functions::init_component<Velocity>(game->registry);
    Registry_functions::init_component<Angle>(game->registry);
    Registry_functions::init_component<AnglularVelocity>(game->registry);
    Registry_functions::init_component<RigidCollision>(game->registry);
    Registry_functions::init_component<Collision>(game->registry);
    Registry_functions::init_component<Player>(game->registry);
    Registry_functions::init_component<Sprite>(game->registry);
    

    ECS_INIT_EVENT(game->registry, CollisionEvent);
    ECS_INIT_EVENT(game->registry, SpawnEvent);


}


void Game::ecs_clean(game_data *game)
{
    assert(game->registry != NULL, "Registry is null");

    Registry_functions::clean(game->registry);
    free(game->registry);
    game->registry = NULL;
}


void Game::sdl_init(game_data *game)
{
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
}


void Game::init(game_data *game)
{
    ecs_init(game);
    sdl_init(game);
    texture_init(game);
    camera_init(game);
}


void Game::clean(game_data *game)
{
    ecs_clean(game);
    sdl_clean(game);
    texture_clean(game);
    camera_clean(game);
}


static float update_timer = 0.0f;
void Game::update(game_data *game, float dt)
{
    update_timer += dt;

    double sum = 0;
    for(size_t i = 0; i < (1.0f/(dt + 0.01) * 500000); ++i)
    {
        sum += sqrt(dt * i);
    }

    if(update_timer > 1.0f)
    {
        printf("fps: %f, frametime: %f", 1.0f / dt, dt);
        printf("    sum_sqrt: %f\n", sum);
        update_timer -= 1.0f;
    }
    
}


void Game::render(game_data *game, float dt)
{
    SDL_RenderClear(game->renderer);
    RenderSystem::render(game);


    SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);

    SDL_RenderDrawPoint(game->renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);



    


    SDL_RenderPresent(game->renderer);
}


bool mouse_buttons[100] = {0};
bool shift_button = false;

void Game::handle_input_events(game_data *game, float dt) //TODO(Johan) move to different file
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        //printf("event type: %d\n", event.type);
        switch(event.type)
        {
            case SDL_QUIT:
                game->active = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    default:
                        break;
                }
                mouse_buttons[event.button.button] = true;
                printf("keydown: %d\n", event.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                switch(event.button.button)
                {
                    default:
                        break;
                }
                mouse_buttons[event.button.button] = false;
                printf("keyup: %d\n", event.button.button);
                break;
            case SDL_MOUSEWHEEL:
                if(event.wheel.y > 0)
                {
                    Camera_functions::zoom(game->camera, MOUSE_ZOOM_SCALE_SPEED);
                }
                else
                {
                    Camera_functions::zoom(game->camera, 1.0f / MOUSE_ZOOM_SCALE_SPEED);
                }
                break;

            case SDL_MOUSEMOTION:
                if(shift_button && mouse_buttons[SDL_BUTTON_LEFT])
                {
                    game->camera->world_x -= event.motion.xrel / game->camera->world_scale_x;
                    game->camera->world_y -= event.motion.yrel / game->camera->world_scale_y;
                }
                //printf("Mouse [ %d, %d ]\n", event.motion.x, event.motion.y);
                
                break;


            //

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                   /*case SDLK_w:
                        break;
                    case SDLK_a:
                        break;
                    case SDLK_s:
                        break;
                    case SDLK_d:
                        break;*/
                    
                    case SDLK_LSHIFT:
                        shift_button = true;
                        break;

                    default:
                        printf("%d\n", event.key.keysym.sym);
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_w:
                        break;
                    case SDLK_a:
                        break;
                    case SDLK_s:
                        break;
                    case SDLK_d:
                        break;

                    case SDLK_LSHIFT:
                        shift_button = false;
                        break;
                }
                break;
        }
    }
}




void Game::run(game_data *game)
{
    game->active = true;
    uint64_t curr;
    uint64_t prev = deltaTime::get_milis_time();
    float delta_time;
    while(game->active)
    {
        curr = deltaTime::get_milis_time();
        delta_time = (float)(curr - prev) / 1000.0f;
        prev = curr;

        handle_input_events(game, delta_time);
        update(game, delta_time);
        render(game, delta_time);
    }
}

void Game::setup_game_state(game_data *game, const char *resources_path)
{
    std::string r_path = resources_path; //TODO(Johan) remove std::string
    std::string ship_path = r_path + "/ships/placeholder.bmp";

    Texture::load_texture(game->renderer, game->texture, SHIP_texture, ship_path.c_str());
    Texture::init_sprite(game->texture, SHIP1, SHIP_texture, 0, 0, 114, 200);

    Entity_creator::create_player(game, 0.0f, 0.0f, 114.0f, 200.0f, SHIP1);

    Camera_functions::set_camera_center(game->camera, 0.0f, 0.0f);
    
}



void GameEvents::event_listener(size_t eventid, const void *event)
{
    switch (eventid)
    {
        case ECS_ID(CollisionEvent):
        {
            auto *coll_event = (CollisionEvent*)event;
            dbg(printf("event_listener with CollisionEvent val: %lld , %lld\n", coll_event->e1, coll_event->e2));
            break;
        }
        case ECS_ID(SpawnEvent):
        {
            auto *spawn_event = (SpawnEvent*)event;
            dbg(printf("event_listener with SpawnEvent\n val: %f , %f\n", spawn_event->x, spawn_event->y));
            break;
        }
            
        
        default:
            break;
    }
}






Entity Entity_creator::create_player(game_data *game, float x, float y, float width, float height, uint32_t ship_type)
{
    Entity e = Registry_functions::create_entity(game->registry);

    auto player_comp    = Player();
    auto collision_comp = Collision();
    
    auto position_comp  = Position();
    auto velocity_comp  = Velocity();
    auto size_comp      = Size();

    auto angle_comp     = Angle();
    auto angleVel_comp  = AnglularVelocity();
    
    auto sprite_comp    = Sprite();

    position_comp.x = x - width / 2;
    position_comp.y = y - height / 2;

    velocity_comp.x = 0.0f;
    velocity_comp.y = 0.0f;

    size_comp.width = width;
    size_comp.height = height;

    angle_comp.angle = 0.0f;
    angleVel_comp.angleV = 0.0f;

    sprite_comp.texture_id = ship_type;

    Registry_functions::set_component(game->registry, e, player_comp);
    Registry_functions::set_component(game->registry, e, collision_comp);
    Registry_functions::set_component(game->registry, e, position_comp);
    Registry_functions::set_component(game->registry, e, velocity_comp);
    Registry_functions::set_component(game->registry, e, size_comp);
    Registry_functions::set_component(game->registry, e, angle_comp);
    Registry_functions::set_component(game->registry, e, angleVel_comp);
    Registry_functions::set_component(game->registry, e, sprite_comp);


    return e;
}


Entity Entity_creator::create_planet(game_data *game, float x, float y)
{
    return 0;
}



