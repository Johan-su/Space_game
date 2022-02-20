#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
#include "Components.hpp"
#include "MemoryManager.hpp"
#include "ComponentManager.hpp"

#include "string.h"




bool Component_functions::init(Memory_pool *mm, Component_data *cdata)
{
    memset(cdata->m_array_init,           0, sizeof(cdata->m_array_init[0])           * MAX_COMPONENT_TYPES);
    memset(cdata->m_array_sizes,          0, sizeof(cdata->m_array_sizes[0])          * MAX_COMPONENT_TYPES);
    memset(cdata->m_component_alignments, 0, sizeof(cdata->m_component_alignments[0]) * MAX_COMPONENT_TYPES);
    memset(cdata->m_component_sizes,      0, sizeof(cdata->m_component_sizes[0])      * MAX_COMPONENT_TYPES);
    memset(cdata->m_componentArrays,      0, sizeof(cdata->m_componentArrays[0])      * MAX_COMPONENT_TYPES);

    cdata->m_componentTypesCount = 0;




    return 0;
}


bool Component_functions::clean(Memory_pool *mm, Component_data *cdata)
{
    for(size_t i = 0; i < MAX_COMPONENT_TYPES; ++i)
    {
        if(cdata->m_array_sizes[i])
        {
            Memory::dealloc(mm, (char*)(cdata->m_componentArrays + i), cdata->m_array_sizes[i]);
        }
    }
    
    return 0;
}


void Component_functions::destroy_entity(Component_data *cdata, Entity e)
{
    assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

    for(size_t i = 0; i < cdata->m_componentTypesCount; ++i)
    {
        assert(cdata->m_array_init[i], "disordered/uninitalized componentArrays");

        void *comparray      = cdata->m_componentArrays[i];
        size_t &compsize     = cdata->m_component_sizes[i];
        size_t &size         = *(size_t*)(comparray);
        Entity *sparse_array = (Entity*)((size_t*)(comparray) + 1);
        Entity *entity_list  = (Entity*)((size_t*)(comparray) + 1) + 1;
        char *dense_array    = (char*)((Entity*)((size_t*)(comparray) + 1) + 2);


        assert(size > 0, "array size is 0");

        Entity laste = entity_list[size - 1];

        memcpy( static_cast<void*>(&(dense_array[sparse_array[e] * compsize])), // high risk of segfault/exception
                static_cast<void*>(&(dense_array[sparse_array[laste] * compsize])), 
                compsize);

        sparse_array[laste] = sparse_array[e];
        
        sparse_array[e] = ENTITY_NULL;
        --size;
    }

}

size_t Component_functions::get_id()
{
    static size_t id_counter = 0;
    return id_counter++;
}
