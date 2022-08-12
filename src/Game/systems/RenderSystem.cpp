#include "RenderSystem.hpp"
#include "../Components_Events.hpp"




//#define PROFILE_FUNCTIONS
#include "../../files/Time.hpp"

void RenderSystem::render(Iter *it)
{
    BEGIN_PROFILE_BLOCK;

    if (game_active_camera == ENTITY_NULL)
    {
        return;
    }

    Transform *camera_t = Ecs::get_component<Transform>(it->registry, game_active_camera);
    CameraComponent *camera_cc = Ecs::get_component<CameraComponent>(it->registry, game_active_camera);

    const Group *group = Ecs::get_group<Transform, SpriteComponent>(it->registry);

    const Transform *transform_list    = Ecs::get_comp_array<Transform>(group, 0);
    const SpriteComponent *sprite_list = Ecs::get_comp_array<SpriteComponent>(group, 1);

    for (Usize i = 0; i < group->size; ++i)
    {

        Application::RenderCopyExF(it->registry, &transform_list[i], &sprite_list[i], camera_t, camera_cc);
    }
    END_PROFILE_BLOCK;
}






