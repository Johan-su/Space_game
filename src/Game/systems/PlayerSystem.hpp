#pragma once

#include "../../ecs/ecs.hpp"
#include "../../datastructures/hashmap.hpp"

namespace PlayerSystem
{
    void set_player_entity(Entity id);
    void update(Ecs::Registry *registry, hash_map<bool> *key_map, float Ts);

} // namespace PlayerSystem