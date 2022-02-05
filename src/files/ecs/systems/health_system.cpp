#include "../Entity.hpp"
#include "../View_Groups.hpp"
#include "../EntityManager.hpp"
#include "../ComponentManager.hpp"
#include "health_system.hpp"

void health_system::init()
{
} 

void health_system::clean()
{

}

void health_system::update(Registry_data *rdata)
{
    auto data = Component_functions::get_view<Health_component>(rdata->cdata);
}