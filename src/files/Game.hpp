#pragma once
#include "Texture.hpp"
#include "Camera.hpp"

#include "ecs/ecs.hpp"

#include <SDL.h>



struct game_data
{
    SDL_Renderer *renderer;
    SDL_Window *window;

    textures_data *texture;
    Ecs::Registry *registry;

    Camera *camera;


    Entity trackedEntity;
    bool active;
};

struct key_settings
{
    
};


namespace Game
{
    game_data *create_game();


    void ecs_init(game_data *game);
    void ecs_clean(game_data *game);


    void sdl_init(game_data *game);
    void sdl_clean(game_data *game);


    void texture_init(game_data *game);
    void texture_clean(game_data *game);


    void camera_init(game_data *game);
    void camera_clean(game_data *game);

    void init(game_data *game);
    void clean(game_data *game);

    void update(game_data *game, float Ts);
    void fixed_update(game_data *game, float Ts);
    void render(game_data *game, float Ts);
    void handle_input_events(game_data *game, float Ts);

    void run(game_data *game);

    void init_components(game_data *game);
    void init_events(game_data *game);
    void init_systems(game_data *game);

    void setup_game_state(game_data *game, const char *resources_path);
}

namespace GameEvents
{
    
    void event_listener(size_t eventid, const void *event);
}


namespace Entity_creator
{
    Entity create_player(game_data *game, float x, float y, float width, float height, uint32_t ship_type);

    Entity create_planet(game_data *game, float x, float y);
}





