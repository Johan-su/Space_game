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


            /*case SDL_MOUSEBUTTONDOWN:
                game->mouse_button_bool_map->emplace(event.button.button, true);
                break;


            case SDL_MOUSEBUTTONUP:
                game->mouse_button_bool_map->emplace(event.button.button, false);
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
                if(game->key_bool_map->at(SDLK_LSHIFT))
                {
                    if(game->mouse_button_bool_map->at(SDL_BUTTON_MIDDLE))
                    {
                        game->camera->world_x -= event.motion.xrel / game->camera->world_scale_x;
                        game->camera->world_y -= event.motion.yrel / game->camera->world_scale_y;
                    }


                    if(game->mouse_button_bool_map->at(SDL_BUTTON_LEFT))
                    {
                        TrackSystem::set_Entity_at_pos(game, Camera_functions::screen_to_world_x(game->camera, event.motion.x), 
                                                        Camera_functions::screen_to_world_y(game->camera, event.motion.y));
                    }
                }
                //printf("Mouse [ %d, %d ]\n", event.motion.x, event.motion.y);
                
                break;


            case SDL_KEYDOWN:
                game->key_bool_map->emplace(event.key.keysym.sym, true);
                break;

            case SDL_KEYUP:
                game->key_bool_map->emplace(event.key.keysym.sym, false);
                break;
        */}
    }
}