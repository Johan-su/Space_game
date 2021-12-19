#pragma once
#include "MemoryManager.h"
#include "ComponentManager.h"
#include "EntityManager.h"

struct Globaldata
{
  MemoryManager *mem;
  ComponentManager *compm;
  EntityManager *enm;

};

extern Globaldata g_data;