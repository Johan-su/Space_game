#pragma once
#include "ecs_constants.hpp"


namespace Ecs
{
    struct Registry;
}

struct Group;

struct Iter 
{
    Ecs::Registry *registry;
    Group *group;
    void *event;
    float Ts;
};



