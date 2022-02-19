#pragma once
#include "../../src/files/ecs/ecs.hpp"


namespace ecs_view_test
{
    namespace R_f = Registry_functions;

    int test()
    {
        auto *rd = new Registry_data();
        Registry_functions::init(rd);

        auto *mm = rd->mm;
        auto *cdata = rd->cdata;

        Entity elist[100];
        
        for(int i = 0; i < 100; ++i)
        {
            elist[i] = Registry_functions::create_entity(rd);
            auto pc1 = Position_component();

            pc1 = {float(elist[i]), float(elist[i])};
            Registry_functions::set_component(rd, elist[i], pc1);
        }


        size_t *result_buffer; //TODO(johan) fix bug here
        result_buffer = Component_functions::get_component_array_sizes<Position_component, Test_component, Health_component>(mm, cdata);


        for(int i = 0; i < 3; ++i)
        {
            std::cout << result_buffer[i] << ", ";
        }
        std::cout << "\n";




        //Collection coll = get_collection(Position_Component, Health_Component, Test_Component);


        Registry_functions::clean(rd);
        delete rd;
        rd = nullptr;
        return 0;
    }
}