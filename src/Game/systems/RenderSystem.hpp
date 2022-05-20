#pragma once
#include "../../ecs/ecs.hpp"
#include "../../Camera.hpp"
#include "../../Texture.hpp"

namespace RenderSystem
{
    void render(Ecs::Registry *registry, SDL_Renderer *renderer, Camera *camera, textures_data *texture_data);
} 
