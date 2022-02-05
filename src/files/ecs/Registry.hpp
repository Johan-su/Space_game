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




}

namespace Registry_functions
{

    template <typename T>
    void set_component(Registry_data *rdata, Entity e, T& comp)
    {
        namespace E_F = Entity_functions;
        namespace C_F = Component_functions;

        auto *cdata = rdata->cdata;
        auto *edata = rdata->edata;

        C_F::set_component<T>(cdata, e, comp);
    }

    



    template <typename T, typename... args>
    View<T> get_view(Registry_data *rdata)
    {
        //return nullptr; //Component_functions::get_view<T, args...>(rdata->cdata);  //TODO(johan) fix
    }


    template <typename T>
    PartialView<T> get_partial_view(Registry_data *rdata)
    {

    }


}