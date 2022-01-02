#pragma once
#include "Entity.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"

struct BaseCollection 
{
    Entity m_entities[MAX_ENTITY_AMOUNT];
    uint64_t size = 0;
};

template <typename T>
struct View : public BaseCollection
{
    //only the template specializations should be used.
};
#define STRUCT_GEN(NAME, vargs...) \
template<> \
struct View<NAME ## _component> : public BaseCollection {vargs}; \

#define DATA_GEN(TYPE, VAR) \
TYPE VAR[MAX_ENTITY_AMOUNT];

COMPONENT_LIST(STRUCT_GEN, DATA_GEN)

#undef STRUCT_GEN
#undef DATA_GEN


template <typename T>
struct PartialView : public BaseCollection
{
    //only the template specializations should be used.
};

template <typename T>
struct Group : public BaseCollection
{
    //only the template specializations should be used.
};