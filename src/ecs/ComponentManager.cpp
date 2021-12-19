#include "Components.h"
#include "ComponentManager.h"


bool ComponentManager::init(MemoryManager* mem)
{
    m_positionArray = mem->alloc<PositionArray>();
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


