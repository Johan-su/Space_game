#pragma once
#include "ecs/ecs.hpp"
#include <SDL.h>

struct game_data
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    Registry_data *registry;

    bool active;
};

struct key_settings
{
    
};


namespace Game
{
    game_data *create_game();
    void destroy_game(game_data *game);

    void ecs_init(game_data *game);
    void ecs_clean(game_data *game);

    void sdl_init(game_data *game);
    void sdl_clean(game_data *game);

    void init(game_data *game);
    void clean(game_data *game);


    void update(game_data *game);
    void handle_events(game_data *game);
    void render(game_data *game);

    void run(game_data *game);
}