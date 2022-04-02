#pragma once
#include <stdio.h>
#include <stdlib.h>

#ifdef _DEBUG
#define ECS_assert(condition, message)                                                                          \
do                                                                                                              \
{                                                                                                               \
   if(!(condition))                                                                                             \
   {                                                                                                            \
      fprintf(stderr, "Assertion [ %s ] failed in %s line %u : %s\n", #condition, __FILE__, __LINE__, message); \
      exit(1);                                                                                                  \
   }                                                                                                            \
} while(0)

#define ECS_dbg(expression) \
do                          \
{                           \
   expression;              \
} while (0) 




#else
#define ECS_assert(condition, message) \
do {} while(0)

#define ECS_dbg(expression) \
do {} while(0)


 #endif