#include "Input.hpp"

#include "Camera.hpp"

#include <SDL.h>


#define MOUSE_ZOOM_SCALE_SPEED 1.4f





void Input::handle_input(engine_data *engine)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        //printf("event type: %d\n", event.type);
        switch(event.type)
        {
            case SDL_QUIT:
                engine->active = false;
                break;

            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {
                    case SDL_WINDOWEVENT_ENTER:
                        printf("mouse enter\n");
                        break;
                    
                    
                    case SDL_WINDOWEVENT_LEAVE:
                        printf("mouse leave\n");
                        break;
                
                }
                break;


            case SDL_MOUSEBUTTONDOWN:
                Hashmap::set(engine->mouse_map, event.button.button, true);
                //printf("down %u\n", event.button.button);
                break;


            case SDL_MOUSEBUTTONUP:
                Hashmap::set(engine->mouse_map, event.button.button, false);
                //printf("up %u\n", event.button.button);
                break;


            case SDL_MOUSEWHEEL:
                if(event.wheel.y > 0)
                {
                    //Camera_functions::zoom(engine->camera, MOUSE_ZOOM_SCALE_SPEED);
                }
                else
                {
                    //Camera_functions::zoom(engine->camera, 1.0f / MOUSE_ZOOM_SCALE_SPEED);
                }
                break;


            case SDL_MOUSEMOTION:
                if(Hashmap::get_value(engine->key_map, SDLK_LSHIFT))
                {
                    if(Hashmap::get_value(engine->mouse_map, SDL_BUTTON_MIDDLE))
                    {
                        //engine->camera->world_x -= event.motion.xrel / engine->camera->world_scale_x;
                        //engine->camera->world_y -= event.motion.yrel / engine->camera->world_scale_y;
                    }

                }
                //printf("Mouse [ %d, %d ]\n", event.motion.x, event.motion.y);
                
                break;


            case SDL_KEYDOWN:
                Hashmap::set(engine->key_map, event.key.keysym.sym, true);
                break;

            case SDL_KEYUP:
                Hashmap::set(engine->key_map, event.key.keysym.sym, false);
                break;
        }
    }
}