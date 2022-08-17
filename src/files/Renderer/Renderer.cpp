#include "Renderer.hpp"

#include "../core/loadgl/load_gl.hpp"
#include "../core/window.hpp"

#include <stdio.h>

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


void Renderer::draw(const Transform *transform, Mesh mesh, const Sprite *sprite)
{
    assert(s_camera_transform != nullptr, "camera transform cannot be nullptr in draw, forgot begin() ?");
    assert(s_camera_comp != nullptr, "camera component cannot be nullptr in draw, forgot begin() ?");


}

