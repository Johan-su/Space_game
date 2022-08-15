#include "Renderer.hpp"

#include <SDL.h>
#include <stdio.h>

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

void Renderer::begin(Transform *s_camera_transform, CameraComponent *s_camera_comp)
{
    ::camera_transform = s_camera_transform;
    ::camera_comp = s_camera_comp;
}


void Renderer::end()
{
    SDL_RenderPresent(s_renderer);
    /*
    ::camera_transform = nullptr;
    ::camera_comp = nullptr;
    */
}


void Renderer::clear()
{
    SDL_RenderClear(s_renderer);
}


void Renderer::draw(Transform *transform, Mesh *mesh)
{
    SDL_SetRenderDrawColor(s_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_Color col[MAX_VERTICIES];

    for (int i = 0; i < MAX_VERTICIES; ++i)
    {
        col[i] = {
            .r = 255,
            .g = 0,
            .b = 0,
            .a = 255,
        };
    }

    float xy[MAX_VERTICIES * 2] = {0};

    
    Mesh mesh_data = *mesh;

    for (int i = 0; i < mesh->vertex_buffer.vertex_count; i += 1)
    {
        mesh_data.vertex_buffer.verticies[i].pos += 1.5f; 
        mesh_data.vertex_buffer.verticies[i].pos *= 500.0f; 
    }
    
    int er = SDL_RenderGeometryRaw(s_renderer, 
        nullptr, 
        &mesh_data.vertex_buffer.verticies->pos.x, 
        sizeof(mesh_data.vertex_buffer.verticies[0]), 
        col, 
        sizeof(SDL_Color),
        &mesh_data.vertex_buffer.verticies->tex_coords.u, 
        sizeof(mesh_data.vertex_buffer.verticies[0]),
        mesh_data.vertex_buffer.vertex_count,
        mesh_data.index_buffer.indicies,
        mesh_data.index_buffer.index_count,
        sizeof(mesh_data.index_buffer.indicies[0]));
    
    if (er != 0)
    {
        fprintf(stderr, "ERROR: sdl failed with %s\n", SDL_GetError());
        exit(1);
    }
}

