#pragma once
#include "Components.hpp"
#include "ecs_constants.hpp"
#include "Entity.hpp"
#include "MemoryManager.hpp"
#include "ecs_assert.hpp"
#include <string>
#include <cstdint>

struct Component_data
{
    uint64_t m_componentIdCount;

    PositionArray *m_positionArray;
    HealthArray *m_healthArray;    
};

namespace Component_functions 
{


    bool init(Component_data *cdata, Memory_pool *mem);
    bool clean(Component_data *cdata, Memory_pool *mem);

    template<typename T>
    bool array_init(T *array, Memory_pool *mem)
    {
        array = mem->alloc<T>();
        return 0;
    }

    template <typename T>
    void set_component(Component_data *cdata, Entity e, T& comp)
    {
        assert(false, "non specialized template");
    }
//    template <>
//    void set_component<PositionComponent>(Component_data *cdata, Entity e, PositionComponent& comp)
//    {
//        Entity *elist =  cdata->m_positionArray->EntityList;
//        uint64_t *eind =  cdata->m_positionArray->EntityIndices;
//        uint64_t &eAmount = cdata->m_positionArray->EntityAmount;
//
//
//        eind[e.id] = eAmount++;
//
//        elist[eind[e.id]] = e;
//
//
//        cdata->m_positionArray->x[eind[e.id]] = comp.x;
//        cdata->m_positionArray->y[eind[e.id]] = comp.y;        
//    }

    template<typename T>
    void destroy_component(Component_data *cdata, Entity e)
    {
        assert(false, "non specialized template");       
    }
//    template<>
//    void destroy_component<PositionComponent>(Component_data *cdata, Entity e)
//    { // https://gist.github.com/dakom/82551fff5d2b843cbe1601bbaff2acbf
//    
//        Entity *elist =  cdata->m_positionArray->EntityList;
//        uint64_t *eind =  cdata->m_positionArray->EntityIndices;
//        uint64_t &eAmount = cdata->m_positionArray->EntityAmount;
//
//
//
//        Entity lastentity = elist[--eAmount];
//        uint64_t lastentity_index = eind[lastentity.id];
//        eind[lastentity.id] = eind[e.id];
//        cdata->m_positionArray->x[eind[e.id]] = cdata->m_positionArray->x[lastentity_index];
//        cdata->m_positionArray->y[eind[e.id]] = cdata->m_positionArray->y[lastentity_index];
//        
//        elist[eAmount] = {0};
//        elist[eind[lastentity.id]] = lastentity;
//        elist[eind[e.id]] = {0};
//
//        eind[e.id] = 0;
//
//    }



   template <typename T>
    T get_component(Component_data *cdata, Entity e)
    {
        assert(false, "non specialized template");
        return nullptr;
    }
//    template <>
//    PositionComponent get_component<PositionComponent>(Component_data *cdata, Entity e)
//    {
//        auto& elist =  cdata->m_positionArray->EntityList;
//        auto& eind =  cdata->m_positionArray->EntityIndices;
//
//        auto pc = PositionComponent();
//        pc.x = cdata->m_positionArray->x[eind[e.id]];
//        pc.y = cdata->m_positionArray->y[eind[e.id]];
//        return pc;
//    }

    template<typename T>
    Signature get_component_signature(Component_data *cdata)
    {
        static Signature component_signature = {getId(cdata)};
        return component_signature;

    }
    uint64_t getId(Component_data *cdata);
}
