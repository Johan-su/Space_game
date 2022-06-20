#pragma once
#include "ecs_constants.hpp"
#include "ecs_assert.hpp"


/*
namespace Ecs
{
    struct Memory_pool
    {
        void *m_runTimeData;
        size_t m_bytesAllocated;
    };

    namespace Memory
    {

        void init(Memory_pool *mm);
        void clean(Memory_pool *mm);


        void dump(Memory_pool *mm,  const size_t size, bool addr);
    } // Memory

    namespace Memory
    {
        template<typename T>
        T *alloc(Memory_pool *mm, size_t amount = 1)
        {
            const size_t type_size = sizeof(T);

            ECS_assert(amount > 0, "Cannot allocate 0 bytes");
            ECS_assert(type_size * amount + mm->m_bytesAllocated < MEMORY_POOL_SIZE, "Out of memory");
            
            size_t padding = alignof(T);
            size_t tmp = mm->m_bytesAllocated + padding;
            mm->m_bytesAllocated += padding + type_size * amount;
                
            return (T*)((char*)(mm->m_runTimeData) + tmp);
        }

        template<typename T>
        void dealloc(Memory_pool *mm, T *ptr, size_t amount = 1)
        {
            const size_t type_size = sizeof(T);

            ECS_assert(amount > 0, "Cannot deallocate 0 bytes");
                    
            ECS_assert(mm->m_bytesAllocated - type_size * amount > 0, "Deallocation outside memory pool");
                    
            ECS_assert(ptr >= mm->m_runTimeData, "Pointer outside memory pool");
            ECS_assert((char*)ptr < (char*)mm->m_runTimeData + MEMORY_POOL_SIZE, "Pointer outside memory pool");
                    
            for(size_t i = 0; i < type_size * amount; ++i) // only sets the deallocated values to zeroes.
            {
                *((char*)(ptr) + i) = 0xDD;
            }  
        }

    } // namespace Memory
    

} // Ecs
*/
