#include "ecs_constants.hpp"
#include "Signature.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"
#include "MemoryManager.hpp"
#include "ComponentManager.hpp"

#include <cstring>



bool Component_functions::init(Memory_pool *mm, Component_data *compdata)
{
    #define STRUCT_GEN(NAME, vargs...) compdata->m_ ## NAME = Memory::alloc<NAME ## _array>(mm);
    #define DATA_GEN(TYPE, VAR)

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)

    #undef STRUCT_GEN
    #undef DATA_GEN

    return 0;
}

bool Component_functions::clean(Memory_pool *mm, Component_data *compdata)
{
    #define STRUCT_GEN(NAME, vargs...) Memory::dealloc(mm, compdata->m_ ## NAME);
    #define DATA_GEN(TYPE, VAR)

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)

    #undef STRUCT_GEN
    #undef DATA_GEN
    return 0;     
}

uint64_t Component_functions::getId(Component_data *cdata)
{
    assert(cdata->m_componentIdCount != 0, "More than " + std::to_string(MAX_COMPONENT_TYPES) + " components registered");
    uint64_t tmp = cdata->m_componentIdCount;
    cdata->m_componentIdCount = cdata->m_componentIdCount << 1;
    return tmp;    
}


template <typename T>
void Component_functions::set_component(Component_data *cdata, Entity e, T& comp)
{
    assert(false, "non specialized template");
}


#define STRUCT_GEN(NAME, vargs...) \
template<> \
void Component_functions::set_component<NAME ## _component> \
(Component_data *cdata, Entity e, NAME ## _component& comp) \
{ \
    NAME ## _array *comparray = cdata->m_ ## NAME; \
    Entity *e_ind = comparray->entity_indicies; \
    Entity *e_list = comparray->entity_list; \
    e_ind[e] = comparray->array_size++; \
    e_list[e_ind[e]] = e; \
    vargs\
} \

#define DATA_GEN(TYPE, VAR) \
comparray->VAR[e_ind[e]] = comp.VAR;

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
#undef STRUCT_GEN
#undef DATA_GEN



template<typename T>
void Component_functions::destroy_component(Component_data *cdata, Entity e)
{
    assert(false, "non specialized template");
}

#define STRUCT_GEN(NAME, vargs...) \
template<> \
void Component_functions::destroy_component<NAME ## _component> \
(Component_data *cdata, Entity e) \
{ \
    NAME ## _array *comparray = cdata->m_ ## NAME; \
    Entity *e_ind = comparray->entity_indicies; \
    Entity *e_list = comparray->entity_list; \
    size_t& ar_size = compoarray->array_size; \
    vargs \
    e_list[e_ind[e]] = e_list[ar_size]; \
    e_ind[e_list[ar_size]] = e_ind[e]; \
    e_ind[e] = MAX_ENTITY_AMOUNT + 1; \
    --ar_size; \
} \
//TODO:(johan) finish https://gist.github.com/dakom/82551fff5d2b843cbe1601bbaff2acbf
#define DATA_GEN(TYPE, VAR) \
comparray->VAR[e_ind[e]] = VAR[ar_size]; \ 

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
#undef STRUCT_GEN
#undef DATA_GEN


template <typename T>
T Component_functions::get_view(Component_data *cdata, Entity e)
{

}

