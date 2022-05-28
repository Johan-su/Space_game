#pragma once
#include "../Camera.hpp"
#include "../KeyCodes.hpp"


// TODO(Johan) make better



typedef void Application_handle, Texture, Tex_Sprite_handle;

namespace Ecs
{
    struct Registry;
}

struct scene
{
    Ecs::Registry *registry;
    Camera camera;
};




/**
 * 
 * 
 * 
 * 
 * taken from SDL 
 * 
 * 
 * 
 *
 **/


struct Rect
{
    int x, y;
    int w, h; 
};

struct FRect
{
    float x;
    float y;
    float w;
    float h;
};

struct FPoint
{
    float x;
    float y;
};


typedef enum
{
    FLIP_NONE = 0x00000000,     /**< Do not flip */
    FLIP_HORIZONTAL = 0x00000001,    /**< flip horizontally */
    FLIP_VERTICAL = 0x00000002     /**< flip vertically */
} Flip_flag;

//--



struct Texture_Sprite
{
    uint32_t x;
    uint32_t y;
    uint32_t w;
    uint32_t h;

    uint32_t texture_index;
};



namespace Application
{
    
    Application_handle *create_application(const char *pwd);
    void destroy_application(Application_handle *app);

    scene *create_scene();


    scene *get_scene(uint16_t scene_id);

    void run(Application_handle *app, uint16_t scene_id, void (*update_func)(Application_handle *, scene *, float), void (*fixed_update_func)(Application_handle *, scene *, float), void (*render_func)(Application_handle *, scene *, float));

    //void set_scene(Application_handle *app, uint16_t scene_id, void (*update_func)(scene *), void (*fixed_update_func)(scene *), void *render_func);
    void push_scene(Application_handle *app, scene *scene);
    void pop_scene(Application_handle *app);


    /**
     * practically a copy of SDL_RenderCopyExF
     * 
     * 
     * 
     *
     */
    int RenderCopyExF(Application_handle *app,
                      Texture *texture,
                      const Rect *srcrect,
                      const FRect *dstrect,
                      const double angle,
                      const FPoint *center,
                      const Flip_flag flip);



    Texture *get_texture(Application_handle *app, uint32_t id);
    Texture_Sprite *get_sprite(Application_handle *app, uint32_t id);


    bool IsKeyPressed(Application_handle *app, int keyCode);

}