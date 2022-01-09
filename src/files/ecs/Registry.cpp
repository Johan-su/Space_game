#include "Registry.hpp"




void Registry_functions::init(Registry_data *rdata)
{
    auto & mm = rdata->mm;
    auto & edata = rdata->edata;
    auto & cdata = rdata->cdata;
    auto & sysdata = rdata->sysdata;

    mm = new Memory_pool();
    Memory::init(mm);

    edata = Memory::alloc<Entity_data>(mm, 1);
    cdata = Memory::alloc<Component_data>(mm, 1);
    sysdata = Memory::alloc<System_data>(mm, 1);

    Entity_functions::init(mm, edata);
    Component_functions::init(mm, cdata);
    System_functions::init(mm, sysdata);
}

void Registry_functions::clean(Registry_data *rdata)
{
    auto & mm = rdata->mm;
    auto & edata = rdata->edata;
    auto & cdata = rdata->cdata;
    auto & sysdata = rdata->sysdata;

    System_functions::clean(mm, sysdata);
    Component_functions::clean(mm, cdata);
    Entity_functions::clean(mm, edata);

    Memory::dealloc(mm, sysdata, 1);
    Memory::dealloc(mm, cdata, 1);
    Memory::dealloc(mm, edata, 1);
    
    Memory::clean(mm);
    free(mm);

    mm = nullptr;
    edata = nullptr;
    cdata = nullptr;
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
    auto & cdata = rdata->cdata;

    auto sig = edata->m_signatures[e];

    Component_functions::destroy_entity(cdata, e, sig);


    Entity_functions::destroy_entity(edata, e);
}

/*Signature get_entity_signature(Registry_data *rdata, Entity e)
{
    return Entity_functions::get_entity_signature(rdata->edata, e);
}*/
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

