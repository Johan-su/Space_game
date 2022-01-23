#pragma once
#include "ecs_constants.hpp"
#include <cstdint>

typedef uint64_t Signature;

static_assert(MAX_COMPONENT_TYPES <= (sizeof(Signature) * 8), "Signatures cannot match max amount of components");