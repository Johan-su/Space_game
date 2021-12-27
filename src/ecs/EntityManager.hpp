#pragma once
#include "ecs_constants.hpp"
#include "Entity.hpp"
#include "MemoryManager.hpp"
#include "Signature.hpp"
#include <cstdint>

struct Entity_data
{
  Signature *m_signatures;
  uint64_t m_entitycount;  
};

namespace Entity_functions
{
  void init(Entity_data *e_data, Memory_pool *mem);
  void clean(Entity_data *e_data, Memory_pool *mem);

  Entity create_entity(Entity_data *e_data);
  void set_entity_signature(Entity_data *e_data, Entity e, Signature sig);
  Signature get_entity_signature(Entity_data *e_data, Entity e);

}