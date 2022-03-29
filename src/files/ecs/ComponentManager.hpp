#pragma once
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"
#include "Entity.hpp"
#include "ecs_assert.hpp"
#include "View_Groups.hpp"



template<typename T>
struct ComponentArray // changing variables or order will affect componentManager functions
{
    size_t size;
    Entity sparse_array[MAX_ENTITY_AMOUNT];
    Entity entity_list[MAX_ENTITY_AMOUNT];
    T dense_array[MAX_ENTITY_AMOUNT];
};


struct Component_data
{
    void *m_componentArrays[MAX_COMPONENT_TYPES];

    size_t m_component_sizes[MAX_COMPONENT_TYPES];
    size_t m_component_alignments[MAX_COMPONENT_TYPES];

    size_t m_componentTypesCount;

    bool m_array_init[MAX_COMPONENT_TYPES];




};



namespace Component_functions 
{
    bool init(Component_data *cdata);
    bool clean(Memory_pool *mm, Component_data *cdata);


    void destroy_entity(Component_data *cdata, Entity e);

    size_t get_id();

}


namespace Component_functions
{

    template<typename T>
    size_t get_unique_component_id(Component_data *cdata)
    {
        static size_t id = cdata->m_componentTypesCount++;
        return id;
    }


    template<typename T>
    void init_component(Memory_pool *mm, Component_data *cdata)
    {
        const size_t compid = get_unique_component_id<T>(cdata);

        ComponentArray<T> *comparray = (ComponentArray<T>*)cdata->m_componentArrays[compid];

        comparray = Memory::alloc<ComponentArray<T>>(mm);

        comparray->size = 0;
        for(size_t i = 0; i < MAX_ENTITY_AMOUNT; ++i)
        {
            comparray->sparse_array[i] = ENTITY_NULL;
            comparray->entity_list[i]  = ENTITY_NULL;
        }

        cdata->m_array_init[compid]           = true;
        cdata->m_component_alignments[compid] = alignof(T);
        cdata->m_component_sizes[compid]      = sizeof(T);
        cdata->m_componentArrays[compid]      = comparray;

        ECS_dbg(std::cout << "sizeof " << typeid(T).name() << "_array : " << sizeof(ComponentArray<T>) << "\n");

    }


    template<typename T>
    ComponentArray<T> *get_component_array(Component_data *cdata)
    {
        size_t compid = get_unique_component_id<T>(cdata);
        ECS_assert(cdata->m_array_init[compid], "Component_array was not initalized");

        auto *comparray = (ComponentArray<T>*) cdata->m_componentArrays[compid];
        ECS_assert(comparray != nullptr, "ComponentArray is null");

        return comparray;
    }

    template<typename T>
    void set_component(Component_data *cdata, Entity e, T comp)
    {
        ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
        ECS_assert(e < (MAX_ENTITY_AMOUNT - 1), "entity id out of bounds");

        ComponentArray<T> *comparray = get_component_array<T>(cdata);

        comparray->sparse_array[e] = comparray->size;

        comparray->entity_list[comparray->size] = e;

        comparray->dense_array[comparray->size] = comp;

        ++comparray->size;
    }

    template<typename T>
    void destroy_component(Component_data *cdata, Entity e) // TODO(Johan) add lookup to check if entity exists in componentarray
    {
        ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
        ECS_assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

        //size_t compid = get_unique_component_id<T>();
        ComponentArray<T> *comparray = get_component_array<T>(cdata);
        ECS_assert(comparray->size > 0, "array size is 0");

        Entity laste = comparray->entity_list[comparray->size - 1];

        comparray->dense_array[comparray->sparse_array[e]] = comparray->dense_array[comparray->sparse_array[laste]];
        comparray->sparse_array[laste] = comparray->sparse_array[e];
        
        comparray->sparse_array[e] = ENTITY_NULL;
        --comparray->size;
    }


    // garbage function
    template<typename T1, typename... Ts>
    void _set_min_comp_array_size(Component_data *cdata, size_t &mincompid, size_t *compids, size_t &minsize, const size_t component_amount)
    {
        const size_t typeCount = 1 + sizeof...(Ts);
        const size_t compid = Component_functions::get_unique_component_id<T1>(cdata);
        ECS_assert(cdata->m_array_init[compid], "componentArray not initalized");

        const auto *comparray = static_cast<ComponentArray<T1>*>(cdata->m_componentArrays[compid]);
        const size_t size = comparray->size;

        if(size < minsize)
        {
            minsize = size;
            mincompid = compid;
        }


        compids[component_amount - typeCount] = compid;

        if constexpr (typeCount - 1) // just works with constexpr
        {
            _set_min_comp_array_size<Ts...>(cdata, mincompid, compids, minsize, component_amount);
        }
    }
    


    template<typename T1, typename... Ts>
    View<T1> get_view(Component_data *cdata)
    {
        const size_t typeCount = 1 + sizeof...(Ts);

        size_t mincompid;
        size_t compids[typeCount];
        size_t minsize = SIZE_MAX;

        _set_min_comp_array_size<T1, Ts...>(cdata, mincompid, compids, minsize, typeCount);

        std::cout << "compids: ";
        for(int i = 0; i < typeCount; ++i)
        {
            std::cout << compids[i] << ", ";
        }
        std::cout << "\n";

        std::cout << "mincompid " << mincompid << "\n";
        std::cout << "minsize " << minsize << "\n";

        auto view = View<T1>();

        for(size_t i = 0; i < VIEW_SIZE; ++i)
        {
            view.entity_list[i] = ENTITY_NULL;
        }

        auto *comparray = get_component_array<T1>(cdata);

        void *mincomparray = cdata->m_componentArrays[mincompid]; // dangerous

        size_t *size_pointer = (size_t*)(mincomparray);
        Entity *sparse_array = (Entity*)(size_pointer + 1);
        Entity *entity_list  = sparse_array + MAX_ENTITY_AMOUNT;

        size_t size = *size_pointer;
        

        for(size_t i = 0; i < size; ++i)
        {
            Entity e = entity_list[i];

            for(size_t j = 0; j < typeCount; ++j) // checks mincomparray again which is unnecessary.
            {   
                void *curr_comp_array     = cdata->m_componentArrays[compids[j]];
                size_t *curr_size_pointer = (size_t*)(curr_comp_array);
                Entity *curr_sparse_array = (Entity*)(curr_size_pointer + 1);

                if(curr_sparse_array[e] == ENTITY_NULL)
                {
                    goto continue_outer_loop; // first use of goto
                }

            }

            
            view.entity_list[view.size++] = e;   // will break when more than VIEW_SIZE (4096) entites are included
                  
            continue_outer_loop : ;
        }

        for(size_t i = 0; i < view.size; ++i)
        {
            Entity e = view.entity_list[i];
            std::cout << "entity, " << e << "\n";

            view.comparray[i] = comparray->dense_array[comparray->sparse_array[e]];
        }

        std::cout << "size: " << view.size << "\n";


        return view;
    }




}
