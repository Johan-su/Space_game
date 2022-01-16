#pragma once
#include "ecs_constants.hpp"
#include "Entity.hpp"
#include "Components.hpp"


// struct component array generator
#define STRUCT_GEN(NAME, vargs...)             \
struct NAME ## _array                          \
{                                              \
    Entity entity_indicies[MAX_ENTITY_AMOUNT]; \
    Entity entity_list[MAX_ENTITY_AMOUNT];     \
    vargs                                      \
    size_t array_size;                         \
};

#define DATA_GEN(TYPE, VAR) \
TYPE VAR[MAX_ENTITY_AMOUNT];

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)

#undef STRUCT_GEN
#undef DATA_GEN
