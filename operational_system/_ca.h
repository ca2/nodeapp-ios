//
//  _ca.h
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 6/18/13.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//


//
//  Prefix header
//
//  The contents of this file are implicitly included at the beginning of every source file.
//

#import <Availability.h>

#ifndef __IPHONE_3_0
#warning "This project uses features only available in iOS SDK 3.0 and later."
#endif

#ifdef __OBJC__
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#else
#include <QuartzCore/QuartzCore.h>
#endif


#include "get_platform.h"







#ifndef _POSIX_C_SOURCE
xxx4
#elif _POSIX_C_SOURCE < 200809L
zzz4
#endif






