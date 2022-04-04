#pragma once
#include <stdint.h>
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"



namespace Ecs
{
    struct event_data
    {
        size_t event_sizes[MAX_EVENT_TYPES];
        size_t event_types_count;

        void (*event_listener)(size_t, const void*);
    };


    namespace Event_functions
    {
        void init(event_data *ed, void (event_listener)(size_t, const void*));
        void clean(Memory_pool *mm, event_data *ed);

        void init_event(event_data *ed, size_t event_id, size_t event_size, size_t event_alignment);
        void broadcast_event(event_data *ed, size_t event_id, size_t event_size, size_t event_alignment, const void *event);

    }
}

