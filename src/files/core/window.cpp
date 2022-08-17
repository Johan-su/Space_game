#include "window.hpp"
#include "core.hpp"

#include "loadgl/load_gl.hpp"


Window *Internal::create_window(int width, int height, const char *title)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef OPENGL_DEBUG
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif

    GLFWwindow *glfwwin = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (glfwwin == nullptr)
    {
        fprintf(stderr, "ERROR: failed creating window");
        exit(1);
    }


    Window *window = Arena::top_alloc<Window>(&g_memory.app_buffer, 1);

    window->internal_win = glfwwin;

    return window;
}


void Internal::destroy_window(Window *window)
{
    glfwDestroyWindow(window->internal_win);
}


void Internal::set_window_as_context(Window *window)
{
    glfwMakeContextCurrent(window->internal_win);
    glfwSwapInterval(1);

    if (load_gl() == 0) // NOTE: pretty bad that load_gl() has to be called here.
    {
        fprintf(stderr, "ERROR: failed loading Modern OpenGL\n");
        exit(1);
    }
    printf("OpenGL %s\n", glGetString(GL_VERSION));
}


void Internal::swap_buffers(Window *window)
{
    glfwSwapBuffers(window->internal_win);
}

