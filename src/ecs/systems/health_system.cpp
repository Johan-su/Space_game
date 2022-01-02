#include "../Entity.hpp"
#include "../Signature.hpp"
#include "../View_Groups.hpp"
#include "../EntityManager.hpp"
#include "../ComponentManager.hpp"
#include "health_system.hpp"

void health_system::init(Signature syssig)
{
    m_Systemsignature = syssig;
} 

void health_system::clean()
{

}

void health_system::update(Registry_data *rdata, Signature sig)
{
    auto data = Component_functions::get_view<Health_component>(rdata->cdata);
}