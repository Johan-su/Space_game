#pragma once
#include <stdint.h>
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"

struct event_data
{
    void *event_arrays[MAX_EVENT_TYPES];

    size_t array_sizes[MAX_EVENT_TYPES];
    size_t event_sizes[MAX_EVENT_TYPES];
    size_t event_alignments[MAX_EVENT_TYPES];

    size_t event_types_count;

    bool array_init[MAX_EVENT_TYPES];
};


namespace Event_functions
{
    void init(event_data *ed);
    void clean(Memory_pool *mm, event_data *ed);

}

namespace Event_functions
{
    template<typename T>
    size_t get_unique_event_id(event_data *ed)
    {
        static size_t id = ed->event_types_count++;
        return id;
    }




    template<typename T>
    void init_event(event_data *ed) //TODO(johan) implemented with eventArrays
    {
        const size_t eventid = get_unique_event_id<T>(ed);

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
        cdata->m_componentTypesCount         += 1;

        dbg(std::cout << "sizeof " << typeid(T).name() << "_array : " << sizeof(ComponentArray<T>) << "\n");
    }

}