#pragma once
#include "Entity.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"

struct BaseCollection 
{
    Entity m_entities[MAX_ENTITY_AMOUNT];
};

template <typename T>
struct View : public BaseCollection
{
    //only the template specializations should be used.
};

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