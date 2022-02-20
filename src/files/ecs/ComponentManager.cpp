#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
#include "Components.hpp"
#include "MemoryManager.hpp"
#include "ComponentManager.hpp"

#include "string.h"

bool Component_functions::init(Memory_pool *mm, Component_data *cdata)
{
    cdata->m_componentTypesCount = 0;
    memset(cdata->m_array_sizes, 0, sizeof(cdata->m_array_sizes[0]) * MAX_COMPONENT_TYPES);

    memset(cdata->m_array_init, 0, sizeof(bool) * MAX_COMPONENT_TYPES);

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
}

size_t Component_functions::get_id()
{
    static size_t id_counter = 0;
    return id_counter++;
}
