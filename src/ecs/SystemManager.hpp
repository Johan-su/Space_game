#pragma once
#include "Entity.hpp"
#include "Signature.hpp"

struct System_data
{

};

namespace System_functions
{

bool init();
bool clean();

void set_entity_signature(Entity e, Signature sig);

}
