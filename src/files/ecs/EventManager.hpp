#pragma once
#include "MemoryManager.hpp"

#include <stdint.h>


namespace Ecs
{
    struct event_data
    {
        bool event_init[MAX_EVENT_TYPES];
        void *event_listeners[MAX_EVENT_TYPES];
        size_t event_types_count;
    };


    namespace Event_functions
    {
        void init(event_data *ed);
        void clean(Memory_pool *mm, event_data *ed);
        
    } // namespace Event_functions
    

    namespace Event_functions
    {
        template<typename T>
        size_t get_event_id(event_data *ed)
        {
            static const size_t id = ed->event_types_count++;
            return id;
        }


        template<typename T>
        void init_event(event_data *ed, void (event_listener)(T*))
        {
            const size_t id = get_event_id<T>(ed);
            ECS_assert(id < MAX_EVENT_TYPES, "id must be lower than MAX_EVENT_TYPES");
            ed->event_listeners[id] = (void*)event_listener;
            ed->event_init[id] = true;
        }

        template<typename T>
        void broadcast_event(event_data *ed, T *event)
        {
            const size_t id = get_event_id<T>(ed);
            ECS_assert(ed->event_init[id], "event must be initalized");

            auto *listener = (void (event_listener)(T*))(ed->event_listeners[id]);

            listener(event);
        }
    } // namespace Event_functions

} // namespace Ecs

