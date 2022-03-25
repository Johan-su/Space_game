#pragma once
#include <stdint.h>
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"





struct event_data
{
    void *events[MAX_EVENT_TYPES];

    size_t event_sizes[MAX_EVENT_TYPES];
    size_t event_types_count;

    void (*event_listener)(size_t);

};


namespace Event_functions
{
    void init(event_data *ed, void (event_listener)(size_t));
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
    void init_event(Memory_pool *mm, event_data *ed)
    {
        const size_t eventid = get_unique_event_id<T>(ed);

        T *event = (T*)ed->events[eventid];
        event = Memory::alloc<T>(mm);

        ed->event_sizes[eventid] = sizeof(T);


        dbg(std::cout << "sizeof " << typeid(T).name() << "_event : " << sizeof(T) << "\n");
    }


    template<typename T>
    void broadcast_event(event_data *ed, T event)
    {
        const size_t eventid = get_unique_event_id<T>();
        T *event = (T*)ed->events[eventid];

        (*ed->event_listener)(eventid);
    }


}