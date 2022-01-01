#include "../Entity.hpp"
#include "../Signature.hpp"
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

void health_system::update(Component_data *cdata, Entity_data *edata, Signature sig)
{
    auto data = Component_functions::get_view<Health_component>(cdata);
}