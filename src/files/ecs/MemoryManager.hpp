#pragma once
#include "ecs_constants.hpp"
#include "ecs_assert.hpp"

#include <stdint.h>

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

        void dump(Memory_pool *mm,  const size_t size, bool addr);
    
        template <typename T>  
        T *alloc(Memory_pool *mm, size_t amount = 1)
        {
            ECS_assert(amount > 0, "Cannot allocate 0 bytes");
            ECS_assert(mm->m_MemoryActive, "Inactive memory pool");
            const size_t type_size = sizeof(T);
            ECS_assert(type_size * amount + mm->m_bytesAllocated < MEMORY_POOL_SIZE, "Out of memory");
        
            uint64_t padding = mm->m_bytesAllocated % type_size;

            uint64_t tmp = mm->m_bytesAllocated + padding;
            mm->m_bytesAllocated += padding + type_size * amount;
            
            return (T*)(((char*)(mm->m_runTimeData)) + tmp); // C++ forcing this mess
        }



        template <typename T>
        void dealloc(Memory_pool *mm, T *pointer, size_t amount = 1)
        {
            ECS_assert(amount > 0, "Cannot deallocate 0 bytes");
            ECS_assert(mm->m_MemoryActive, "Inactive memory pool");
            const size_t size = sizeof(T);
            
            ECS_assert(mm->m_bytesAllocated - size * amount > 0, "Deallocation outside memory pool");
            
            ECS_assert(pointer >= mm->m_runTimeData, "Pointer outside memory pool");
            ECS_assert((char*)pointer < (char*)mm->m_runTimeData + MEMORY_POOL_SIZE, "Pointer outside memory pool");
            
            for(size_t i = 0; i < size * amount; ++i)
            {
                *((char*)(pointer) + i) = 0;
            }
        }
    }
}

