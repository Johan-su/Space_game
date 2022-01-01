#pragma once
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "component_arrays.hpp"
#include "Signature.hpp"
#include "ecs_assert.hpp"
#include <string>


/* component arrays in component_data
// from component_arrays.hpp and components.hpp
//
//
*/
struct Component_data
{
    uint64_t m_componentIdCount;

    #define STRUCT_GEN(NAME, vargs...) NAME ## _array *m_ ## NAME;
    #define DATA_GEN(TYPE, VAR)    

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)

    #undef STRUCT_GEN
    #undef DATA_GEN    

};



namespace Component_functions 
{
    bool init(Memory_pool *mm, Component_data *compdata);
    bool clean(Memory_pool *mm, Component_data *compdata);
    uint64_t getId(Component_data *cdata);

    template<typename T>
    bool array_init(T *array, Memory_pool *mem)
    {
        array = mem->alloc<T>();
        return 0;
    }

    template <typename T>
    void set_component(Component_data *cdata, Entity e, T& comp);

    template<typename T>
    void destroy_component(Component_data *cdata, Entity e);

    template <typename T>
    T get_view(Component_data *cdata);

    template<typename T>
    Signature get_component_signature(Component_data *cdata)
    {
        static Signature component_signature = {getId(cdata)};
        return component_signature;
    }
}
