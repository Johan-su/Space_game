#pragma once

#include "../Game.hpp"

namespace PlayerSystem
{
    void set_player_entity(Entity id);
    void update(Application_data *app, Ecs::Registry *registry, float Ts);

} // namespace PlayerSystem