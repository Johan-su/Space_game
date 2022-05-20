#include "EventManager.hpp"

#include "../assert.hpp"

#include <string.h>


using namespace Ecs;





void Event_functions::init(event_data *ed)
{
    memset(ed, 0, sizeof(*ed));
}



