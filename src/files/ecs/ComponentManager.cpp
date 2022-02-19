#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
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
        cdata->m_ ## NAME->entity_indicies[i] = ENTITY_NULL;           \
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


void Component_functions::destroy_entity(Component_data *cdata, Entity e) 
{
    #define STRUCT_GEN(NAME, vargs...) \
    Component_functions::destroy_component<NAME ## _component>(cdata, e);



    #define DATA_GEN(TYPE, VAR)

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
    #undef STRUCT_GEN
    #undef DATA_GEN


}
