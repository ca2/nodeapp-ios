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



#if defined(_DEBUG) && !defined(DEBUG)
#define DEBUG 1
#endif


#define STORE_LAST_BLOCK 1
#define MEMDFREE 1
#define MEMDLEAK 1


#define BSD_STYLE_SOCKETS
#define HAVE_OPENSSL
#define VARIADIC_TEMPLATE



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


#define AXIS_FREEIMAGE


#define FONT_SANS "sans-serif"
#define FONT_SERIF "serif"
#define FONT_SANS_EX "sans-serif"
#define FONT_SERIF_EX "serif"
#define FONT_SANS_FX "sans-serif"
#define FONT_SERIF_FX "serif"





