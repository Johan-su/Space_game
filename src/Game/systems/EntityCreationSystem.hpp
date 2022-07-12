#pragma once

#include "../Game.hpp"
#include "../Components_Events.hpp"

namespace EntityCreationSystem
{
    
    Entity create_ship(Iter *iter);
    Entity create_player(Iter *iter);
    Entity create_ai(Iter *iter);
    Entity create_planet(Iter *iter);
} // namespace EntityCreationSystem