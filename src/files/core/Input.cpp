#include "Input.hpp"
#include "Application.hpp"



#include <GLFW/glfw3.h>



struct input_data
{
    MOUSE_SCROLL scroll;
    MousePos mouse_pos;

    HashMap<bool> key_map;
    HashMap<bool> mouse_map;
};


static input_data s_input;
static Window *s_window;


static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    //TODO(Johan): implement scroll
}


static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (action == GLFW_PRESS)
        HashMapN::set(&s_input.mouse_map, button, true);
    else if (action == GLFW_RELEASE)
        HashMapN::set(&s_input.mouse_map, button, false);    
}


static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    s_input.mouse_pos = {(I16)xpos, (I16)ypos};
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
        HashMapN::set(&s_input.key_map, key, true);
    else if (action == GLFW_RELEASE)
        HashMapN::set(&s_input.key_map, key, false);
}


void Internal::init_input(Window *window)
{
    ::s_window = window;
    glfwSetKeyCallback(s_window->internal_win, key_callback);
    glfwSetCursorPosCallback(s_window->internal_win, cursor_position_callback);
    glfwSetMouseButtonCallback(s_window->internal_win, mouse_button_callback);
    glfwSetScrollCallback(s_window->internal_win, scroll_callback);




    HashMapN::init(&s_input.key_map);
    HashMapN::init(&s_input.mouse_map);
    s_input.scroll = MOUSE_SCROLL_NONE;
}


void Internal::handle_input()
{
    glfwPollEvents();
    if (glfwWindowShouldClose(s_window->internal_win) || HashMapN::get_value(&s_input.key_map, VK_KEY_ESCAPE))
    {
        Application::quit_app(Application::Get());
    }

}


bool Real::IsKeyPressed(int keyCode)
{
    return HashMapN::get_value(&s_input.key_map, keyCode);
}

bool Real::IsMousePressed(int mouseCode)
{
    return HashMapN::get_value(&s_input.mouse_map, mouseCode);
}



/**
 * @return MOUSE_SCROLL_NONE, MOUSE_SCROLL_UP, MOUSE_SCROLL_DOWN.
 */ 
MOUSE_SCROLL Real::IsMouseScroll()
{
    return s_input.scroll;
}




MousePos Real::getMousePos()
{
    return s_input.mouse_pos;
}
