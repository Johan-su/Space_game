#include "EventManager.hpp"
#include "MemoryManager.hpp"

void Event_functions::init(event_data *ed, void (event_listener)(size_t, const void*))
{
    memset(ed->event_sizes, 0, sizeof(ed->event_sizes[0]) * MAX_EVENT_TYPES);


    ed->event_types_count = 0;
    ed->event_listener = event_listener;

}


void Event_functions::clean(Memory_pool *mm, event_data *ed)
{
}


void Event_functions::init_event(event_data *ed, size_t event_id, size_t event_size, size_t event_alignment)
{
    ECS_assert(event_id <= ed->event_types_count, "non increasing event_id");
    ECS_assert(ed->event_types_count != MAX_EVENT_TYPES, "MAX_EVENT_TYPES EXCEEDED");

    ed->event_sizes[event_id] = event_size;
    ++ed->event_types_count;


}


void Event_functions::broadcast_event(event_data *ed, size_t event_id, size_t event_size, size_t event_alignment, const void *event)
{
    ECS_assert(ed->event_sizes[event_id] == event_size, "mismatch between declared event_size and parameter event_size");

    (*ed->event_listener)(event_id, event);
}
