#include "Renderer.hpp"

#include "../core/loadgl/load_gl.hpp"
#include "../core/window.hpp"

#include <stdio.h>
#include "../int.hpp"
#include "../assert.hpp"



#ifdef OPENGL_DEBUG
static void GL_debug_callback(GLenum source,
                              GLenum type,
                              GLuint id,
                              GLenum severity,
                              GLsizei length,
                              const GLchar *message,
                              const void *userParam)
{
    if (type != GL_DEBUG_TYPE_ERROR)
        return;

    fprintf(stderr, "DEBUG OpenGL:\nSource: 0x%x\nType: 0x%x\n"
         "Id: 0x%x\nSeverity: 0x%x\n", source, type, id, severity);
    fprintf(stderr, "%s\n", message);
    exit(1);
}
#endif


static Window *s_window = nullptr;


void Internal::init_renderer(Window *window)
{
    ::s_window = window;
    Internal::set_window_as_context(window);

#ifdef OPENGL_DEBUG
    glDebugMessageCallback(GL_debug_callback, nullptr);
#endif


}


void Internal::clean_renderer()
{
    
}


static Transform *s_camera_transform = nullptr;
static CameraComponent *s_camera_comp = nullptr;


void Renderer::begin(Transform *s_camera_transform, CameraComponent *s_camera_comp)
{
    ::s_camera_transform = s_camera_transform;
    ::s_camera_comp = s_camera_comp;
}


void Renderer::end()
{
    Internal::swap_buffers(s_window);
#ifdef _DEBUG
    ::s_camera_transform = nullptr;
    ::s_camera_comp = nullptr;
#endif
}


void Renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}


void Renderer::draw(VertexArray *va, IndexBuffer *ib, Shader *shader, Vector4f color)
{
    Real::bind(va);
    Real::bind(ib);
    Real::bind(shader);

    Real::set_uniform_vec4f(shader, color, "u_Color");

    Mat4 transform_matrix = {
        {1.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 1.0f},
    };

    Real::set_uniform_mat4(shader, &transform_matrix, "u_MVP");


    glDrawElements(GL_TRIANGLES, ib->count, GL_UNSIGNED_INT, nullptr);
}


void Renderer::draw(Transform *transform, MeshComponent *meshc, Shader *shader, Vector4f color) //TODO(Johan): add way to draw using textures and maybe change to materials instead of using shaders + data.
{
    Real::bind(&meshc->mesh->va);
    Real::bind(&meshc->mesh->ib);
    Real::bind(shader);
    
    Real::set_uniform_vec4f(shader, color, "u_Color");

    Mat4 transform_m = Real::transform_to_mat4(transform);

    Mat4 projection = Real::orthographic(0, s_camera_comp->screen_width,
        0, s_camera_comp->screen_height,
        -1.0f, 1.0f);

    Mat4 mvp = projection * transform_m;

    
    Real::set_uniform_mat4(shader, &mvp, "u_MVP");


    glDrawElements(GL_TRIANGLES, meshc->mesh->ib.count, GL_UNSIGNED_INT, nullptr);
}


void Renderer::draw(const Transform *transform, const MeshComponent *meshc, const MaterialComponent *materialc)
{
    Real::bind(&meshc->mesh->va);
    Real::bind(&meshc->mesh->ib);
    Real::bind(materialc->material->shader);
    Real::bind(materialc->material->texture, 0);
    

    Mat4 transform_m = Real::transform_to_mat4(transform);

    Mat4 projection = Real::orthographic(0, s_camera_comp->screen_width,
        0, s_camera_comp->screen_height,
        -1.0f, 1.0f);

    Mat4 mvp = projection * transform_m;

    Real::set_uniform_mat4(materialc->material->shader, &mvp, "u_MVP");

    materialc->material->uniform_set_func(materialc->material->shader);

    glDrawElements(GL_TRIANGLES, meshc->mesh->ib.count, GL_UNSIGNED_INT, nullptr);    
}


void Renderer::set_blending()
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}