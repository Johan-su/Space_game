#include "../files/Game.hpp"




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

    game_data *game = Game::create_game();

    Game::init(game, pwd);
    Game::setup_game_state(game, pwd);
    Game::run(game);
    Game::clean(game);

    free(game);
    game = NULL;

    return 0;
}
















