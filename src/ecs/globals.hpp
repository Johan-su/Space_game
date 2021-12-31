#pragma once
#include "MemoryManager.hpp"
#include "SystemManager.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"

struct Globaldata
{
  Memory_pool *mm;
  Entity_data *edata;
  Component_data *compdata;
  System_data *sysdata;
};

extern Globaldata _g;