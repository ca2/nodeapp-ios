#pragma once

// STRICT is the only supported option (NOSTRICT is no longer supported)
#ifndef STRICT
#define STRICT 1
#endif

#ifdef DEBUG
#undef DEBUG
#define DEBUG 1
#else
#define DEBUG 0
#endif

#if defined(_MM) || defined(_M)

#import <UIKit/UIKit.h>

#endif

#if DEBUG
#undef DEBUG
#define DEBUG
#else
#undef DEBUG
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

#ifndef EXPORT
#define EXPORT
#endif

