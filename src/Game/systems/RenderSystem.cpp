#include "RenderSystem.hpp"
#include "../Components_Events.hpp"





void RenderSystem::render(Iter *iter)
{  
    View<Transform> *transform_view = Ecs::get_view<Transform, SpriteComponent>(iter->curr_registry);
    View<SpriteComponent> *sprite_view = Ecs::get_view<SpriteComponent, Transform>(iter->curr_registry);

    for (Usize i = 0; i < transform_view->size; ++i)
    {
        //dbg(printf("running in render for loop\n"));


        Transform *transform = &transform_view->comparray[i];
        SpriteComponent *sprite_comp = &sprite_view->comparray[i];



        // printf("camerapos [x = %f, y = %f, scale_x = %f, scale_y = %f] ", camera->world_x, camera->world_y, camera->world_scale_x, camera->world_scale_y);
        // printf("renderpos [x = %f, y = %f, w = %f, h = %f]\n", dstrect.x, dstrect.y, dstrect.w, dstrect.h);

        Application::RenderCopyExF(iter->curr_registry, transform, sprite_comp);
    }
}






