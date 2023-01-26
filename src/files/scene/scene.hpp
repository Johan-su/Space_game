#pragma once
#include "../ecs.hpp"

struct scene
{
    const char *name;
    Ecs::Registry registry;
};

typedef struct scene scene;

