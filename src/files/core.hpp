#pragma once
#include "Texture.hpp"
#include "Camera.hpp"
#include "Config.hpp"

#include "ecs/ecs.hpp"

#include <SDL.h>
#include "datastructures/hashmap.hpp"






struct engine_data
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    
    config_data *config;
    textures_data *texture;

    hash_map<bool> *key_map;
    hash_map<bool> *mouse_map;

    bool active;
};

struct key_settings
{
    
};


namespace Real
{
    engine_data *create_context();
    void destroy_context(engine_data *engine);

    void init(engine_data *engine, const char *pwd);
    void clean(engine_data *engine);

    void run(engine_data *engine);

    void setup_scene(engine_data *engine, const char *pwd);
}



// TODO: remove gamevents namespace
namespace GameEvents
{
    
    void event_listener(size_t eventid, const void *event);
}





