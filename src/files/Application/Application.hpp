#pragma once
#include "../input/KeyCodes.hpp"
#include "../scene/scene.hpp"
#include "../scene/component.hpp"

// TODO(Johan) make better


struct Application_data;

namespace Ecs
{
    struct Registry;
}


namespace Application
{
    extern Application_data *n_app_instance;


    Application_data *create_application(const char *pwd);
    void destroy_application(Application_data *app);

    scene *create_add_scene( const char *scene_name);

    scene *get_scene_by_name(const char *scene_name);

    void run(Application_data *app, scene *scene);

    //void set_scene(Application_data *app, uint16_t scene_id, void (*update_func)(scene *), void (*fixed_update_func)(scene *), void *render_func);


    int RenderCopyExF(Ecs::Registry *registry, Transform *transform, SpriteComponent *sprite_comp);



    void load_texture(U32 id, const char *path);
    void init_sprite(U32 sprite_id, U32 texture_id, U32 x, U32 y, U32 w, U32 h);

    Application_data *Get();
    void quit_app(Application_data *app);


    char *cat_string(const char *str1, const char *str2);

    /**
     * does not clear view buffer
     */ 
    Entity get_first_active_camera(Ecs::Registry *registry);

}