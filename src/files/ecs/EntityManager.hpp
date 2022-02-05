#pragma once
#include "ecs_constants.hpp"
#include "Entity.hpp"
#include "MemoryManager.hpp"

struct Entity_data
{
  uint64_t m_entitycount;
};

namespace Entity_functions
{
  void init(Memory_pool *mem, Entity_data *e_data);
  void clean(Memory_pool *mem, Entity_data *e_data);

  Entity create_entity(Entity_data *e_data);
  void destroy_entity(Entity_data *edata, Entity e);

}