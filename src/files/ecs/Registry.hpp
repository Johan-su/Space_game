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

    template<typename T>
    void init_component(Registry_data *rdata)
    {
        namespace C_F = Component_functions;

        auto *cdata = rdata->cdata;
        auto *mm = rdata->mm;


        C_F::init_component<T>(mm, cdata);        
    }

    template <typename T>
    void set_component(Registry_data *rdata, Entity e, T& comp)
    {
        namespace E_F = Entity_functions;
        namespace C_F = Component_functions;

        auto *cdata = rdata->cdata;
        auto *edata = rdata->edata;

        C_F::set_component<T>(cdata, e, comp);
    }

    template<typename T>
    void destroy_component(Registry_data *rdata, Entity e) //TODO(Johan) add all necessary deletions
    {
        namespace C_F = Component_functions;
        
        auto *cdata = rdata->cdata;

        C_F::destroy_component<T>(cdata, e);
    }


}