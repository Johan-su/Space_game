#pragma once
#include "Entity.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"

struct Collection 
{
    // Entity m_entities[MAX_ENTITY_AMOUNT];
    void *comparray; // only one component type
    uint64_t size = 0;
};



#define get_collection(first, vargs...) _get_collection(first, vargs)


inline constexpr bool equal(const char *lhs, const char *rhs)
{
    while (*lhs || *rhs)
    {
        if (*lhs++ != *rhs++)
        {
            return false;
        }

    }
    return true;
}

inline constexpr void component_to_enum(const char *component, size_t *val)
{
    #define STR(s1) #s1  


    #define STRUCT_GEN(NAME, vargs...)            \
    if(equal(component, STR(NAME ## _component))) \
    {                                             \
        *val = NAME ##_CONSTANT;                  \
    }

    #define DATA_GEN(TYPE, VAR)

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)


    #undef STRUCT_GEN
    #undef DATA_GEN
    #undef STR
    
}


inline Collection _get_collection(const char *components)
{
    printf("%s", components);

    return *(Collection*)(0);
}
