#pragma once

#include "../Game.hpp"


namespace PlayerSystem
{
    void init(game_data *game);
    void set_player_entity(Entity id);
    void update(float Ts);

} // namespace PlayerSystem