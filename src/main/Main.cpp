#include "../files/Game.hpp"


static Game_data *game;

int main(int argv, char* args[])
{
    Game::init(game);
    Game::run(game);
    Game::clean(game);
}
















