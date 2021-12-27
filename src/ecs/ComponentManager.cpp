#include "Signature.hpp"
#include "Components.hpp"
#include "ComponentManager.hpp"

#include <cstring>



bool Component_functions::init(Component_data *cdata, Memory_pool *mem)
{
    cdata->m_componentIdCount = 1;
    cdata->m_positionArray = Memory::alloc<PositionArray>(mem);

    memset(cdata->m_positionArray->EntityIndices, 0xFF, sizeof(uint64_t) * MAX_ENTITY_AMOUNT);
    memset(cdata->m_positionArray->EntityList, 0, sizeof(Entity) * MAX_ENTITY_AMOUNT);

    cdata->m_positionArray->EntityAmount = 0;


    cdata->m_healthArray = Memory::alloc<HealthArray>(mem);

    return 0;
}

bool Component_functions::clean(Component_data *cdata, Memory_pool *mem)
{
    Memory::dealloc(mem, cdata->m_positionArray);
    Memory::dealloc(mem, cdata->m_healthArray);

    cdata->m_positionArray = nullptr;
    cdata->m_healthArray = nullptr;   
    return 0;     
}

uint64_t Component_functions::getId(Component_data *cdata)
{
    assert(cdata->m_componentIdCount != 0, "More than " + std::to_string(MAX_COMPONENT_TYPES) + " components registered");
    uint64_t tmp = cdata->m_componentIdCount;
    cdata->m_componentIdCount = cdata->m_componentIdCount << 1;
    return tmp;    
}
