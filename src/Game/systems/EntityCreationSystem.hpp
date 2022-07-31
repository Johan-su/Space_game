#pragma once

#include "../Game.hpp"
#include "../Components_Events.hpp"

namespace EntityCreationSystem
{
    
    void create_ship(Iter *iter);
    void create_player(Iter *iter);
    void create_ai(Iter *iter);
    void create_planet(Iter *iter);
} // namespace EntityCreationSystem