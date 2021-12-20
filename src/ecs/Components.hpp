#pragma once
#include "Entity.hpp"
#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
#include <cstdint>

//#define _DEBUG


#define ENTITY_LIST_INDICIES Entity EntityList[MAX_ENTITY_AMOUNT]; \
   uint64_t EntityIndices[MAX_ENTITY_AMOUNT]; \
   uint64_t EntityAmount; \


#define POSITIONLIST \
  to_array_field(float, x) \
  to_array_field(float, y) \

#define HEALTHLIST \
  to_array_field(float, health) \
  to_array_field(float, health_regen) \


#define STRUCT_GEN(NAME, LIST)                  \
  struct NAME ## Component                      \
  {LIST};                                       \



#define ARRAY_GEN(NAME, LIST)                   \
  struct NAME ## Array                          \
  {LIST ENTITY_LIST_INDICIES};                  \


#define to_array_field(TYPE, NAME) TYPE NAME;

STRUCT_GEN(Position, POSITIONLIST)
STRUCT_GEN(Health, HEALTHLIST)

#undef to_array_field

#define to_array_field(TYPE, NAME)                                 \
  TYPE NAME[MAX_ENTITY_AMOUNT];                                    \


ARRAY_GEN(Position, POSITIONLIST)
ARRAY_GEN(Health, HEALTHLIST)


#undef to_array_field
