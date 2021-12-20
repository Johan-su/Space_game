#pragma once
#include "Components.hpp"
#include "ecs_constants.hpp"
#include "Entity.hpp"
#include "MemoryManager.hpp"
#include "ecs_assert.hpp"
#include <cstdint>



class ComponentManager
{
public:
    bool init(MemoryManager *mem);
    bool clean(MemoryManager *mem);

private:
    template<typename T>
    bool array_init(T *array, MemoryManager *mem)
    {
        array = mem->alloc<T>();
        return 0;
    }

public:
    template <typename T>
    void set_component(Entity e, T& comp)
    {
        assert(false, "non specialized template");
    }
    template <>
    void set_component<PositionComponent>(Entity e, PositionComponent& comp)
    {
        Entity *elist =  m_positionArray->EntityList;
        uint64_t *eind =  m_positionArray->EntityIndices;
        uint64_t &eAmount = m_positionArray->EntityAmount;


        eind[e.id] = eAmount++;

        elist[eind[e.id]] = e;


        m_positionArray->x[eind[e.id]] = comp.x;
        m_positionArray->y[eind[e.id]] = comp.y;        
    }

    template<typename T>
    void destroy_component(Entity e)
    {
        assert(false, "non specialized template");       
    }
    template<>
    void destroy_component<PositionComponent>(Entity e)
    { // https://gist.github.com/dakom/82551fff5d2b843cbe1601bbaff2acbf
    
        Entity *elist =  m_positionArray->EntityList;
        uint64_t *eind =  m_positionArray->EntityIndices;
        uint64_t &eAmount = m_positionArray->EntityAmount;



        Entity lastentity = elist[--eAmount];
        uint64_t lastentity_index = eind[lastentity.id];
        eind[lastentity.id] = eind[e.id];
        m_positionArray->x[eind[e.id]] = m_positionArray->x[lastentity_index];
        m_positionArray->y[eind[e.id]] = m_positionArray->y[lastentity_index];
        
        elist[eAmount] = {0};
        elist[eind[lastentity.id]] = lastentity;
        elist[eind[e.id]] = {0};

        eind[e.id] = 0;

    }



   template <typename T>
    T get_component(Entity e)
    {
        assert(false, "non specialized template");
        return nullptr;
    }
    template <>
    PositionComponent get_component<PositionComponent>(Entity e)
    {
        auto& elist =  m_positionArray->EntityList;
        auto& eind =  m_positionArray->EntityIndices;

        auto pc = PositionComponent();
        pc.x = m_positionArray->x[eind[e.id]];
        pc.y = m_positionArray->y[eind[e.id]];
        return pc;
    }



    /*PositionComponent get_component(Entity e)
    {
        auto pc = PositionComponent();
        pc.x = m_positionArray.x[e.id];
        pc.y = m_positionArray.y[e.id];
        return pc;
    }*/
    template<typename T>
    Signature get_component_signature()
    {
        static Signature component_signature = {getId()};
        return component_signature;

    }
private:
    uint64_t getId()
    {
        assert(m_componentIdCount != 0, "More than " + std::to_string(MAX_COMPONENT_TYPES) + " components registered");
        uint64_t tmp = m_componentIdCount;
        m_componentIdCount = m_componentIdCount << 1;
        return tmp;
    }


private:
    uint64_t m_componentIdCount;

    PositionArray *m_positionArray;
    HealthArray *m_healthArray;
};
