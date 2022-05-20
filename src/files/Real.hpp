#pragma once
#include "ecs/ecs.hpp"
#include "Application/Application.hpp"


// Need to define update, fixed_update, render










int main(int argc, char *argv[])
{   
    const char *exe = *argv++;
    (void)exe;
    const char *pwd;
    if(argc > 1)
    {
        pwd = *argv++;
    }
    else
    {
        pwd = "./";
    }

    // game_data *game = Game::create_context();

    // Game::init(game, pwd);
    // Game::setup_scene(game, pwd);
    // Game::run(game);
    // Game::clean(game);

    // free(game);
    // game = NULL;

    return 0;
}