#include "Input.hpp"

#include "../Camera.hpp"

#include <SDL.h>






struct input_data
{
    MOUSE_SCROLL scroll;
    vec2i mouse_pos;

    hash_map<bool> key_map;
    hash_map<bool> mouse_map;
};


static input_data input;


void Internal::init_input()
{
    Hashmap::init(&input.key_map);
    Hashmap::init(&input.mouse_map);
    input.scroll = MOUSE_SCROLL_NONE;
}


void Internal::handle_input()
{
    SDL_Event event;
    // TODO(Johan) maybe find better solution to mouse scroll
    input.scroll = MOUSE_SCROLL_NONE;
    while(SDL_PollEvent(&event))
    {
        //printf("event type: %d\n", event.type);
        switch(event.type)
        {
            case SDL_QUIT:
            {
                // TODO(Johan) implement quitting
            } break;

            /*
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

            */


            case SDL_MOUSEBUTTONDOWN:
            {
                Hashmap::set(&input.mouse_map, event.button.button, true);
                //printf("down %u\n", event.button.button);
            } break;


            case SDL_MOUSEBUTTONUP:
            {
                Hashmap::set(&input.mouse_map, event.button.button, false);
                //printf("up %u\n", event.button.button);
            } break;

            case SDL_MOUSEWHEEL:
            {
                if(event.wheel.y > 0)
                {
                    input.scroll = MOUSE_SCROLL_UP;
                    //printf("Mouse scroll up\n");
                }
                else if(event.wheel.y < 0)
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
                Hashmap::set(&input.key_map, event.key.keysym.sym, true);
            } break;


            case SDL_KEYUP:
            {
                Hashmap::set(&input.key_map, event.key.keysym.sym, false);
            } break;
        }
    }
}


bool Real::IsKeyPressed(int keyCode)
{
    return Hashmap::get_value(&input.key_map, keyCode);
}

bool Real::IsMousePressed(int mouseCode)
{
    return Hashmap::get_value(&input.mouse_map, mouseCode);
}



/**
 * @return MOUSE_SCROLL_NONE, MOUSE_SCROLL_UP, MOUSE_SCROLL_DOWN.
 */ 
MOUSE_SCROLL Real::IsMouseScroll()
{
    return input.scroll;
}




vec2i Real::getMousePos()
{
    return input.mouse_pos;
}
