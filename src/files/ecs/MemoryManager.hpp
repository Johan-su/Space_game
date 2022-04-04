#pragma once
#include "ecs_constants.hpp"
#include "ecs_assert.hpp"

#include <stdint.h>

#define MEMORY_ALLOC(memory_pool, type, amount) (type*) Memory::alloc(memory_pool, sizeof(type), alignof(type), amount)
#define MEMORY_DEALLOC(memory_pool, type, ptr, amount) Memory::dealloc(memory_pool, sizeof(type), alignof(type), ptr, amount)

namespace Ecs
{
    struct Memory_pool
    {
        void *m_runTimeData;
        size_t m_bytesAllocated;
        bool m_MemoryActive;
        
        uint8_t padding1;
        uint8_t padding2;
        uint8_t padding3;
        uint8_t padding4;
        uint8_t padding5;
        uint8_t padding6;
        uint8_t padding7;

    };

    namespace Memory
    {

        void init(Memory_pool *mm);
        void clean(Memory_pool *mm);


        void *alloc(Memory_pool *mm, size_t type_size, size_t type_alignment, size_t amount = 1);
        void dealloc(Memory_pool *mm, size_t type_size, size_t type_alignment, void *ptr, size_t amount = 1);

        void dump(Memory_pool *mm,  const size_t size, bool addr);
    } // Memory
} // Ecs


