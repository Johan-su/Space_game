#include "Registry.hpp"




void Registry_functions::init(Registry_data *rdata)
{
    auto &mm      = rdata->mm;
    auto &edata   = rdata->edata;
    auto &cdata   = rdata->cdata;
    auto &sysdata = rdata->sysdata;

    mm = new Memory_pool();
    Memory::init(mm);

    edata = Memory::alloc<Entity_data>(mm);
    cdata = Memory::alloc<Component_data>(mm);
    sysdata = Memory::alloc<System_data>(mm);

    Entity_functions::init(mm, edata);
    Component_functions::init(mm, cdata);
    System_functions::init(mm, sysdata);
}


void Registry_functions::clean(Registry_data *rdata)
{
    auto &mm      = rdata->mm;
    auto &edata   = rdata->edata;
    auto &cdata   = rdata->cdata;
    auto &sysdata = rdata->sysdata;

    System_functions::clean(mm, sysdata);
    Component_functions::clean(mm, cdata);
    Entity_functions::clean(mm, edata);

    Memory::dealloc(mm, sysdata, 1);
    Memory::dealloc(mm, cdata, 1);
    Memory::dealloc(mm, edata, 1);
    
    Memory::clean(mm);
    free(mm);

    mm      = nullptr;
    edata   = nullptr;
    cdata   = nullptr;
    sysdata = nullptr;
}


Entity Registry_functions::create_entity(Registry_data *rdata)
{
    auto & edata = rdata->edata;

    Entity e = Entity_functions::create_entity(edata);

    return e;    
}


void Registry_functions::destroy_entity(Registry_data *rdata, Entity e)
{
    auto &edata = rdata->edata;
    auto &cdata = rdata->cdata;


    Component_functions::destroy_entity(cdata, e);


    Entity_functions::destroy_entity(edata, e);
}


    

