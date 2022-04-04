#pragma once
#include "../../src/files/ecs/ecs.hpp"


struct Position
{
    float x;
    float y;
};


struct Size
{
    float width;
    float height;
};

void noop(size_t t, const void *r){}

namespace ecs_view_test
{
    using namespace Ecs;
    int test()
    {
        auto *rd = Ecs::create_registry();
        Ecs::init(rd, noop);

        //auto &mm = rd->mm;
        auto &cdata = rd->cdata;

        Ecs::init_component<Position>(rd);
        Ecs::init_component<Size>(rd);

        #define ELIST_CAP 100
        #define ELIST1_CAP 150
        #define ELIST2_CAP 100
        Ecs::destroy_entity(rd, 340);
        for(size_t i = 0; i < ELIST_CAP; ++i)
        {
            Entity e  = Ecs::create_entity(rd);
            auto pc1 = Position();
            pc1      = {-1 * float(e), -1 * float(e)};

            Ecs::set_component(rd, e, pc1);
        }


        for(size_t i = 0; i < ELIST1_CAP; ++i)
        {
            Entity e  = Ecs::create_entity(rd);
            auto sz1  = Size();
            sz1       = {float(e), float(e)};

            Ecs::set_component(rd, e, sz1);
        }


        for(size_t i = 0; i < ELIST2_CAP; ++i)
        {
            Entity e  = Ecs::create_entity(rd);
            auto sz1  = Size();
            sz1       = {float(e), float(e)};
            auto pos  = Position();
            pos       = {-1 * float(e), -1 * float(e)};

            Ecs::set_component(rd, e, sz1);            
            Ecs::set_component(rd, e, pos);            
        }

        Ecs::destroy_entity(rd, 340);

        auto view = Component_functions::get_view<Position, Size>(cdata);


        for(int i = 0; i < view.size; ++i)
        {
            Entity e     = view.entity_list[i];
            Position pos = view.comparray[i];

            std::cout << "Entity: " << e << ", x: " << pos.x << ", y: " << pos.y << "\n";
        }







        Ecs::clean(rd);
        delete rd;
        rd = nullptr;
        return 0;
    }
}