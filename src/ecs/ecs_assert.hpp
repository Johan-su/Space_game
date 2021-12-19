#pragma once
#include <iostream>
#define assert(condition, message) \
 do \
{ \
   if(!(condition)) \
   { \
      std::cerr << "Assertion " << " #condition " \
      << " failed in " << __FILE__ << " line " << __LINE__ \
      << ": " << message << "\n"; \
   } \
 } while(0)