#include "window.hpp"
#include "core.hpp"




Window *Internal::create_window(int width, int height, const char *title)
{

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
}


void Internal::swap_buffers(Window *window)
{
    glfwSwapBuffers(window->internal_win);
}

