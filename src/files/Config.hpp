#pragma once

#include <stdint.h>

struct config_data
{
    uint16_t screen_width;
    uint16_t screen_height;

    uint16_t FPS_target;

};


namespace Internal
{
    void init_config(config_data *settings, const char *path);
}