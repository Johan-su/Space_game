#pragma once

#include "../Game.hpp"
#include "../Components_Events.hpp"

namespace EntityCreationSystem
{
    
    Entity create_ship(Ecs::Registry *registry, ShipSpawnEvent *event);
    Entity create_player(Ecs::Registry *registry, PlayerSpawnEvent *event);
    Entity create_ai(Ecs::Registry *registry, AiSpawnEvent *event);
    Entity create_planet(Ecs::Registry *registry, PlanetSpawnEvent *event);

} // namespace EntityCreationSystem