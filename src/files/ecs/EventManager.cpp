#include "EventManager.hpp"

#include "../assert.hpp"
#include "../utils.hpp"

#include <string.h>


using namespace Ecs;


void Event_functions::init(event_data *ed)
{
    memset(ed, 0, sizeof(*ed));
}


void Event_functions::run_events(event_data *ed, Memory_arena *event_mm, Iter *it)
{
    void *after_latest_event = event_mm->data;

    while (ed->events_in_buffer_count != 0)
    {
        Usize *event_id = (Usize *)after_latest_event;
        void *event = event_id + 1;
        ECS_assert(ed->event_init[*event_id], "event not initalized");
        void *after_latest_event_unaligned = (U8 *)event + ed->type_data[*event_id].size;

        after_latest_event = Utils::align_pointer(after_latest_event_unaligned, alignof(Usize));

        for (int i = 0; i < ed->listener_data[*event_id].event_sub_count; ++i)
        {
            it->event = event;
            ed->listener_data[*event_id].event_listeners[i](it);
        }
        --ed->events_in_buffer_count;
    }
    Arena::clear_top_arena(event_mm);
}