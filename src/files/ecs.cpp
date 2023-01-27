#include "ecs.hpp"
#include "utils.hpp"
#include <string.h>


using namespace Ecs;

void Ecs::init_component_bytes(Memory_arena *mm, Component_data *cdata, Usize compid, Usize comp_size, Usize comp_alignment)
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


void *Ecs::get_component_pool_raw(Component_data *cdata, Usize compid)
{
    ECS_assert(cdata->pool_init[compid], "Component_pool was not initalized");

    void *comp_pool = cdata->component_pools[compid];
    ECS_assert(comp_pool != nullptr, "Component_pool is nullptr");

    return comp_pool;
}


void *Ecs::init_page_raw(Memory_arena *mm, void *raw_pool, U32 page_id, Usize compsize)
{
    // not actually U8 used for byte-wise
    Component_pool<U8> *pool = (Component_pool<U8> *)raw_pool;

    ECS_assert(page_id < MAX_PAGE_AMOUNT, "page_id outside legal scope");


    Usize pool_size_without_dense_array = sizeof(Component_page<U8>) - sizeof(U8) * PAGE_SIZE;
    Usize pool_size_with_dense_array = pool_size_without_dense_array + compsize * PAGE_SIZE;

    // not actually U8 used for byte-wise
    // TODO(Johan): test if allocation works correctly
    Component_page<U8> *page = (Component_page<U8> *)Arena::top_alloc_bytes(mm, pool_size_with_dense_array, 8); // 8 to gurantee alignment
    page->entity_count = 0;
    for(Usize i = 0; i < PAGE_SIZE; ++i)
    {
        page->sparse_array[i] = ENTITY_NULL;
        page->entity_list[i]  = ENTITY_NULL;
    }
    ECS_assert(pool->page_count < MAX_PAGE_AMOUNT, "Maximum page amount reached");
    pool->component_pages[page_id] = page;
    pool->page_count += 1;
    return (void *)page;
}


void *Ecs::get_page_raw(Memory_arena *mm, void *raw_pool, U32 id, Usize compsize)
{
    // not actually U8 use for byte-wise
    Component_pool<U8> *pool = (Component_pool<U8> *)raw_pool; 

    ECS_assert(id < MAX_PAGE_AMOUNT , "id must be lower than MAX_PAGE_AMOUNT");
    if (pool->component_pages[id] == nullptr)
    {
        // not actually U8 use for byte-wise
        pool->component_pages[id] = (Component_page<U8> *)init_page_raw(mm, pool, id, compsize);
    }
    return pool->component_pages[id];
}


void Ecs::set_component_raw(Memory_arena *mm, Component_data *cdata, Entity e, void *raw_comp, Usize compid, Usize compsize)
{
    ECS_assert(e != ENTITY_NULL, "entity cannot be ENTITY_NULL");
    ECS_assert(e < (MAX_ENTITY_AMOUNT - 1), "entity id out of bounds");
    U32 page_id = e / PAGE_SIZE;
    U32 page_entry = e % PAGE_SIZE;
    // not actually U8 use for byte-wise
    Component_pool<U8> *pool = (Component_pool<U8> *)get_component_pool_raw(cdata, compid);
    // not actually U8 use for byte-wise
    Component_page<U8> *page = (Component_page<U8> *)get_page_raw(mm, pool, page_id, compsize);
    page->sparse_array[page_entry] = page->entity_count;
    page->entity_list[page->entity_count] = e;
    memcpy(&page->dense_array[page->entity_count * compsize], raw_comp, compsize); // TODO(Johan) test if actually works
    ++page->entity_count;
    ++pool->entity_count;
}

void *Ecs::get_component_raw(Memory_arena *mm, Component_data *cdata, Entity e, Usize compid, Usize compsize)
{
    ECS_assert(e < ENTITY_NULL, "Entity outside scope");
    // not actually U8 use for byte-wise
    Component_pool<U8> *pool = (Component_pool<U8> *)get_component_pool_raw(cdata, compid);
    U32 page_id = e / PAGE_SIZE;
    U32 page_entry = e % PAGE_SIZE;
    // not actually U8 use for byte-wise
    Component_page<U8> *page = (Component_page<U8> *)get_page_raw(mm, pool, page_id, compsize);
    if (page->sparse_array[page_entry] == ENTITY_NULL)
    {
        return nullptr;
    }
    return &page->dense_array[page->sparse_array[page_entry] * compsize]; // TODO(Johan): test if actually works
}


