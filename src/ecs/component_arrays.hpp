#pragma once
#include "ecs_constants.hpp"
#include "Entity.hpp"
#include "Components.hpp"


// struct component array generator
#define STRUCT_GEN(NAME, vargs...) \
struct NAME ## _array {Entity entity_list; Entity entity_indicies; size_t array_size; vargs};

#define DATA_GEN(TYPE, VAR) \
TYPE VAR[MAX_ENTITY_AMOUNT];

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)

#undef STRUCT_GEN
#undef DATA_GEN


/*#define ENTITY_LIST_INDICIES Entity EntityList[MAX_ENTITY_AMOUNT]; \
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


#undef to_array_field*/

