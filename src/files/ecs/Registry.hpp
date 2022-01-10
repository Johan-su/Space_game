#pragma once
#include "MemoryManager.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"
#include "View_Groups.hpp"

struct Registry_data
{
    Memory_pool *mm;
    Entity_data *edata;
    Component_data *cdata;
    System_data *sysdata;
};

namespace Registry_functions
{
    void init(Registry_data *rdata);
    void clean(Registry_data *rdata);

    Entity create_entity(Registry_data *rdata);
    void destroy_entity(Registry_data *rdata, Entity e);
    Signature get_entity_signature(Registry_data *rdata, Entity e);



    template <typename T>
    void set_component(Registry_data *rdata, Entity e, T& comp)
    {
    namespace E_F = Entity_functions;
    namespace C_F = Component_functions;
    auto *cdata = rdata->cdata;
    auto *edata = rdata->edata;

    C_F::set_component<T>(cdata, e, comp);
    E_F::set_entity_signature(edata, e, E_F::get_entity_signature(edata, e) | C_F::get_component_signature<T>(cdata));
    }



    template <typename T>
    View<T> & get_view(Registry_data *rdata, Signature sig)
    {
    return Component_functions::get_view<T>(rdata->cdata);
    }


    template <typename T>
    PartialView<T> get_partial_view(Registry_data *rdata, Signature sig)
    {

    }

}