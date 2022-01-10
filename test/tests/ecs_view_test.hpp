#include "../../src/files/ecs/ecs.hpp"


namespace ecs_view_test
{
    class health_system : System
    {
        void update(Registry_data *rdata)
        {
            auto & view = Registry_functions::get_view<Health_component>(rdata, m_Systemsignature);
            //for(auto& tuple ) /TODO(johan): finish test
        }
    };
    int test()
    {
        auto *rd = new Registry_data();
        Registry_functions::init(rd);

        auto *mm = rd->mm;

        Entity e1 = Registry_functions::create_entity(rd);

        auto pc1 = Position_component();
        pc1 = {float(e1), float(e1)};

        Registry_functions::set_component(rd, e1, pc1);





        Registry_functions::clean(rd);
        delete rd;
        rd = nullptr;
        return 0;
    }
}