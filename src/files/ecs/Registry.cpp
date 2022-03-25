#include "Registry.hpp"



void Registry_functions::init(Registry_data *rdata, void (event_listener)(size_t))
{
    assert(rdata != nullptr, "Registry_data cannot be NULL");

    auto &mm     = rdata->mm;
    auto &edata  = rdata->edata;
    auto &evdata = rdata->evdata;
    auto &cdata  = rdata->cdata;

    mm = (Memory_pool*)malloc(sizeof(Memory_pool));

    mm->m_MemoryActive = false;

    Memory::init(mm);

    edata  = Memory::alloc<Entity_data>(mm);
    evdata = Memory::alloc<event_data>(mm);
    cdata  = Memory::alloc<Component_data>(mm);

    Entity_functions::init(mm, edata);
    Event_functions::init(evdata, event_listener);
    Component_functions::init(cdata);
}


void Registry_functions::clean(Registry_data *rdata)
{
    auto &mm     = rdata->mm;
    auto &edata  = rdata->edata;
    auto &evdata = rdata->evdata;
    auto &cdata  = rdata->cdata;

    Component_functions::clean(mm, cdata);
    Event_functions::clean(mm, evdata);
    Entity_functions::clean(mm, edata);

    Memory::dealloc(mm, cdata, 1);
    Memory::dealloc(mm, evdata, 1);
    Memory::dealloc(mm, edata, 1);
    
    Memory::clean(mm);
    free(mm);

    mm      = nullptr;
    edata   = nullptr;
    cdata   = nullptr;
}


Entity Registry_functions::create_entity(Registry_data *rdata)
{
    auto *edata = rdata->edata;

    Entity e = Entity_functions::create_entity(edata);

    return e;    
}


void Registry_functions::destroy_entity(Registry_data *rdata, Entity e)
{
    auto *edata = rdata->edata;
    auto *cdata = rdata->cdata;


    Component_functions::destroy_entity(cdata, e);
    Entity_functions::destroy_entity(edata, e);
}


    

