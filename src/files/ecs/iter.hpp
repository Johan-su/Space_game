#pragma once
#include "ecs_constants.hpp"


namespace Ecs
{
    struct Registry;
}

struct Group;
struct top_memory_arena;



struct Iter 
{
    Ecs::Registry *registry;
    Group *group;
    top_memory_arena *view_arena;
    void *event;
    float Ts;
};



