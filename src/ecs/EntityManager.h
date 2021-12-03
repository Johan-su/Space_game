#pragma once
#include "Entity.h"
#include <cstdint>




class EntityManager
{
public:
  void init();
  void clean();

  Entity create_entity();
  void set_entity_signature(/*signature goes here*/);
  void get_entity_signature(Entity e);



private:

  //signature[] m_signature;




};
