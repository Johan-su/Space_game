#pragma once

#include "../Game.hpp"

#include "../Components_Events.hpp"

namespace EntityCreationSystem
{
    void init(game_data *game);

    Entity create_player(PlayerSpawnEvent *event);

    Entity create_boid(BoidSpawnEvent *event);

    Entity create_planet(float x, float y);

} // namespace EntityCreationSystem