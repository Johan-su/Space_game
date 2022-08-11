#pragma once
#include "Entity.hpp"
#include "ecs_constants.hpp"



/**
 * non-owning view, only provides copies of components
 */
template<typename T>
struct View
{
    Usize size;
    Entity *entity_list;
    T *comparray;
};


/**
 * non-owning group, only provies copies of components
 */
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
     * @param group the group, which the array will be retrived from.
     * @param order_id the component's order in the group. starts at 0
     * @return pointer to component array
     */
    template<typename T>
    const T *get_comp_array(const Group *group, U64 order_id)
    {
        ECS_assert(group->comp_sizes[order_id] == sizeof(T) && group->comp_alignments[order_id] == alignof(T), "Component size/alignment mismatch, id order is probably incorrect");
        return (const T *)(group->comp_arrays[order_id]);
    }

} // namespace Ecs



