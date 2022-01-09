#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
#include "Signature.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"
#include "MemoryManager.hpp"
#include "ComponentManager.hpp"

#include <string>


bool Component_functions::init(Memory_pool *mm, Component_data *cdata)
{
    #define STRUCT_GEN(NAME, vargs...) \
    cdata->m_ ## NAME = Memory::alloc<NAME ## _array>(mm); \
    for(size_t i = 0; i < MAX_ENTITY_AMOUNT; ++i) \
    { \
        cdata->m_ ## NAME->entity_indicies[i] = MAX_ENTITY_AMOUNT - 1; \
    }

    #define DATA_GEN(TYPE, VAR)

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)

    #undef STRUCT_GEN
    #undef DATA_GEN

    return 0;
}

bool Component_functions::clean(Memory_pool *mm, Component_data *cdata)
{
    #define STRUCT_GEN(NAME, vargs...) Memory::dealloc(mm, cdata->m_ ## NAME);
    #define DATA_GEN(TYPE, VAR)

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)

    #undef STRUCT_GEN
    #undef DATA_GEN
    return 0;     
}


uint64_t Component_functions::getId(Component_data *cdata) // should not be called directly
{
    assert(cdata->m_componentIdCount != 0, "More than " + std::to_string(MAX_COMPONENT_TYPES) + " components registered");
    uint64_t tmp = cdata->m_componentIdCount;
    cdata->m_componentIdCount = cdata->m_componentIdCount << 1;
    return tmp;    
}

template <typename T>
Signature Component_functions::get_component_signature(Component_data *cdata)
{
    static Signature component_signature = {getId(cdata)};
    return component_signature;
}




template <typename T>
void Component_functions::set_component(Component_data *cdata, Entity e, T comp)
{
    assert(false, "non specialized template");
}


#define STRUCT_GEN(NAME, vargs...) \
template<> \
void Component_functions::set_component<NAME ## _component> \
(Component_data *cdata, Entity e, NAME ## _component comp) \
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
    size_t& ar_size = comparray->array_size; \
    vargs \
    e_list[e_ind[e]] = e_list[ar_size]; \
    e_ind[e_list[ar_size]] = e_ind[e]; \
    e_ind[e] = MAX_ENTITY_AMOUNT - 1; \
    --ar_size; \
}

#define DATA_GEN(TYPE, VAR) \
comparray->VAR[e_ind[e]] = comparray->VAR[ar_size];

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
#undef STRUCT_GEN
#undef DATA_GEN

//TODO:(johan) finish https://gist.github.com/dakom/82551fff5d2b843cbe1601bbaff2acbf
template <typename T>
View<T> & Component_functions::get_view(Component_data *cdata) //--
{
    assert(false, "no template specialization");
    return *(View<T>*)0;
}

#define STRUCT_GEN(NAME, vargs...) \
template<> \
View<NAME ## _component> & Component_functions::get_view<NAME ## _component>(Component_data *cdata) \
{ \
     return *(View<NAME ## _component>*)0; \
}
#define DATA_GEN(TYPE, VAR)

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
#undef STRUCT_GEN
#undef DATA_GEN



void Component_functions::destroy_entity(Component_data *cdata, Entity e, Signature sig) //--
{
#define STRUCT_GEN(NAME, vargs...) \
if (( sig & get_component_signature<NAME ## _component>(cdata) ) == get_component_signature<NAME ## _component>(cdata)) \
{ \
Component_functions::destroy_component<NAME ## _component>(cdata, e); \
}

#define DATA_GEN(TYPE, VAR)

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
#undef STRUCT_GEN
#undef DATA_GEN


}
