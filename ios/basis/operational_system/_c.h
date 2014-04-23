//
//  _c.h
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 6/18/13.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#pragma once


#ifndef _POSIX_C_SOURCE
xxx2
#elif _POSIX_C_SOURCE < 200809L
zzz2
#endif


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <inttypes.h>
#include <sys/time.h>
#include <pthread.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>



#define DWORD     uint32_t
#define BYTE      uint8_t

//#define NULL 0
#define _strcmpi strcasecmp



#ifdef _LP64

typedef int64_t int_ptr;
typedef uint64_t uint_ptr;
#define int3264   int64_t

#else

typedef int32_t int_ptr;
typedef uint32_t uint_ptr;
#define int3264   int32_t

#endif


typedef void * PVOID;

#define _strcmpi strcasecmp



#ifndef _POSIX_C_SOURCE
xxx
#elif _POSIX_C_SOURCE < 200809L
zzz
#endif




#ifndef _POSIX_C_SOURCE
xxx
#elif _POSIX_C_SOURCE < 200809L
zzz
#endif





#ifndef _POSIX_C_SOURCE
xxx3
#elif _POSIX_C_SOURCE < 200809L
zzz3
#endif