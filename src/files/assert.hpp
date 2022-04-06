#pragma once
#include <stdlib.h>
#include <stdio.h>


#ifdef _DEBUG
#define assert(condition, message)                                                                              \
do                                                                                                              \
{                                                                                                               \
   if(!(condition))                                                                                             \
   {                                                                                                            \
      fprintf(stderr, "Assertion [ %s ] failed in %s line %u : %s\n", #condition, __FILE__, __LINE__, message); \
      exit(1);                                                                                                  \
   }                                                                                                            \
} while(0)

#define dbg(expression) \
do                          \
{                           \
   expression;              \
} while (0) 




#else
#define assert(condition, message) \
do {} while(0)

#define dbg(expression) \
do {} while(0)

#endif