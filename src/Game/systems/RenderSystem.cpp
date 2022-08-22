#include "RenderSystem.hpp"
#include "../Components_Events.hpp"




//#define PROFILE_FUNCTIONS
#include "../../files/Time.hpp"

void RenderSystem::render(Iter *it)
{
    BEGIN_PROFILE_BLOCK();


    const Group *group = Ecs::get_group<Transform, MeshComponent, MaterialComponent>(it->registry);

    const Transform *transform_list    = Ecs::get_comp_array<Transform>(group, 0);
    const MeshComponent *mesh_list     = Ecs::get_comp_array<MeshComponent>(group, 1);
    const MaterialComponent *material_list = Ecs::get_comp_array<MaterialComponent>(group, 2);

    for (Usize i = 0; i < group->size; ++i)
    {
        Renderer::draw(&transform_list[i], &mesh_list[i], &material_list[i]);
    }
    
    END_PROFILE_BLOCK();
}






