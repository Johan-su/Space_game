#pragma once
#include "../../src/files/ecs/ecs.hpp"


namespace ecs_view_test
{
    namespace R_f = Registry_functions;

    int test()
    {
        auto *rd = new Registry_data();
        Registry_functions::init(rd);

        auto &mm = rd->mm;
        auto &cdata = rd->cdata;

        Registry_functions::init_component<Position>(rd);
        Registry_functions::init_component<Size>(rd);

        Entity elist[100];
        Entity elist1[50];
        
        for(size_t i = 0; i < 100; ++i)
        {
            elist[i] = Registry_functions::create_entity(rd);
            auto pc1 = Position();
            pc1      = {float(elist[i]), float(elist[i])};

            Registry_functions::set_component(rd, elist[i], pc1);
        }


        for(size_t i = 0; i < 50; ++i)
        {
            elist1[i] = Registry_functions::create_entity(rd);
            auto sz1  = Size();
            sz1       = {10 * float(elist[i]), 10 * float(elist[i])};

            Registry_functions::set_component(rd, elist[i], sz1);
        }







        Registry_functions::clean(rd);
        delete rd;
        rd = nullptr;
        return 0;
    }
}