#pragma once

#include "../Game.hpp"
#include "../Components_Events.hpp"

namespace EntityCreationSystem
{
    
    void create_player(Iter *it);
    void create_bullet (Iter *it);
    void create_ai(Iter *it);
    void create_planet(Iter *it);
} // namespace EntityCreationSystem