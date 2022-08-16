#pragma once
#include "KeyCodes.hpp"
#include "../scene/scene.hpp"
#include "../scene/component.hpp"
#include "../asset/mesh.hpp"
// TODO(Johan) make better


struct Application_data;

namespace Ecs
{
    struct Registry;
}


namespace Application
{
    extern Application_data *n_app_instance;


    Application_data *create_application();
    void destroy_application(Application_data *app);

    scene *create_add_scene( const char *scene_name);

    scene *get_scene_by_name(const char *scene_name);

    void run(Application_data *app, scene *scene);

    //void set_scene(Application_data *app, uint16_t scene_id, void (*update_func)(scene *), void (*fixed_update_func)(scene *), void *render_func);


    Application_data *Get();
    void quit_app(Application_data *app);


    char *cat_string(const char *str1, const char *str2);

    /**
     * does not clear view buffer
     */ 
    Entity get_first_active_camera(Ecs::Registry *registry);

}