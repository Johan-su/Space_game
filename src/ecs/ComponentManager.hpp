#pragma once
#include "ecs_constants.hpp"
#include "Components.hpp"
#include "MemoryManager.hpp"
//#include "globals.hpp"
#include "ecs_assert.hpp"
#include <cstdint>
#include <cstddef>



class ComponentManager
{
public:
    bool init(MemoryManager* mem);
    bool clean(MemoryManager* mem);



    template <typename T>
    void set_component(Entity e)
    {
    }
   template <typename T>
    T get_component(Entity e)
    {
        assert(false, "non specialized template"); // non specialized template
        return;
    }
    template <>
    PositionComponent get_component<PositionComponent>(Entity e)
    {
        auto pc = PositionComponent();
        pc = {0.0f, 0.0f};
        return pc;
    }
    /*PositionComponent get_component(Entity e)
    {
        auto pc = PositionComponent();
        pc.x = m_positionArray.x[e.id];
        pc.y = m_positionArray.y[e.id];
        return pc;
    }*/

private:
    PositionArray *m_positionArray;
    HealthArray *m_healthArray;
};
