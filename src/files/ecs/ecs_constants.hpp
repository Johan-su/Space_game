#pragma once

#include "../int.hpp"


#define ENTITY_NULL MAX_ENTITY_AMOUNT 


#define MAX_COMPONENT_TYPES 256

#define PAGE_SIZE 1024 // increase for faster iteration at the cost of higher memory usage.
#define MAX_PAGE_AMOUNT 4096 //TODO(Johan) swap usage of size and amount

#define MAX_ENTITY_AMOUNT PAGE_SIZE * MAX_PAGE_AMOUNT // will crash going over MAX_ENTITY_AMOUNT

#define MAX_EVENT_TYPES 256