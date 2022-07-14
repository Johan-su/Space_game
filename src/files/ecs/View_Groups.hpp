#pragma once
#include "Entity.hpp"
#include "ecs_constants.hpp"


template<typename T>
struct View
{
    Usize size;
    Entity *entity_list;
    T *comparray;
};


struct Group
{
    Usize size;
    Usize *comp_sizes;
    Usize *comp_alignments;
    Entity *entity_list;
    void **comp_arrays;
};
    


namespace Ecs
{
    /**
     * id is the order the components are declared in the group starting from 0
     * @return pointer to compnonent array
     */
    template<typename T>
    T *get_comp_array(Group *group, U64 order_id)
    {
        ECS_assert(group->comp_sizes[order_id] == sizeof(T) && group->comp_alignments[order_id] == alignof(T), "Component size/alignment mismatch, id order is probably incorrect");
        return (T *)(group->comp_arrays[order_id]);
    }

} // namespace Ecs



