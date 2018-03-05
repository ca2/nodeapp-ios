//
//  config.h
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 2013-09-17.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
//
//  config.h
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 2013-09-17.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#pragma once

#define CUBE // 21 de Julho de 2017, ThomasBS-LiveEdu.TV

#if defined(_DEBUG) && !defined(DEBUG)
#define DEBUG 1
#endif


#define STORE_LAST_BLOCK 0
#define MEMDFREE 0
#define MEMDLEAK 0


#define BSD_STYLE_SOCKETS
#define HAVE_OPENSSL
//#define OPENSSL_MIN_API 0x00908000L
#define VARIADIC_TEMPLATE_FORMAT2



#ifndef APPLEOS
#define APPLEOS
#endif


#ifndef APPLE_OS
#define APPLE_OS
#endif



#ifndef APPLE_IOS
#define APPLE_IOS
#endif




#define CLASS_DECL_IMPORT
#define CLASS_DECL_EXPORT
#define CLASS_DECL_THREAD __thread

#ifndef OSBIT
#include "nodeapp/operational_system/bit.h"
#endif





#define static_inline inline


#ifdef __cplusplus

#define LOG_THIS_TAG (typeid(*this).name())
#define LOG_MEMBER_PREFIX __FUNCTION__

#endif


#define AXIS_FREEIMAGE


#define FONT_SANS "sans-serif"
#define FONT_SERIF "serif"
#define FONT_SANS_EX "sans-serif"
#define FONT_SERIF_EX "serif"
#define FONT_SANS_FX "sans-serif"
#define FONT_SERIF_FX "serif"





