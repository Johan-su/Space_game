#include "RenderSystem.hpp"
#include "../Components_Events.hpp"





void RenderSystem::render(Iter *iter)
{
    Group *group = Ecs::get_group<Transform, SpriteComponent>(iter->curr_registry);

    for (Usize i = 0; i < group->size; ++i)
    {
        //dbg(printf("running in render for loop\n"));


        Transform *transform = &((Transform *)(group->comp_arrays[0]))[i];
        SpriteComponent *sprite_comp = &((SpriteComponent *)(group->comp_arrays[1]))[i];



        // printf("camerapos [x = %f, y = %f, scale_x = %f, scale_y = %f] ", camera->world_x, camera->world_y, camera->world_scale_x, camera->world_scale_y);
        // printf("renderpos [x = %f, y = %f, w = %f, h = %f]\n", dstrect.x, dstrect.y, dstrect.w, dstrect.h);

        Application::RenderCopyExF(iter->curr_registry, transform, sprite_comp);
    }
}






