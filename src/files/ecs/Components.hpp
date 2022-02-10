#pragma once
#include "Entity.hpp"
#include "ecs_constants.hpp"
#include "ecs_assert.hpp"


#define COMPONENT_LIST(STRC, DATA) \
STRC(Position,                     \
DATA(float, x)                     \
DATA(float, y)                     \
)                                  \
STRC(Size,                         \
DATA(float, width)                 \
DATA(float, height)                \
)                                  \
STRC(Health,                       \
DATA(float, hp)                    \
DATA(float, hp_regen)              \
)                                  \
STRC(Test,                         \
DATA(float, a)                     \
DATA(float, b)                     \
DATA(int, c)                       \
DATA(bool, d)                      \
DATA(short, e)                     \
)


// enum component generator
enum
{

#define STRUCT_GEN(NAME, vargs...) \
NAME ##_CONSTANT,

#define DATA_GEN(TYPE, VAR) \

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)


#undef STRUCT_GEN
#undef DATA_GEN

};


// struct component generator
#define STRUCT_GEN(NAME, vargs...) \
struct NAME ## _component {vargs};

#define DATA_GEN(TYPE, VAR) \
TYPE VAR;

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)


#undef STRUCT_GEN
#undef DATA_GEN

//######## introspection ############

// Member amount
#define STRUCT_GEN(NAME, vargs...) \
const size_t NAME ## _MEMBER_AMOUNT = 0 vargs; // expands to  0 ( + 1 + 1 + 1 + ... 1; ) 

#define DATA_GEN(TYPE, VAR) \
+ 1

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)

#undef STRUCT_GEN
#undef DATA_GEN



// 











