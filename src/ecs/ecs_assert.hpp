#pragma once
#include <iostream>
#ifndef DDEBUG
#define assert(condition, message) \
 do \
{ \
   if(!(condition)) \
   { \
      std::cerr << "Assertion " << "[ " #condition " ]" \
      << " failed in " << __FILE__ << " line " << __LINE__ \
      << ": " << message << "\n"; exit(1); \
   } \
 } while(0)

#else
 do {} while(0) \

 #endif