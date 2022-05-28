#pragma once

#include "../Game.hpp"

namespace PlayerSystem
{
    void set_player_entity(Entity id);
    void update(Application_handle *app, Ecs::Registry *registry, float Ts);

} // namespace PlayerSystem