#pragma once
#include "core.hpp"


struct vec2i
{
    I16 x;
    I16 y;
};



enum MOUSE_SCROLL
{
    MOUSE_SCROLL_NONE,
    MOUSE_SCROLL_UP,
    MOUSE_SCROLL_DOWN,
};


namespace Internal
{
    void init_input(Window *window);
    void handle_input();
}    



namespace Real
{
    bool IsKeyPressed(int keyCode);
    bool IsMousePressed(int mouseCode);
    MOUSE_SCROLL IsMouseScroll();
    vec2i getMousePos();
}