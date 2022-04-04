#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
#include "MemoryManager.hpp"
#include "ComponentManager.hpp"

#include "string.h"


using namespace Ecs;

/*struct Component_data
{
    void *m_componentArrays[MAX_COMPONENT_TYPES];
    size_t m_component_sizes[MAX_COMPONENT_TYPES];
    size_t m_component_alignments[MAX_COMPONENT_TYPES];
    size_t m_componentTypesCount;
    bool m_array_init[MAX_COMPONENT_TYPES];
};*/


bool Component_functions::init(Component_data *cdata) // TODO(johan) check if alignment actually works
{
    memset(cdata->m_array_init,           0, sizeof(cdata->m_array_init[0])           * MAX_COMPONENT_TYPES);
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
        if(cdata->m_array_init[i])
        {
            Memory::dealloc(mm, cdata->m_component_sizes[i], cdata->m_component_alignments[i], cdata->m_componentArrays[i],  MAX_COMPONENT_TYPES);
        }
    }
    
    return 0;
}


void Component_functions::destroy_entity(Component_data *cdata, Entity e)
{
    ECS_assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

    for(size_t i = 0; i < cdata->m_componentTypesCount; ++i)
    {
        ECS_assert(cdata->m_array_init[i], "disordered/uninitalized componentArrays");

        void *comparray      = cdata->m_componentArrays[i];
        size_t &compsize     = cdata->m_component_sizes[i];
        size_t *size_pointer = (size_t*)(comparray);
        Entity *sparse_array = (Entity*)(size_pointer + 1);
        Entity *entity_list  = sparse_array + MAX_ENTITY_AMOUNT;
        char *dense_array    = (char*)(entity_list + MAX_ENTITY_AMOUNT);

        size_t size = *size_pointer;


        if(size == 0) {
            ECS_dbg(printf("DEBUG: Ignoring destroy entity on empty array\n"));
            break;
        }

        Entity laste = entity_list[size - 1];

        memcpy( static_cast<void*>(&(dense_array[sparse_array[e] * compsize])), // high risk of segfault/exception
                static_cast<void*>(&(dense_array[sparse_array[laste] * compsize])), 
                compsize);

        sparse_array[laste] = sparse_array[e];
        
        sparse_array[e] = ENTITY_NULL;
        --size;
    }

}
