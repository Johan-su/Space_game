#pragma once
#include "ecs_constants.hpp"
#include <cstdint>
static_assert(MAX_COMPONENT_TYPES <= (sizeof(uint64_t) * 8), "Signatures cannot match max amount of components");

typedef uint64_t Signature;