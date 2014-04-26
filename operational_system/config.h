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

#ifndef APPLE_IOS
#define APPLE_IOS
#endif
#ifndef APPLE_OS
#define APPLE_OS
#endif
#define BSD_STYLE_SOCKETS
#define HAVE_OPENSSL
#define VARIADIC_TEMPLATE



