#pragma once
#include "ecs/ecs.hpp"
#include <SDL.h>

struct Game_data
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    Registry_data *registry;

    bool active;
};



namespace Game
{
    Game_data *create_game();
    void destroy_game(Game_data *game);

    void ecs_init(Registry_data *registry);
    void ecs_clean(Registry_data *registry);

    void sdl_init(SDL_Renderer *renderer, SDL_Window *window);
    void sdl_clean(SDL_Renderer *renderer, SDL_Window *window);

    void init(Game_data *game);
    void clean(Game_data *game);


    void update(Game_data *game);
    void handle_events(Game_data *game);
    void render(Game_data *game);

    void run(Game_data *game);
}