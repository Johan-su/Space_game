#pragma once
#ifdef PROFILE_FUNCTIONS

#include <stdio.h>
#include "platform/platform.hpp"


struct ProfileBlock
{
    U64 timer;
    ProfileBlock()
    {
        timer = Platform::get_micro_time();
    }

    ~ProfileBlock()
    {
        printf("DEBUG: %s %lluus\n", __PRETTY_FUNCTION__, Platform::get_micro_time() - timer); 
    }
};

#define HELPER_(x) x
#define PROFILE_BLOCK()  ProfileBlock block##__COUNTER__ = ProfileBlock()





#else
#define PROFILE_BLOCK(...)
#endif