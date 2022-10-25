#pragma once

#include "int.hpp"

struct config_data
{
    U16 screen_width;
    U16 screen_height;

    U16 FPS_target;

};


namespace Internal
{
    void init_config(config_data *settings, const char *path);
}