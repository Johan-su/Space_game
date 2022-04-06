#include "TrackSystem.hpp"
#include "../Components_Events.hpp"

#include <SDL.h>


static game_data *game;

void TrackSystem::init(game_data *game)
{
    ::game = game;
}


void TrackSystem::set_Entity_at_pos(float x, float y)
{
    auto pos_view = Ecs::get_view<Position, Size>(game->registry);
    auto size_view = Ecs::get_view<Size, Position>(game->registry);

    for(size_t i = 0; i < pos_view.size; ++i)
    {
        auto pos = pos_view.comparray[i];
        auto size = size_view.comparray[i];

        bool b1 = x > pos.x - size.width / 2;

        bool b2 = y > pos.y - size.height / 2;

        bool b3 = x < pos.x + size.width / 2;

        bool b4 = y < pos.y + size.height / 2;

        if(b1 && b2 && b3 && b4)
        {
            game->trackedEntity = pos_view.entity_list[i];
            break;
        }
    }
}


