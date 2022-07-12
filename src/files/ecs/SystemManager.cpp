#include "SystemManager.hpp"
#include "../Application/Application.hpp"
#include "ecs_assert.hpp"
#include <string.h>

using namespace Ecs;

void System_functions::init(system_data *sys_data)
{
    memset(sys_data, 0, sizeof(*sys_data));
}


void System_functions::init_system(system_data *sys_data, Phase phase, SystemFunc *system_func)
{
    switch (phase)
    {
        case Phase::None:
        {} break;

        
        case Phase::PreUpdate:
        {
            sys_data->pre_update_funcs.funcs[sys_data->pre_update_funcs.count] = system_func;
            ++sys_data->pre_update_funcs.count;
        } break;


        case Phase::OnUpdate:
        {
            sys_data->on_update_funcs.funcs[sys_data->on_update_funcs.count] = system_func;
            ++sys_data->on_update_funcs.count;
        } break;


        case Phase::PostUpdate:
        {
            sys_data->post_update_funcs.funcs[sys_data->post_update_funcs.count] = system_func;
            ++sys_data->post_update_funcs.count;
        } break;


        default:
        {
            ECS_assert(false, "Unreachable");
        } break;
        
    }
}


static void run_system(SystemFunc *sys_func, Iter *iter)
{
    Application::clear_view_buffer();

    sys_func(iter);
}


void System_functions::progess_systems(system_data *sys_data, Iter *iter)
{
    for (int i = 0; i < sys_data->pre_update_funcs.count; ++i)
    {
        run_system(sys_data->pre_update_funcs.funcs[i], iter);
    }


    for (int i = 0; i < sys_data->on_update_funcs.count; ++i)
    {
        run_system(sys_data->on_update_funcs.funcs[i], iter);
    }


    for (int i = 0; i < sys_data->post_update_funcs.count; ++i)
    {
        run_system(sys_data->post_update_funcs.funcs[i], iter);
    }
}



