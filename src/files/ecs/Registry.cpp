#include "Registry.hpp"



void Registry_functions::init(Registry_data *rdata, void (event_listener)(size_t, const void*))
{
    ECS_assert(rdata != nullptr, "Registry_data cannot be NULL");


    rdata->mm = (Memory_pool*)malloc(sizeof(Memory_pool));

    rdata->mm->m_MemoryActive = false;

    Memory::init(rdata->mm);

    rdata->edata  = Memory::alloc<Entity_data>(rdata->mm);
    rdata->evdata = Memory::alloc<event_data>(rdata->mm);
    rdata->cdata  = Memory::alloc<Component_data>(rdata->mm);

    Entity_functions::init(rdata->mm, rdata->edata);
    Event_functions::init(rdata->evdata, event_listener);
    Component_functions::init(rdata->cdata);
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


void Registry_functions::init_event(Registry_data *rdata, size_t event_id, size_t event_size, size_t event_alignment)
{
    Event_functions::init_event(rdata->evdata, event_id, event_size, event_alignment);
}


void Registry_functions::broadcast_event(Registry_data *rdata, size_t event_id, size_t event_size, size_t event_alignment, const void *event)
{
    Event_functions::broadcast_event(rdata->evdata, event_id, event_size, event_alignment, event);
}

    

