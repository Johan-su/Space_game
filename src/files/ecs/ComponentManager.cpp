#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
#include "ComponentManager.hpp"

#include "string.h"


using namespace Ecs;



void Component_functions::init(Component_data *cdata)
{
    memset(cdata, 0, sizeof(*cdata));
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
        if (page == NULL)
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
