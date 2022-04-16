#pragma once
#define MEMORY_POOL_SIZE 104857600 // 100 MiB


#define MAX_ENTITY_AMOUNT 50000 // about 2^10
#define ENTITY_NULL MAX_ENTITY_AMOUNT - 1


#define MAX_COMPONENT_TYPES 256
#define PAGE_SIZE 1024 // increase for faster iteration at the cost of higher memory usage.
#define MAX_PAGE_AMOUNT 4096

#define VIEW_SIZE 10000 // increase for faster iteration at the cost of higher memory usage.

#define MAX_EVENT_TYPES 256