#pragma once

#include <stdint.h>


#define MAX_EVENT_LISTENERS 32
#define MAX_EVENTS 128


template<typename T>
struct event_func_array
{
    void *funcs[MAX_EVENT_LISTENERS];
};



struct event_listeners
{
    size_t event_count;
    void *event_func_arrays;
};



 //TODO(Johan) finish event queue/system



namespace Real
{
    
} // namespace Real




namespace Real
{

    template<typename T>
    void get_event_id(event_listeners *el)
    {
    }


    template<typename T>
    void init_event(event_listeners *el)
    {

    }

    template<typename T>
    void bind_func_to_event(event_listeners *el)
    {

    }

} // namespace Real
