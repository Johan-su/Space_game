#pragma once
#include <GLFW/glfw3.h>
#include <glext.h>
#include "gl_funcs.hpp"

int load_gl();


#define x(return_t, func_name, proc_name, ...) \
extern proc_name func_name;

GLFUNCS

#undef x