#include "RenderSystem.hpp"
#include "../Components_Events.hpp"


void RenderSystem::render(Iter *iter)
{
    Group *group = Ecs::get_group<Transform, SpriteComponent>(iter->registry);


    Transform *transform_list    = Ecs::get_comp_array<Transform>(group, 0);
    SpriteComponent *sprite_list = Ecs::get_comp_array<SpriteComponent>(group, 1);

    for (Usize i = 0; i < group->size; ++i)
    {

        Application::RenderCopyExF(iter->registry, &transform_list[i], &sprite_list[i]);
    }
}






