#pragma once
#include "Components.hpp"
#include "ecs_constants.hpp"
#include "MemoryManager.hpp"
#include "ecs_assert.hpp"
#include <cstdint>



class ComponentManager
{
public:
    bool init(MemoryManager* mem);
    bool clean(MemoryManager* mem);

public:
    template <typename T>
    void set_component(Entity e, T comp)
    {
        assert(false, "non specialized template");
    }
    template <>
    void set_component<PositionComponent>(Entity e, PositionComponent comp)
    {
        auto& elist =  m_positionArray->EntityList;
        auto& eind =  m_positionArray->EntityIndices;

        m_positionArray->x[elist[eind[e.id]].id] = comp.x;
        m_positionArray->y[elist[eind[e.id]].id] = comp.y;        
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
        pc.x = m_positionArray->x[elist[eind[e.id]].id];
        pc.y = m_positionArray->y[elist[eind[e.id]].id];
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
