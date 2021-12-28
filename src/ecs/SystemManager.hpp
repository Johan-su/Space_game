#pragma once
#include "MemoryManager.hpp"
#include "Entity.hpp"
#include "Signature.hpp"

struct System_data
{
    uint64_t temp;
};

namespace System_functions
{

bool init(Memory_pool *mm, System_data *sysdata);
bool clean(Memory_pool *mm, System_data *sysdata);

void set_entity_signature(Entity e, Signature sig);

}
