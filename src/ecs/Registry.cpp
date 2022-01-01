#include "Registry.hpp"




void Registry_functions::init(Registry_data *rdata)
{
    auto & mm = rdata->mm;
    auto & edata = rdata->edata;
    auto & compdata = rdata->compdata;
    auto & sysdata = rdata->sysdata;

    mm = new Memory_pool();
    Memory::init(mm);

    edata = Memory::alloc<Entity_data>(mm);
    compdata = Memory::alloc<Component_data>(mm);
    sysdata = Memory::alloc<System_data>(mm);

    Entity_functions::init(mm, edata);
    Component_functions::init(mm, compdata);
    System_functions::init(mm, sysdata);
}

void Registry_functions::clean(Registry_data *rdata)
{
    auto & mm = rdata->mm;
    auto & edata = rdata->edata;
    auto & compdata = rdata->compdata;
    auto & sysdata = rdata->sysdata;

    System_functions::clean(mm, sysdata);
    Component_functions::clean(mm, compdata);
    Entity_functions::clean(mm, edata);

    Memory::dealloc(mm, sysdata);
    Memory::dealloc(mm, compdata);
    Memory::dealloc(mm, edata);
    
    Memory::clean(mm);
    free(mm);

    mm = nullptr;
    edata = nullptr;
    compdata = nullptr;
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
    auto & edata = rdata->edata;
    auto & compdata = rdata->compdata;

    Component_functions::destroy_entity(compdata, e);


    Entity_functions::destroy_entity(edata, e);
}

