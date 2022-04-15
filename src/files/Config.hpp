#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>

struct config_data
{
    uint16_t screen_width;
    uint16_t screen_height;

    uint16_t FPS_target;

};


namespace Config
{
    void init(config_data *settings, const char *path);
    void clean(config_data *settings);


}