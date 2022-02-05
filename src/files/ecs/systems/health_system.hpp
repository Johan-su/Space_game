#pragma once
#include "../Registry.hpp"
#include "../system.hpp"

class health_system :  System
{
    void init();
    void clean();
    void update(Registry_data *rdata);
};