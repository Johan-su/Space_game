#pragma once
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"
#include "Components.hpp"
#include "Entity.hpp"
#include "ecs_assert.hpp"
#include "View_Groups.hpp"
#include <type_traits>


/* component arrays in component_data
// from component_arrays.hpp and components.hpp
//
//
*/
struct Component_data
{
    void *m_componentArrays[MAX_COMPONENT_TYPES];

    size_t m_array_sizes[MAX_COMPONENT_TYPES];

    bool m_array_init[MAX_COMPONENT_TYPES];

    uint64_t m_componentTypesCount;



};



namespace Component_functions 
{
    bool init(Memory_pool *mm, Component_data *cdata);
    bool clean(Memory_pool *mm, Component_data *cdata);


    void destroy_entity(Component_data *cdata, Entity e);

    size_t get_id();

}


namespace Component_functions
{

    template<typename T>
    size_t get_unique_component_id()
    {
        static size_t id = get_id();
        return id;
    }


    template<typename T>
    void init_component(Memory_pool *mm, Component_data *cdata)
    {
       const size_t compid = get_unique_component_id<T>();

        ComponentArray<T> *comparray = (ComponentArray<T>*)cdata->m_componentArrays[compid];

        comparray = Memory::alloc<ComponentArray<T>>(mm);

        comparray->size = 0;
        for(size_t i = 0; i < MAX_ENTITY_AMOUNT; ++i)
        {
            comparray->sparse_array[i] = ENTITY_NULL;
            comparray->entity_list[i]  = ENTITY_NULL;
        }

        cdata->m_componentArrays[compid] = comparray;
        cdata->m_array_sizes[compid]     = sizeof(ComponentArray<T>);
        cdata->m_array_init[compid]      = true;

        dbg(std::cout << "sizeof " << typeid(T).name() << "_array : " << sizeof(ComponentArray<T>) << "\n");

    }


    template<typename T>
    ComponentArray<T> *get_component_array(Component_data *cdata)
    {
        size_t compid = get_unique_component_id<T>();
        assert(cdata->m_array_init[compid], "Component_array was not initalized");

        auto *comparray = (ComponentArray<T>*) cdata->m_componentArrays[compid];
        assert(comparray != nullptr, "ComponentArray is null");

        return comparray;
    }

    template<typename T>
    void set_component(Component_data *cdata, Entity e, T comp)
    {
        assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

        size_t compid = get_unique_component_id<T>();
        ComponentArray<T> *comparray = get_component_array<T>(cdata);

        comparray->sparse_array[e] = comparray->size;

        comparray->entity_list[comparray->size] = e;

        comparray->dense_array[comparray->size] = comp;

        ++comparray->size;
    }

    template<typename T>
    void destroy_component(Component_data *cdata, Entity e)
    {
        assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

        size_t compid = get_unique_component_id<T>();
        ComponentArray<T> *comparray = get_component_array<T>(cdata);
        assert(comparray->size > 0, "array size is 0");

        Entity laste = comparray->entity_list[comparray->size - 1];

        comparray->dense_array[comparray->sparse_array[e]] = comparray->dense_array[comparray->sparse_array[laste]];
        comparray->sparse_array[laste] = comparray->sparse_array[e]
        
        comparray->sparse_array[e] = ENTITY_NULL;
        --comparray->size;
    }
}
