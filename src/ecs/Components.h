#pragma once
#include <cstdint>

#define to_array_field(type, name) type name[MAX_ENTITY_AMOUNT];

#define PositionComponent \
  to_array_field(float, x) \
  to_array_field(float, y) \

#define HealthComponent \
  to_array_field(float, health) \
  to_array_field(float, health_regen) \

struct Component_data
{
  PositionComponent
  HealthComponent
};

#undef to_array_field
