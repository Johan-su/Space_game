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
    #define STRUCT_GEN(NAME, vargs...)                                 \
    cdata->m_ ## NAME = Memory::alloc<NAME ## _array>(mm, 1);          \
    for(size_t i = 0; i < MAX_ENTITY_AMOUNT; ++i)                      \
    {                                                                  \
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
    #define STRUCT_GEN(NAME, vargs...) Memory::dealloc(mm, cdata->m_ ## NAME, 1);
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




void Component_functions::destroy_entity(Component_data *cdata, Entity e, Signature sig) //--
{
#define STRUCT_GEN(NAME, vargs...)                                                                                      \
if (( sig & get_component_signature<NAME ## _component>(cdata) ) == get_component_signature<NAME ## _component>(cdata)) \
{                                                                                                                       \
    Component_functions::destroy_component<NAME ## _component>(cdata, e);                                               \
}

#define DATA_GEN(TYPE, VAR)

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
#undef STRUCT_GEN
#undef DATA_GEN


}
