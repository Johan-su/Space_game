#include "load_gl.hpp"


#include <stdio.h>

#define x(return_t, func_name, proc_name, ...) \
proc_name func_name = NULL;

GLFUNCS

#undef x

/**
 * 
 * must be called after making OpenGL context
 * @return 0 if errors occured, otherwise 1
 */
int load_gl()
{
    int error = 1;

    #define x(return_t, func_name, proc_name, ...) \
    func_name = (proc_name) glfwGetProcAddress(#func_name); \
    if (func_name == NULL) \
    { \
        fprintf(stderr, "ERROR: Failed to load %s\n", #func_name); \
        error = 0; \
    }
    GLFUNCS

    #undef x

    return error;
}