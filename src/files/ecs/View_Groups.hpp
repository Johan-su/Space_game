#pragma once
#include "Entity.hpp"
#include "ecs_constants.hpp"

template<typename T>
class Collection
{
public:
    size_t size;
    Entity *m_entities;
    T *comparray; // only one component type

    Collection(size_t size)
    {
        this->size = size;

        //this->m_entities = Memory::alloc<Entity>(mm, size);
        //this->comparray  = Memory::alloc<T>(mm, size);
    }

    ~Collection()
    {
        //Memory::dealloc<Entity>(mm, m_entities, size);
        //Memory::dealloc<T>(mm, comparray, size);
    }
};



template<typename T>
struct View
{
    size_t size;
    Entity entity_list[VIEW_SIZE];
    T comparray[VIEW_SIZE];
};
