#pragma once
#include <stdint.h>
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"



template<typename T>
struct event_array
{
    T eventlist[EVENT_QUEUE_SIZE];
    bool activelist[EVENT_QUEUE_SIZE];
    size_t queue_start_index;
    size_t size;

};


struct event_data
{
    void *event_arrays[MAX_EVENT_TYPES];

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
    void init_event(event_data *ed)
    {
        const size_t eventid = get_unique_event_id<T>(ed);

        event_array<T> *eventarray = (event_array<T>*)ed->event_arrays[eventid];
        eventarray = Memory::alloc<event_array<T>>(mm);

        eventarray->size = 0;
        eventarray->queue_start_index = 0;

        for(size_t i = 0; i < EVENT_QUEUE_SIZE; ++i)
        {
            eventarray->activelist[i] = false; 
        }

        ed->event_sizes[eventid]      = sizeof(T);
        ed->event_alignments[eventid] = alignof(T);
        ed->array_init[eventid]       = true;


        dbg(std::cout << "sizeof " << typeid(T).name() << "_array : " << sizeof(event_array<T>) << "\n");
    }

}