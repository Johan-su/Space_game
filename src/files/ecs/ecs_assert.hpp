#pragma once
#include <iostream>


#ifdef _DEBUG
#define assert(condition, message)                         \
 do                                                        \
{                                                          \
   if(!(condition))                                        \
   {                                                       \
      std::cerr << "Assertion " << "[ " #condition " ]"    \
      << " failed in " << __FILE__ << " line " << __LINE__ \
      << ": " << message << "\n";                          \
      exit(1);                                             \
   }                                                       \
} while(0)

#else
#define assert(condition, message) \
do {} while(0)

 #endif