#pragma once
#include "ecs_assert.hpp"
#include "ecs_constants.hpp"
#include "iter.hpp"

#include "../Memory_arena.hpp"
#include <stdint.h>

namespace Ecs
{
    typedef void (listener_func)(Iter *);

    struct event_listener_data
    {
        Usize event_sub_count;
        listener_func *event_listeners[MAX_EVENT_SUBS];
    };


    struct event_type_data
    {
        Usize size;
        Usize alignment;
    };


    struct event_data
    {
        Usize event_types_count;
        Usize events_in_buffer_count;
        bool event_init[MAX_EVENT_TYPES];
        event_listener_data listener_data[MAX_EVENT_TYPES];
        event_type_data type_data[MAX_EVENT_TYPES];
    };


    namespace Event_functions
    {
        void init(event_data *ed); 
        void run_events(event_data *ed, top_memory_arena *event_mm, Iter *it);
    } // namespace Event_functions
    

    namespace Event_functions
    {
        template<typename T>
        Usize get_event_id(event_data *ed)
        {
            static const Usize id = ed->event_types_count++;
            return id;
        }

        template<typename T>
        void init_event(event_data *ed)
        {
            const Usize id = get_event_id<T>(ed);
            ECS_assert(id < MAX_EVENT_TYPES, "id must be lower than MAX_EVENT_TYPES");

            ed->event_init[id] = true;
            ed->type_data[id].size = sizeof(T);
            ed->type_data[id].alignment = alignof(T);
        }


        template<typename T>
        void init_event_listener(event_data *ed, void (*listener)(Iter *))
        {
            const Usize id = get_event_id<T>(ed);
            ECS_assert(ed->listener_data[id].event_sub_count < MAX_EVENT_SUBS, "cannot have more than MAX_EVENT_SUBS subs to a single event");

            ed->listener_data[id].event_listeners[ed->listener_data[id].event_sub_count] = listener;
            ++ed->listener_data[id].event_sub_count;
        }


        template<typename T>
        void push_event(event_data *ed, top_memory_arena *event_mm, T *event)
        {
            const Usize id = get_event_id<T>(ed);
            ECS_assert(ed->event_init[id], "event must be initalized");

            Usize *id_b = (Usize *)Arena::top_alloc_bytes(event_mm, sizeof(Usize) + sizeof(T), alignof(Usize)); // id + event aligned as id
            *id_b = id;

            T *event_b = (T *)(id_b + 1);
            *event_b = *event;

            ++ed->events_in_buffer_count;
        }
        


    } // namespace Event_functions

} // namespace Ecs