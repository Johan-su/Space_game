#pragma once
#include "ecs_constants.h"
#include "Components.h"
#include <cstdint>
#include <cstddef>



class ComponentManager
{
    public:


        template <typename T>
        void set_component(Entity e)
        {

        }

        template <typename T>
        T get_component(Entity e)
        {
            auto pc = PositionComponent();
            pc.x = m_positionArray.x[e.id];
            pc.y = m_positionArray.y[e.id];

            return static_cast<T>(pc);
        }

    private:
        PositionArray m_positionArray;
        HealthArray m_healthArray;
};
