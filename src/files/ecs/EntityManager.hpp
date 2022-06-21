#pragma once
#include "ecs_constants.hpp"
#include "Entity.hpp"
#include "MemoryManager.hpp"

namespace Ecs
{

    struct Entity_data
    {
        U64 m_entitycount;
    };

    namespace Entity_functions
    {


        void init(Entity_data *e_data);

        Entity create_entity(Entity_data *e_data);
        void destroy_entity(Entity_data *edata, Entity e);

    }
}
