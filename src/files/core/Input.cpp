#include "Input.hpp"
#include "Application.hpp"



#include <GLFW/glfw3.h>



struct input_data
{
    MOUSE_SCROLL scroll;
    vec2i mouse_pos;

    HashMap<bool> key_map;
    HashMap<bool> mouse_map;
};


static input_data s_input;
static Window *s_window;

void Internal::init_input(Window *window)
{
    ::s_window = window;
    HashMapN::init(&s_input.key_map);
    HashMapN::init(&s_input.mouse_map);
    s_input.scroll = MOUSE_SCROLL_NONE;
}


void Internal::handle_input()
{
    glfwPollEvents();
    if (glfwWindowShouldClose(s_window->internal_win))
    {
        Application::quit_app(Application::Get());
    }
    /*

    if (HashMapN::get_value(&input.key_map, SDLK_ESCAPE))
    {
        // TODO(Johan): probably change to something better
        Application::quit_app(Application::Get());
    }

    SDL_Event event;
    // TODO(Johan) maybe find better solution to mouse scroll
    input.scroll = MOUSE_SCROLL_NONE;
    while (SDL_PollEvent(&event))
    {
        //printf("event type: %d\n", event.type);
        switch(event.type)
        {
            case SDL_QUIT:
            {
                 // TODO(Johan): probably change to something better
                Application::quit_app(Application::Get());
            } break;

            
            case SDL_WINDOWEVENT:
            {
                switch (event.window.event)
                {
                    case SDL_WINDOWEVENT_ENTER:
                    {
                        printf("mouse enter\n");
                    } break;
                    
                    
                    case SDL_WINDOWEVENT_LEAVE:
                    {
                        printf("mouse leave\n");
                    } break;
                }
            } break;


            case SDL_MOUSEBUTTONDOWN:
            {
                HashMapN::set(&input.mouse_map, event.button.button, true);
                //printf("down %u\n", event.button.button);
            } break;


            case SDL_MOUSEBUTTONUP:
            {
                HashMapN::set(&input.mouse_map, event.button.button, false);
                //printf("up %u\n", event.button.button);
            } break;


            case SDL_MOUSEWHEEL:
            {
                if (event.wheel.y > 0)
                {
                    input.scroll = MOUSE_SCROLL_UP;
                    //printf("Mouse scroll up\n");
                }
                else if (event.wheel.y < 0)
                {
                    input.scroll = MOUSE_SCROLL_DOWN;
                    //printf("Mouse scroll down\n");
                }
            } break;


            case SDL_MOUSEMOTION:
            {
                input.mouse_pos.x = event.motion.x;
                input.mouse_pos.y = event.motion.y;

               // printf("Mouse [ %d, %d ]\n", event.motion.x, event.motion.y);
            } break;


            case SDL_KEYDOWN:
            {
                HashMapN::set(&input.key_map, event.key.keysym.sym, true);
            } break;


            case SDL_KEYUP:
            {
                HashMapN::set(&input.key_map, event.key.keysym.sym, false);
            } break;
        }
    }
    */
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




vec2i Real::getMousePos()
{
    return s_input.mouse_pos;
}
