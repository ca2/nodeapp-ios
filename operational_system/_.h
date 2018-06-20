#pragma once


#define APPLE_IOS
#define APPLEOS


#define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0


#define _POSIX_SOURCE 200809L
#define _POSIX_C_SOURCE 200809L
#define _DARWIN_C_SOURCE 200809L
#define _XOPEN_SOURCE 700

#define CLASS_DECL_IMPORT
#define CLASS_DECL_EXPORT
#define CLASS_DECL_THREAD __thread

#define DECL_C
//#define PASCAL


#define _PRE_WIDEN(x) L ## x
#define _WIDEN(x) _PRE_WIDEN(x)

#define NOTHROW throw()
#define THROWS // gnucc null throw statement means that the function can throw any exception



#ifdef DEBUG

#define RELEASENOTHROW

#else

#define RELEASENOTHROW throw()

#endif







#ifdef _LP64
#define OS64BIT
#define OSBIT 64
#else
#define OSBIT 32
#endif


