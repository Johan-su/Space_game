#include "ecs_constants.hpp"
#include "ecs_assert.hpp"
#include "MemoryManager.hpp"
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

    uint32_t page_id      = e / PAGE_SIZE;
    uint32_t page_entry_e = e % PAGE_SIZE;
    ECS_dbg3(printf("DEBUG: DESTROYING ENTITY [%llu]\n", e));
    for(size_t i = 0; i < cdata->componentTypesCount; ++i)
    {
        ECS_assert(cdata->pool_init[i], "disordered/uninitalized component pool");

        size_t &compsize     = cdata->component_sizes[i];
        void *pool           = cdata->component_pools[i];


        size_t *pool_page_count     = (size_t*)(pool);
        size_t *pool_entity_count   = (size_t*)(pool_page_count + 1);
        void **pool_component_pages = (void**)(pool_entity_count + 1);


        if(pool_entity_count == 0) {
            ECS_dbg3(printf("DEBUG: Ignoring destroy entity [%llu] on empty pool; component id: %llu\n", e, i));
            continue;
        }

        void *page = pool_component_pages[page_id];
        if(page == NULL)
        { 
            ECS_dbg3(printf("DEBUG: ignoring destroy entity [%llu] on empty page; component id: %ld, page id: %llu\n", e, i, page_id));
            continue;
        }
        size_t *page_entity_count = (size_t*)(page);
        Entity *page_sparse_array = (Entity*)(page_entity_count + 1);

        if(page_sparse_array[page_entry_e] == ENTITY_NULL)
        {
            ECS_dbg3(printf("DEBUG: ignoring destroy entity [%llu], does not exist in page; component id: %llu, page id: %ld\n", e, i, page_id));
            continue;
        }

        Entity *page_entity_list  = (Entity*)(page_sparse_array + PAGE_SIZE);
        uint8_t *page_dense_array = (uint8_t*)(page_entity_list + PAGE_SIZE); // char for byte-wise pointer arithmetic in memcpy

        Entity laste = page_entity_list[*page_entity_count - 1];
        uint32_t page_entry_laste = laste % PAGE_SIZE;

        memcpy( (void*)(&(page_dense_array[page_sparse_array[page_entry_e] * compsize])),
                (void*)(&(page_dense_array[page_sparse_array[page_entry_laste] * compsize])), 
                compsize);


        page_entity_list[page_sparse_array[page_entry_e]] = laste;
        page_entity_list[*page_entity_count - 1] = ENTITY_NULL;

        page_sparse_array[page_entry_laste] = page_sparse_array[page_entry_e];
        
        page_sparse_array[page_entry_e] = ENTITY_NULL;
        --*page_entity_count;
    }

}
