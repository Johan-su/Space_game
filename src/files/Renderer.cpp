#include "Renderer.hpp"

#include <SDL.h>


static SDL_Renderer *s_renderer = nullptr;
static SDL_Window *s_window = nullptr;



void Internal::init_renderer(SDL_Renderer *renderer, SDL_Window *window)
{
    ::s_renderer = renderer;
    ::s_window = window;
}


void Internal::clean_renderer()
{
    /*SDL stuff gets cleared in core*/
}


static Transform *camera_transform = nullptr;
static CameraComponent *camera_comp = nullptr;

void Renderer::begin(Transform *camera_transform, CameraComponent *camera_comp)
{
    ::camera_transform = camera_transform;
    ::camera_comp = camera_comp;
}


void Renderer::end()
{
    SDL_RenderPresent(s_renderer);
    ::camera_transform = nullptr;
    ::camera_comp = nullptr;
}


void Renderer::clear()
{
    SDL_RenderClear(s_renderer);
}


void Renderer::draw(Transform *transform, Mesh *mesh)
{

}

