#pragma once

#include "../core/window.hpp"


#include "../asset/mesh.hpp"
#include "../scene/component.hpp"
#include "../scene/Camera.hpp"

namespace Internal
{
   void init_renderer(Window *window);
   void clean_renderer();
} // namespace Internal




namespace Renderer
{
    void begin(Transform *camera_transform, CameraComponent *camera_comp);
    void end();

    void clear();
    void draw(const Transform *transform, Mesh mesh, const Sprite *sprite);
    void draw();

} // namespace Renderer
