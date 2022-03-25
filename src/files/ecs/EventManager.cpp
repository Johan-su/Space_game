#include "EventManager.hpp"
#include "MemoryManager.hpp"

void Event_functions::init(event_data *ed)
{
    memset(ed->event_arrays,     0, sizeof(ed->event_arrays[0])     * MAX_EVENT_TYPES);
    memset(ed->event_sizes,      0, sizeof(ed->event_sizes[0])      * MAX_EVENT_TYPES);
    memset(ed->event_alignments, 0, sizeof(ed->event_alignments[0]) * MAX_EVENT_TYPES);
    memset(ed->array_init,       0, sizeof(ed->array_init[0])       * MAX_EVENT_TYPES);


    ed->event_types_count = 0;

}


void Event_functions::clean(Memory_pool *mm, event_data *ed)
{
    for(size_t i = 0; i < ed->event_types_count; ++i)
    {
        if(ed->array_init[i])
        {
            Memory::dealloc(mm, (char*)(ed->event_arrays + i), ed->event_sizes[i] * MAX_EVENT_TYPES);
        }
    }
}
