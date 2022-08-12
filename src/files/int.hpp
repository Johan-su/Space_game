#pragma once


#ifdef _WIN64
typedef signed char I8;
typedef short       I16;
typedef int         I32;
typedef long long   I64;

typedef long long Isize;


typedef unsigned char      U8;
typedef unsigned short     U16;
typedef unsigned int       U32;
typedef unsigned long long U64;

typedef unsigned long long Usize;

#endif

#ifdef __linux__
#include <stdint.h>

typedef int8_t  I8;
typedef int16_t I16;
typedef int32_t I32;
typedef int64_t I64;

typedef int64_t Isize;


typedef uint8_t  U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

typedef size_t   Usize;


#endif