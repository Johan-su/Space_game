#include "Input.hpp"

#include "systems/TrackSystem.hpp"
#include "Camera.hpp"

#include <SDL.h>


#define MOUSE_ZOOM_SCALE_SPEED 1.4f





void Input::handle_input(game_data *game)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        //printf("event type: %d\n", event.type);
        switch(event.type)
        {
            case SDL_QUIT:
                game->active = false;
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
                Hashmap::set(game->mouse_map, event.button.button, true);
                //printf("down %u\n", event.button.button);
                break;


            case SDL_MOUSEBUTTONUP:
                Hashmap::set(game->mouse_map, event.button.button, false);
                //printf("up %u\n", event.button.button);
                break;


            case SDL_MOUSEWHEEL:
                if(event.wheel.y > 0)
                {
                    Camera_functions::zoom(game->camera, MOUSE_ZOOM_SCALE_SPEED);
                }
                else
                {
                    Camera_functions::zoom(game->camera, 1.0f / MOUSE_ZOOM_SCALE_SPEED);
                }
                break;


            case SDL_MOUSEMOTION:
                if(Hashmap::get_value(game->key_map, SDLK_LSHIFT))
                {
                    if(Hashmap::get_value(game->mouse_map, SDL_BUTTON_MIDDLE))
                    {
                        game->camera->world_x -= event.motion.xrel / game->camera->world_scale_x;
                        game->camera->world_y -= event.motion.yrel / game->camera->world_scale_y;
                    }


                    if(Hashmap::get_value(game->mouse_map, SDL_BUTTON_LEFT))
                    {
                        TrackSystem::set_Entity_at_pos(Camera_functions::screen_to_world_x(game->camera, event.motion.x), 
                                                        Camera_functions::screen_to_world_y(game->camera, event.motion.y));
                    }
                }
                //printf("Mouse [ %d, %d ]\n", event.motion.x, event.motion.y);
                
                break;


            case SDL_KEYDOWN:
                Hashmap::set(game->key_map, event.key.keysym.sym, true);
                break;

            case SDL_KEYUP:
                Hashmap::set(game->key_map, event.key.keysym.sym, false);
                break;
        }
    }
}