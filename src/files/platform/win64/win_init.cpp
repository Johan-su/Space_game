#include "win_init.hpp"



#ifdef _WIN64


SYSTEM_INFO g_info;

void Windows::init()
{

    GetSystemInfo(&g_info);
}

#endif