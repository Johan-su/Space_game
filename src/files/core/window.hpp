#pragma once

#include <GLFW/glfw3.h>
struct Window
{
    GLFWwindow *internal_win;
};


namespace Internal
{
    Window *create_window(int width, int height, const char *title);
    void destroy_window(Window *window);

    void set_window_as_context(Window *window);
    void swap_buffers(Window *window);

} // namespace Internal


