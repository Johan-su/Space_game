#pragma once
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"
#include "Entity.hpp"
#include "Signature.hpp"
#include "ecs_assert.hpp"
#include "View_Groups.hpp"
//#include <string>


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
    bool init(Memory_pool *mm, Component_data *cdata);
    bool clean(Memory_pool *mm, Component_data *cdata);

    uint64_t getId(Component_data *cdata); // should not be called directly

    template <typename T>
    Signature get_component_signature(Component_data *cdata)
    {
        static Signature component_signature = {getId(cdata)};
        return component_signature;
    }




    template <typename T>
    void set_component(Component_data *cdata, Entity e, T& comp)
    {
        assert(false, "non specialized template");
    }


    #define STRUCT_GEN(NAME, vargs...)                         \
    template<>                                                 \
    void set_component<NAME ## _component>                     \
    (Component_data *cdata, Entity e, NAME ## _component& comp) \
    {                                                          \
        NAME ## _array *comparray = cdata->m_ ## NAME;         \
        Entity *e_ind = comparray->entity_indicies;            \
        Entity *e_list = comparray->entity_list;               \
        e_ind[e] = comparray->array_size++;                    \
        e_list[e_ind[e]] = e;                                  \
        vargs                                                  \
    }                                                          \

    #define DATA_GEN(TYPE, VAR) \
    comparray->VAR[e_ind[e]] = comp.VAR;

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
    #undef STRUCT_GEN
    #undef DATA_GEN



    template<typename T>
    void destroy_component(Component_data *cdata, Entity e)
    {
        assert(false, "non specialized template");
    }

    #define STRUCT_GEN(NAME, vargs...)                 \
    template<>                                         \
    void destroy_component<NAME ## _component>         \
    (Component_data *cdata, Entity e)                  \
    {                                                  \
        NAME ## _array *comparray = cdata->m_ ## NAME; \
        Entity *e_ind = comparray->entity_indicies;    \
        Entity *e_list = comparray->entity_list;       \
        size_t& ar_size = comparray->array_size;       \
        vargs                                          \
        e_list[e_ind[e]] = e_list[ar_size];            \
        e_ind[e_list[ar_size]] = e_ind[e];             \
        e_ind[e] = MAX_ENTITY_AMOUNT - 1;              \
        --ar_size;                                     \
    }
    #define DATA_GEN(TYPE, VAR) \
    comparray->VAR[e_ind[e]] = comparray->VAR[ar_size];

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
    #undef STRUCT_GEN
    #undef DATA_GEN



    //TODO:(johan) finish https://gist.github.com/dakom/82551fff5d2b843cbe1601bbaff2acbf
    template <typename T>
    View<T> & get_view(Component_data *cdata) //--
    {
        assert(false, "no template specialization");
        return *(View<T>*)0;
    }


    #define STRUCT_GEN(NAME, vargs...)                                             \
    template<>                                                                     \
    View<NAME ## _component> & get_view<NAME ## _component>(Component_data *cdata) \
    {                                                                              \
        return *(View<NAME ## _component>*)0;                                      \
    }

    #define DATA_GEN(TYPE, VAR)

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
    #undef STRUCT_GEN
    #undef DATA_GEN



    void destroy_entity(Component_data *cdata, Entity e, Signature sig);
}
