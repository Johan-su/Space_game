#pragma once
#include "../Camera.hpp"
#include "../KeyCodes.hpp"


// TODO(Johan) make better



typedef void Texture, Tex_Sprite_handle;


struct Application_data;

namespace Ecs
{
    struct Registry;
}

struct scene
{
    Camera camera;
    const char *name;
    Ecs::Registry *registry;
};

typedef struct scene scene;



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
    
    Application_data *create_application(const char *pwd);
    void destroy_application(Application_data *app);

    scene *create_add_scene(Application_data *app, const char *scene_name);

    scene *get_scene_by_name(Application_data *app, const char *scene_name);

    void run(Application_data *app, scene *scene, void (*update_func)(Application_data *, struct scene *, float), void (*fixed_update_func)(Application_data *, struct scene *, float), void (*render_func)(Application_data *, struct scene *, float));

    //void set_scene(Application_data *app, uint16_t scene_id, void (*update_func)(scene *), void (*fixed_update_func)(scene *), void *render_func);


    /**
     * practically a copy of SDL_RenderCopyExF
     * 
     * 
     * 
     *
     */
    int RenderCopyExF(Application_data *app,
                      Texture *texture,
                      const Rect *srcrect,
                      const FRect *dstrect,
                      const double angle,
                      const FPoint *center,
                      const Flip_flag flip);



    void load_texture(Application_data *app, uint32_t id, const char *path);
    void init_sprite(Application_data *app, uint32_t sprite_id, uint32_t texture_id, uint32_t x, uint32_t y, uint32_t w, uint32_t h);

    Texture *get_texture(Application_data *app, uint32_t id);
    Texture_Sprite *get_sprite(Application_data *app, uint32_t id);


    bool IsKeyPressed(Application_data *app, int keyCode);

}