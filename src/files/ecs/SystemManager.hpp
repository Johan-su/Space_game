#pragma once
#include "ecs_constants.hpp"
#include "../Memory_arena.hpp"

enum Phase
{
    None,
    PreUpdate,
    OnUpdate,
    PostUpdate,
};



struct Iter;

namespace Ecs
{

    typedef void (SystemFunc)(Iter *);

    struct SystemPool
    {
        Usize count;
        SystemFunc *funcs[MAX_SYSTEM_TYPES];
    };


    struct system_data
    {
        SystemPool pre_update_funcs;
        SystemPool on_update_funcs;
        SystemPool post_update_funcs;
    };

    
    namespace System_functions
    {
        void init(system_data *sys_data);
        void init_system(system_data *sys_data, Phase phase, SystemFunc *system_func);
        void progess_systems(system_data *sys_data, Memory_arena *view_mm, Iter *iter);


    } // namespace System_functions


    namespace System_functions
    {} // namespace System_functions
    

















} // namespace Ecs
