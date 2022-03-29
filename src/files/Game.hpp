#pragma once
#include "ecs/ecs.hpp"
#include "Texture.hpp"

#include <SDL.h>







struct game_data
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    textures_data *texture;
    Registry_data *registry;

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

    void init(game_data *game);
    void clean(game_data *game);


    void load_texture(game_data *game, uint32_t enum_id,  const char *path);
    SDL_Texture *get_texture(game_data *game, uint32_t enum_id);

    void update(game_data *game);
    void render(game_data *game);
    void handle_input_events(game_data *game);

    void run(game_data *game);

    
    void setup_game_state(game_data *game);
}

namespace GameEvents
{
    
    void event_listener(size_t eventid, const void *event);
}


namespace Entity_creator
{
    Entity create_player(float x, float y);
    Entity create_planet(float x, float y);
}