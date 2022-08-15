#pragma once

struct SDL_Renderer;
struct SDL_Window;

#include "asset/mesh.hpp"
#include "scene/component.hpp"
#include "scene/Camera.hpp"

namespace Internal
{
   void init_renderer(SDL_Renderer *renderer, SDL_Window *window);
   void clean_renderer();
} // namespace Internal




namespace Renderer
{
    void begin(Transform *camera_transform, CameraComponent *camera_comp);
    void end();

    void clear();
    void draw(Transform *transform, Mesh *mesh);

} // namespace Renderer
