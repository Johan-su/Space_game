#pragma once
#include "Entity.hpp"
#include "Signature.hpp"
class SystemManager
{
public:

bool init();
bool clean();

void set_entity_signature(Entity e, Signature sig);

private:

};