#pragma once
#include "../../src/files/ecs/ecs.hpp"


namespace ecs_view_test
{
    int test()
    {
        auto *rd = new Registry_data();
        Registry_functions::init(rd);

        auto *mm = rd->mm;

        Entity elist[100];
        
        for(int i = 0; i < 100; ++i)
        {
            elist[i] = Registry_functions::create_entity(rd);
            auto pc1 = Position_component();

            pc1 = {float(elist[i]), float(elist[i])};
            Registry_functions::set_component(rd, elist[i], pc1);
        }


        auto view = Registry_functions::get_view<Position_component>(rd, Registry_functions::get_component_signature<Position_component>(rd));





        Registry_functions::clean(rd);
        delete rd;
        rd = nullptr;
        return 0;
    }
}