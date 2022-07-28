#include "utils.hpp"


void *Utils::align_pointer(void *ptr, Usize alignment)
{
    Usize offset = (Usize)ptr;
    offset = (offset + (alignment - 1)) & ~(alignment - 1);

    return (void *)offset;
}