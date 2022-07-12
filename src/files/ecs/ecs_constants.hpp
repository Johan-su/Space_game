#pragma once

#include "../int.hpp"





const Usize PAGE_SIZE = 1024; // increase for faster iteration at the cost of higher memory usage. different from OS pages
const Usize MAX_PAGE_AMOUNT = 4096; //TODO(Johan) swap usage of size and amount

const Usize MAX_ENTITY_AMOUNT = PAGE_SIZE * MAX_PAGE_AMOUNT; // will crash going over MAX_ENTITY_AMOUNT

const Usize ENTITY_NULL = MAX_ENTITY_AMOUNT;


const Usize MAX_SYSTEM_TYPES    = 256; // per phase, can be more than 256 systems in total
const Usize MAX_COMPONENT_TYPES = 256;
const Usize MAX_EVENT_TYPES     = 256;