#ifdef _WIN64
#include "win_init.hpp"





SYSTEM_INFO g_info;

void Windows::init()
{

    GetSystemInfo(&g_info);
}

#endif