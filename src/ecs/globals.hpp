#pragma once
#include "MemoryManager.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"

struct Globaldata
{
  MemoryManager *mem;
  ComponentManager *compm;
  EntityManager *enm;

};

extern Globaldata g_data;