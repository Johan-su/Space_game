#include "Signature.hpp"
#include "Components.hpp"
#include "ComponentManager.hpp"

#include <cstring>



bool ComponentManager::init(MemoryManager *mem)
{
    m_componentIdCount = 1;
    m_positionArray = mem->alloc<PositionArray>();

    memset(m_positionArray->EntityIndices, 0xFF, sizeof(uint64_t) * MAX_ENTITY_AMOUNT);
    memset(m_positionArray->EntityList, 0, sizeof(Entity) * MAX_ENTITY_AMOUNT);

    m_positionArray->EntityAmount = 0;


    m_healthArray = mem->alloc<HealthArray>();

    return 0;
}

bool ComponentManager::clean(MemoryManager* mem)
{
    mem->dealloc(m_positionArray);
    mem->dealloc(m_healthArray);

    m_positionArray = nullptr;
    m_healthArray = nullptr;   
    return 0;     
}


