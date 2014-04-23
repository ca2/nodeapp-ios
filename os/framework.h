#ifndef __GNUC__
#pragma once
#endif

#ifdef __OBJC__
#ifdef __cplusplus
#import "ios_mm.h"
#else
#error "unexcpected!! was a .m or object-c file include?! only c++ files in os library leve!!"
#endif
#include "mac.h"
#include "mac_internal.h"
#endif




