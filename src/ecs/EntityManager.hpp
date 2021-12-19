#pragma once
#include "Entity.hpp"
#include "MemoryManager.hpp"
#include "Signature.hpp"
#include <cstdint>




class EntityManager
{
public:
  void init(MemoryManager *mem);
  void clean(MemoryManager *mem);

  Entity create_entity();
  void set_entity_signature(Entity e, Signature sig);
  Signature get_entity_signature(Entity e);



private:

  Signature *m_signatures;
  uint64_t m_entitycount;




};
