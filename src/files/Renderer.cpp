#include "Renderer.hpp"

#include "core/loadgl/load_gl.hpp"
#include "core/window.hpp"

#include <stdio.h>

#include "assert.hpp"

//static SDL_Renderer *s_renderer = nullptr;
static Window *s_window = nullptr;



void Internal::init_renderer(Window *window)
{
    //::s_renderer = renderer;
    ::s_window = window;

    Internal::set_window_as_context(window);
}


void Internal::clean_renderer()
{
    /*SDL stuff gets cleared in core*/
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

