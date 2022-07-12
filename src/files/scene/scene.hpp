#pragma once
#include "../ecs/ecs.hpp"

struct scene
{
    const char *name;
    Ecs::Registry registry;
};

typedef struct scene scene;

