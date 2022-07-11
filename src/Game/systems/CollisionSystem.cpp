#include "CollisionSystem.hpp"

#include "../Components_Events.hpp"

#include <assert.h>

void CollisionSystem::update(Ecs::Registry *registry)
{
    Application::clear_view_buffer();
    View<Position> *pos_view = Ecs::get_view<Position, SizeComponent, Collision>(registry);
    View<SizeComponent> *size_view    = Ecs::get_view<SizeComponent, Position, Collision>(registry);

    for(size_t i = 0; i < pos_view->size; ++i)
    {
        Entity e = pos_view->entity_list[i];
        Position pos = pos_view->comparray[i];
        SizeComponent size = size_view->comparray[i];

        for(size_t j = 0; j < pos_view->size; ++j)
        {
            Entity e2 = pos_view->entity_list[j];
            if (e == e2)
            {
                continue;
            }

            Position pos2 = pos_view->comparray[j];
            SizeComponent size2 = size_view->comparray[j];


            bool b1 = pos.x < pos2.x + size2.width;

            bool b2 = pos.x + size.width > pos2.x;


            bool b3 = pos.y < pos2.y + size2.height;

            bool b4 = pos.y + size.height > pos2.y;


            if (b1 && b2 && b3 && b4)
            {
                CollisionEvent ce = CollisionEvent();

                ce.e1 = e;
                ce.e2 = e2;
                Ecs::broadcast_event<void>(registry, &ce);
            }
        }
    }

}


