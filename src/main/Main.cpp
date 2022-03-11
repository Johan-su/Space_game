#include "../files/Game.hpp"




int main(int argv, char *args[])
{
    Game_data *game = Game::create_game();

    Game::init(game);
    Game::run(game);
    Game::clean(game);

    free(game);

    return 0;
}
















