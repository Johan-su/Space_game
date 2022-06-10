#pragma once

#include <stdint.h>



#define MAX_EVENT_TYPES 256

namespace Ecs
{
    struct Registry;
    struct event_data
    {
        bool event_init[MAX_EVENT_TYPES];
        void *event_listeners[MAX_EVENT_TYPES];
        size_t event_types_count;
    };


    namespace Event_functions
    {
        void init(event_data *ed);
        
    } // namespace Event_functions
    

    namespace Event_functions
    {
        template<typename T>
        size_t get_event_id(event_data *ed)
        {
            static const size_t id = ed->event_types_count++;
            return id;
        }


        template<typename ReturnT, typename EventT>
        void init_event(event_data *ed, ReturnT (event_listener)(Registry *, EventT*))
        {
            const size_t id = get_event_id<EventT>(ed);
            ECS_assert(id < MAX_EVENT_TYPES, "id must be lower than MAX_EVENT_TYPES");
            ed->event_listeners[id] = (void*)event_listener;
            ed->event_init[id] = true;
        }

        template<typename ReturnT, typename EventT>
        ReturnT broadcast_event(Registry *registry, event_data *ed, EventT *event)
        {
            const size_t id = get_event_id<EventT>(ed);
            ECS_assert(ed->event_init[id], "event must be initalized");

            auto *listener = (ReturnT (*)(Registry *, EventT*))(ed->event_listeners[id]); // normal C++ things

            return listener(registry, event);
        }
    } // namespace Event_functions

} // namespace Ecs

