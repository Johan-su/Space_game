#include "../files/Game.hpp"




int main(int argv, char *args[])
{
    game_data *game = Game::create_game();

    Game::init(game);
    Game::setup_game_state(game);
    Game::run(game);
    Game::clean(game);

    free(game);

    return 0;
}
















