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
        auto *reg = new Registry_data();
        Registry_functions::init(reg);









        Registry_functions::clean(reg);
        delete reg;
        reg = nullptr;
        return 0;
    }
}