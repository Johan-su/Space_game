#pragma once
#include "../Registry.hpp"
#include "../system.hpp"

class health_system :  System
{
    void init(Signature syssig);
    void clean();
    void update(Registry_data *rdata, Signature sig);
};