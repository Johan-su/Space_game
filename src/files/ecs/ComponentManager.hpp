#pragma once
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"
#include "Components.hpp"
#include "component_arrays.hpp"
#include "Entity.hpp"
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

    uint64_t getId(Component_data *cdata);

    void destroy_entity(Component_data *cdata, Entity e);

}


namespace Component_functions
{


    template<typename T>
    auto *get_component_array(Component_data *cdata)
    {
        assert(false, "non specialized template");
        return nullptr;
    }

    #define STRUCT_GEN(NAME, vargs...)                                          \
    template<>                                                                  \
    inline auto *get_component_array<NAME ## _component>(Component_data *cdata) \
    {                                                                           \
        return cdata->m_ ## NAME;                                               \
    } 

    #define DATA_GEN(TYPE, VAR)

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
    
    #undef STRUCT_GEN
    #undef DATA_GEN



    template <typename T>
    void set_component(Component_data *cdata, Entity e, T& comp)
    {
        assert(false, "non specialized template");
    }


    #define STRUCT_GEN(NAME, vargs...)                          \
    template<>                                                  \
    inline void set_component<NAME ## _component>               \
    (Component_data *cdata, Entity e, NAME ## _component& comp) \
    {                                                           \
        NAME ## _array *comparray = cdata->m_ ## NAME;          \
        Entity *e_ind = comparray->entity_indicies;             \
        Entity *e_list = comparray->entity_list;                \
        e_ind[e] = comparray->array_size++;                     \
        e_list[e_ind[e]] = e;                                   \
        vargs                                                   \
    }                                                           

    #define DATA_GEN(TYPE, VAR) \
    comparray->VAR[e_ind[e]] = comp.VAR;

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
    
    #undef STRUCT_GEN
    #undef DATA_GEN



    template<typename T>
    inline void destroy_component(Component_data *cdata, Entity e)
    {
        assert(false, "non specialized template");
    }

    #define STRUCT_GEN(NAME, vargs...)                                                  \
    template<>                                                                          \
    inline void destroy_component<NAME ## _component> (Component_data *cdata, Entity e) \
    {                                                                                   \
        auto *comparray = get_component_array<NAME ## _component>(cdata);               \
        Entity *e_ind = comparray->entity_indicies;                                     \
        Entity *e_list = comparray->entity_list;                                        \
        size_t &ar_size = comparray->array_size;                                        \
        if(e_ind[e] == ENTITY_NULL) return;                                             \
        vargs                                                                           \
        e_list[e_ind[e]] = e_list[ar_size];                                             \
        e_ind[e_list[ar_size]] = e_ind[e];                                              \
        e_ind[e] = MAX_ENTITY_AMOUNT;                                                   \
        --ar_size;                                                                      \
    }


    #define DATA_GEN(TYPE, VAR) \
    comparray->VAR[e_ind[e]] = comparray->VAR[ar_size];

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
    #undef STRUCT_GEN
    #undef DATA_GEN


    template<typename T>
    size_t get_component_array_size(Component_data *cdata)
    {
        assert(false, "non specialized template");
        return 0;
    }


    #define STRUCT_GEN(NAME, vargs...)                                                 \
    template<>                                                                         \
     inline size_t get_component_array_size<NAME ## _component>(Component_data *cdata) \
    {                                                                                  \
        return get_component_array<NAME ## _component>(cdata)->array_size;             \
    }


    #define DATA_GEN(TYPE, VAR)

    COMPONENT_LIST(STRUCT_GEN, DATA_GEN)
    #undef STRUCT_GEN
    #undef DATA_GEN



    template<typename T1, typename... Ts> // TODO(johan) check if working
    size_t *get_component_array_sizes(Memory_pool *mm, Component_data *cdata) // https://en.cppreference.com/w/cpp/language/parameter_pack
    {
        const size_t type_count = 1 + sizeof...(Ts);

        size_t *result_buf = Memory::alloc<size_t>(mm, type_count);
       

        __get_component_array_sizes<T1, Ts...>(cdata, result_buf);

        return result_buf;
    }


    template<typename T1, typename... Ts>
    void __get_component_array_sizes(Component_data *cdata, size_t *result_buf)
    {
        const size_t type_count = sizeof...(Ts);

        result_buf[type_count] = get_component_array_size<T1>(cdata);



        if constexpr (type_count)
        {
            __get_component_array_sizes<Ts...>(cdata, result_buf);
        }
    }

}
