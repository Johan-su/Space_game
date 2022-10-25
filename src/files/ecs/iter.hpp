#pragma once
#include "ecs_constants.hpp"


namespace Ecs
{
    struct Registry;
}

struct Group;
struct Memory_arena;



struct Iter 
{
    Ecs::Registry *registry;
    Group *group;
    Memory_arena *view_arena;
    void *event;
    float Ts;
};