void Ecs::destroy_entity(Component_data *cdata, Entity e)
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


void Ecs::fill_similar_entities(Component_data *cdata, Entity *entity_list, Usize *count, Usize *comp_ids, Usize min_id, Usize typeCount)
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

void Ecs::run_events(Registry *registry, Iter *it)
{
    void *after_latest_event = registry->event_mm->data;

    while (registry->evdata.events_in_buffer_count != 0)
    {
        Usize *event_id = (Usize *)after_latest_event;
        void *event = event_id + 1;
        ECS_assert(registry->evdata.event_init[*event_id], "event not initalized");
        void *after_latest_event_unaligned = (U8 *)event + registry->evdata.type_data[*event_id].size;

        after_latest_event = Utils::align_pointer(after_latest_event_unaligned, alignof(Usize));

        for (int i = 0; i < registry->evdata.listener_data[*event_id].event_sub_count; ++i)
        {
            it->event = event;
            registry->evdata.listener_data[*event_id].event_listeners[i](it);
        }
        --registry->evdata.events_in_buffer_count;
    }
    Arena::clear_arena(registry->event_mm);
}



void Ecs::init(Registry *registry, Memory_arena *mm, Memory_arena *view_mm, Memory_arena *event_mm)
{
    ECS_assert(registry != nullptr, "Registry cannot be nullptr");
    memset(registry, 0, sizeof(*registry));



    registry->mm = mm;
    registry->view_mm = view_mm;
    registry->event_mm = event_mm;

    Arena::clear_arena(event_mm);
}


void Ecs::init_system(Registry *registry, Phase phase, SystemFunc *system_func)
{
    switch (phase)
    {
        case Phase::None:
        {} break;

        
        case Phase::PreUpdate:
        {
            registry->pre_update_funcs.funcs[registry->pre_update_funcs.count] = system_func;
            ++registry->pre_update_funcs.count;
        } break;


        case Phase::OnUpdate:
        {
            registry->on_update_funcs.funcs[registry->on_update_funcs.count] = system_func;
            ++registry->on_update_funcs.count;
        } break;


        case Phase::PostUpdate:
        {
            registry->post_update_funcs.funcs[registry->post_update_funcs.count] = system_func;
            ++registry->post_update_funcs.count;
        } break;


        default:
        {
            ECS_assert(false, "Unreachable");
        } break;
        
    }
}

static void run_system(SystemFunc *sys_func, Memory_arena *view_mm, Iter *iter)
{
    Arena::clear_arena(view_mm);
    sys_func(iter);
}

void Ecs::progress_systems(Registry *registry, float Ts)
{
    Iter it = {
        .registry   = registry,
        .group      = nullptr,
        .view_arena = registry->view_mm,
        .event      = nullptr,
        .Ts         = Ts
    };
    run_events(registry, &it);

    for (Usize i = 0; i < registry->pre_update_funcs.count; ++i)
    {
        run_system(registry->pre_update_funcs.funcs[i], registry->view_mm, &it);
    }


    for (Usize i = 0; i < registry->on_update_funcs.count; ++i)
    {
        run_system(registry->on_update_funcs.funcs[i], registry->view_mm, &it);
    }


    for (Usize i = 0; i < registry->post_update_funcs.count; ++i)
    {
        run_system(registry->post_update_funcs.funcs[i], registry->view_mm, &it);

    }
}


Entity Ecs::create_entity(Registry *registry)
{
    return registry->entity_count++;
}


void Ecs::destroy_entity(Registry *registry, Entity e)
{
    ECS_assert(e < MAX_ENTITY_AMOUNT - 1, "entity id out of bounds");

    U32 page_id      = e / PAGE_SIZE;
    U32 page_entry_e = e % PAGE_SIZE;
    ECS_dbg3(printf("DEBUG: DESTROYING ENTITY [%llu]\n", e));
    for(size_t i = 0; i < registry->cdata.componentTypesCount; ++i)
    {
        ECS_assert(registry->cdata.pool_init[i], "disordered/uninitalized component pool");

        size_t &compsize     = registry->cdata.component_sizes[i];

        // component is not actually U8, used to access individual bytes.
        Component_pool<U8> *pool = (Component_pool<U8> *)registry->cdata.component_pools[i];
        


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


    

