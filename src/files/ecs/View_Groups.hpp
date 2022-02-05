#pragma once
#include "Entity.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"

struct Collection 
{
    // Entity m_entities[MAX_ENTITY_AMOUNT];
    void *comparray;
    uint64_t size = 0;
};



#define get_collection(vargs...) _get_collection(#vargs)

inline Collection _get_collection(const char *components)
{
    printf("%s", components);
}
