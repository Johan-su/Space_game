#pragma once

namespace Ecs
{
    struct Registry;
}



struct Iter 
{
    Ecs::Registry *curr_registry;
    void *curr_event;
    float Ts;
};



