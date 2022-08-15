#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
#include "ComponentManager.hpp"

#include "string.h"


using namespace Ecs;



void Component_functions::init(Component_data *cdata)
{
    memset(cdata, 0, sizeof(*cdata));
}


void Component_functions::init_component_bytes(top_memory_arena *mm, Component_data *cdata, Usize compid, Usize comp_size, Usize comp_alignment)
{
        // not actually a pool of U8.
        Component_pool<U8> *comp_pool = (Component_pool<U8> *)cdata->component_pools[compid];

        comp_pool = Arena::top_alloc<Component_pool<U8>>(mm);
        comp_pool->page_count = 0;
        comp_pool->entity_count = 0;

        for(Usize i = 0; i < MAX_PAGE_AMOUNT; ++i)
        {
            comp_pool->component_pages[i] = nullptr;
        }

        cdata->pool_init[compid]            = true;
        cdata->component_alignments[compid] = comp_alignment;
        cdata->component_sizes[compid]      = comp_size;
        cdata->component_pools[compid]      = comp_pool;
}


#define ECS_DEBUG3 0

void Component_functions::destroy_entity(Component_data *cdata, Entity e)
{
    ECS_assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

    U32 page_id      = e / PAGE_SIZE;
    U32 page_entry_e = e % PAGE_SIZE;
    ECS_dbg3(printf("DEBUG: DESTROYING ENTITY [%llu]\n", e));
    for(size_t i = 0; i < cdata->componentTypesCount; ++i)
    {
        ECS_assert(cdata->pool_init[i], "disordered/uninitalized component pool");

        size_t &compsize     = cdata->component_sizes[i];

        // component is not actually U8, used to access individual bytes.
        Component_pool<U8> *pool = (Component_pool<U8> *)cdata->component_pools[i];
        


        if (pool->entity_count == 0) {
            ECS_dbg3(printf("DEBUG: Ignoring destroy entity [%llu] on empty pool; component id: %llu\n", e, i));
            continue;
        }


        // component is not actually U8, used to access individual bytes.
        Component_page<U8> *page = pool->component_pages[page_id];
        if (page == nullptr)
        { 
            ECS_dbg3(printf("DEBUG: ignoring destroy entity [%llu] on empty page; component id: %ld, page id: %llu\n", e, i, page_id));
            continue;
        }

        if (page->sparse_array[page_entry_e] == ENTITY_NULL)
        {
            ECS_dbg3(printf("DEBUG: ignoring destroy entity [%llu], does not exist in page; component id: %llu, page id: %ld\n", e, i, page_id));
            continue;
        }

        Entity laste = page->entity_list[page->entity_count - 1];
        U32 page_entry_laste = laste % PAGE_SIZE;

        memcpy( &(page->dense_array[page->sparse_array[page_entry_e] * compsize]),
                &(page->dense_array[page->sparse_array[page_entry_laste] * compsize]), 
                compsize);


        page->entity_list[page->sparse_array[page_entry_e]] = laste;
        page->entity_list[page->entity_count - 1] = ENTITY_NULL;

        page->sparse_array[page_entry_laste] = page->sparse_array[page_entry_e];
        
        page->sparse_array[page_entry_e] = ENTITY_NULL;
        --page->entity_count;
    }

}


void Component_functions::fill_similar_entities(Component_data *cdata, Entity *entity_list, Usize *count, Usize *comp_ids, Usize min_id, Usize typeCount)
{
    // not actually pool of U8, used for manipulating indiviudal bytes.

    Component_pool<U8> *min_comp_pool = (Component_pool<U8> *)cdata->component_pools[min_id];

    for(Usize i = 0; i < MAX_PAGE_AMOUNT; ++i) // for every page in min component pool
    {
        // not actually page of U8, used for manipulating indiviudal bytes.
        Component_page<U8> *page = min_comp_pool->component_pages[i];
        if (page == nullptr)
        {
            continue;
        }

        for(Usize j = 0; j < page->entity_count; ++j) // for every entity in min pool's page
        {
            Entity min_e  = page->entity_list[j];
            U32 page_entry_min_e = min_e % PAGE_SIZE;

            for(Usize k = 0; k < typeCount; ++k) // for every type except T1
            {
                // not actually pool of U8, used for manipulating indiviudal bytes.
                Component_pool<U8> *curr_comp_pool = (Component_pool<U8> *)cdata->component_pools[comp_ids[k]];

                // not actually page of U8, used for manipulating indiviudal bytes.
                Component_page<U8> *curr_page = curr_comp_pool->component_pages[i];
                if (curr_page == nullptr)
                {
                    goto continue_page_loop;
                }

                if (curr_page->sparse_array[page_entry_min_e] == ENTITY_NULL)
                {
                    goto continue_entity_loop;
                }

            }

            ECS_assert(min_e != ENTITY_NULL, "Entity to be added to view cannot be ENTITY_NULL");
            entity_list[(*count)++] = min_e;

            continue_entity_loop:;
        }                    

                
        continue_page_loop:;
    }
}
