#pragma once
#include "../../src/files/ecs/ecs.hpp"


namespace ecs_view_test
{
    namespace R_f = Registry_functions;

    int test()
    {
        auto *rd = new Registry_data();
        Registry_functions::init(rd);

        //auto &mm = rd->mm;
        auto &cdata = rd->cdata;

        Registry_functions::init_component<Position>(rd);
        Registry_functions::init_component<Size>(rd);

        #define ELIST_CAP 100
        #define ELIST1_CAP 150
        #define ELIST2_CAP 100
        Registry_functions::destroy_entity(rd, 340);
        for(size_t i = 0; i < ELIST_CAP; ++i)
        {
            Entity e  = Registry_functions::create_entity(rd);
            auto pc1 = Position();
            pc1      = {-1 * float(e), -1 * float(e)};

            Registry_functions::set_component(rd, e, pc1);
        }


        for(size_t i = 0; i < ELIST1_CAP; ++i)
        {
            Entity e  = Registry_functions::create_entity(rd);
            auto sz1  = Size();
            sz1       = {float(e), float(e)};

            Registry_functions::set_component(rd, e, sz1);
        }


        for(size_t i = 0; i < ELIST2_CAP; ++i)
        {
            Entity e  = Registry_functions::create_entity(rd);
            auto sz1  = Size();
            sz1       = {float(e), float(e)};
            auto pos  = Position();
            pos       = {-1 * float(e), -1 * float(e)};

            Registry_functions::set_component(rd, e, sz1);            
            Registry_functions::set_component(rd, e, pos);            
        }

        Registry_functions::destroy_entity(rd, 340);

        auto view = Component_functions::get_view<Position, Size>(cdata);


        for(int i = 0; i < view.size; ++i)
        {
            Entity e     = view.entity_list[i];
            Position pos = view.comparray[i];

            std::cout << "Entity: " << e << ", x: " << pos.x << ", y: " << pos.y << "\n";
        }







        Registry_functions::clean(rd);
        delete rd;
        rd = nullptr;
        return 0;
    }
}