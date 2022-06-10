#pragma once

#ifdef _WIN64


#include <Windows.h>

extern SYSTEM_INFO g_info;

namespace Windows
{
    void init();
} // namespace Windows

#endif