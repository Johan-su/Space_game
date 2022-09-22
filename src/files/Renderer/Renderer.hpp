#pragma once

#include "../core/window.hpp"


#include "Mesh.hpp"
#include "../scene/component.hpp"
#include "../scene/Camera.hpp"

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "Material.hpp"

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
    void draw(VertexArray *va, IndexBuffer *ib, Shader *shader, Vector4f color);
    void draw(Transform *transform, MeshComponent *mesh, Shader *shader, Vector4f color);
    void draw(const Transform *transform, const MeshComponent *meshc, const MaterialComponent *materialc);

    void set_blending();
    void set_depth_test(U32 depth_func);

} // namespace Renderer
