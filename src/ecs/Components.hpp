#pragma once
#include "Entity.hpp"
#include "ecs_constants.hpp"
#include "ecs_assert.hpp"

//#define _DEBUG
#define COMPONENT_LIST(STRC, DATA) \
STRC(Position, \
DATA(float, x) \
DATA(float, y) \
) \
STRC(Health, \
DATA(float, hp) \
DATA(float, hp_regen) \
) \


// struct component generator
#define STRUCT_GEN(NAME, vargs...) \
struct NAME ## _component {vargs};

#define DATA_GEN(TYPE, VAR) \
TYPE VAR;

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)


#undef STRUCT_GEN
#undef DATA_GEN