#include "../files/Game.hpp"




int main(int argc, char *argv[])
{   
    const char *exe = *argv++;
    const char *resource_path;
    if(argc > 1)
    {
        resource_path = *argv++;
    }
    else
    {
        resource_path = "./resources";
    }

    game_data *game = Game::create_game();

    Game::init(game);
    Game::setup_game_state(game, resource_path);
    Game::run(game);
    Game::clean(game);

    free(game);

    return 0;
}
















