#pragma once
#ifdef PROFILE_FUNCTIONS

#include <stdio.h>
#include "platform/platform.hpp"

#define BEGIN_PROFILE_BLOCK(...) \
U64 PROFILE_TIMER____ = deltaTime::get_micro_time()


#define END_PROFILE_BLOCK(...) \
PROFILE_TIMER____ = deltaTime::get_micro_time() - PROFILE_TIMER____; \
printf("DEBUG: time_elapsed %llu\n", PROFILE_TIMER____)






#else
#define BEGIN_PROFILE_BLOCK(...)
#define END_PROFILE_BLOCK(...)
#endif