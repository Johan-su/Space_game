#pragma once
#include <cstdint>


struct Entity //TODO(johan): move to a better place.
{
  uint64_t id;
};

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
