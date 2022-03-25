#include "EventManager.hpp"
#include "MemoryManager.hpp"

void Event_functions::init(event_data *ed, void (event_listener)(size_t))
{
    memset(ed->events,      0, sizeof(ed->events[0])      * MAX_EVENT_TYPES);
    memset(ed->event_sizes, 0, sizeof(ed->event_sizes[0]) * MAX_EVENT_TYPES);


    ed->event_types_count = 0;
    ed->event_listener = event_listener;

}


void Event_functions::clean(Memory_pool *mm, event_data *ed)
{
    for(size_t i = 0; i < ed->event_types_count; ++i)
    {
        if(ed->event_sizes[i] > 0)
        {
            Memory::dealloc(mm, (char*)(ed->events + i), ed->event_sizes[i]);
        }
    }
}
