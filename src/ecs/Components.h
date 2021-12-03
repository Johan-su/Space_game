#pragma once
#include "Entity.h"
#include "ecs_constants.h"
#include <cstdint>

//#define _DEBUG


#define ENTITY_LIST_INDICIES Entity EntityList[MAX_ENTITY_AMOUNT]; \
   uint64_t EntityIndices[MAX_ENTITY_AMOUNT]; \


#define POSITIONLIST \
  to_array_field(float, x) \
  to_array_field(float, y) \

#define HEALTHLIST \
  to_array_field(float, health) \
  to_array_field(float, health_regen) \


#ifndef _DEBUG

#define STRUCT_GEN(NAME, LIST)                  \
  struct NAME ## Component                      \
  {LIST};                                       \

#else

#define STRUCT_GEN(NAME, LIST)                  \
  struct NAME ## Component                      \
  {LIST Entity currentEntity;};                 \

#endif



#define ARRAY_GEN(NAME, LIST)                   \
  struct NAME ## Array                          \
  {LIST ENTITY_LIST_INDICIES};                  \


#define to_array_field(TYPE, NAME) TYPE NAME;

STRUCT_GEN(Position, POSITIONLIST)
STRUCT_GEN(Health, HEALTHLIST)

#undef to_array_field

#define to_array_field(TYPE, NAME) TYPE NAME[MAX_ENTITY_AMOUNT]; \
  uint64_t NAME ## _size;                                        \


ARRAY_GEN(Position, POSITIONLIST)
ARRAY_GEN(Health, HEALTHLIST)


#undef to_array_field
