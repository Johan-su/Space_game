#pragma once


namespace health_system
{
    void init();
    void clean();
    void update(Component_data *cdata, Entity_data *edata, Signature sig);
}