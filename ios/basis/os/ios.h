#pragma once


#define SECURITY_WIN32


#include "app/appseed/core/core.h"


#define CLASS_DECL_ios


string get_error_message(DWORD dwError);

base_application *     ios_instantiate_application(base_application * pappSystem, const char * pszId);

/////////////////////////////////////////////////////////////////////////////
// explicit initialization for general purpose classes

//CLASS_DECL_ios WINBOOL AfxInitialize(WINBOOL bDLL = FALSE, DWORD dwVersion = _MFC_VER);
CLASS_DECL_ios WINBOOL AfxInitialize(WINBOOL bDLL = FALSE, DWORD dwVersion = 0);

/////////////////////////////////////////////////////////////////////////////
// stop on a specific primitive::memory request

// Debugger hook on specified allocation request - Obsolete
CLASS_DECL_ios void AfxSetAllocStop(LONG lRequestNumber);

// Return TRUE if primitive::memory is sane or print out what is wrong
CLASS_DECL_ios bool __check_memory();

// Return TRUE if valid primitive::memory block of nBytes
CLASS_DECL_ios WINBOOL AfxIsMemoryBlock(const void * p, UINT nBytes,
                                        LONG* plRequestNumber = NULL);

// helper routines for non-C++ EH implementations
// for THROW_LAST auto-delete backward compatiblity
CLASS_DECL_ios void AfxThrowLastCleanup();

// other out-of-line helper functions
CLASS_DECL_ios void AfxTryCleanup();


/////////////////////////////////////////////////////////////////////////////
// Global implementation helpers

// window creation hooking
CLASS_DECL_ios void AfxHookWindowCreate(::user::interaction * pWnd);
CLASS_DECL_ios WINBOOL AfxUnhookWindowCreate();
CLASS_DECL_ios void AfxResetMsgCache();

// for backward compatibility to previous versions
#define _AfxHookWindowCreate    AfxHookWindowCreate
#define _AfxUnhookWindowCreate  AfxUnhookWindowCreate

#include "ios1.h"
#include "ios_implementation.h"
#include "ios_state.h"
//#include "ios_handle.h"
// xxx #include "ios_file_find.h"
#include "ios_dir.h"
// xxx #include "ios_folder_watch.h"
#include "ios_factory_exchange.h"
#include "ios_window_draw.h"
#include "ios_thread.h"
#include "ios_window.h"
#include "ios_os.h"
#include "ios_port_forward.h"
#include "ios_copydesk.h"
#include "ios_crypto.h"
#include "ios_ip_enum.h"

#define NULL_REF(class) (*((class *) NULL))
// xxx CLASS_DECL_ios WNDPROC AfxGetAfxWndProc();
#define AfxWndProc (*AfxGetAfxWndProc())

#define IOS_THREAD(pthread) (dynamic_cast < ::ios::thread * > (dynamic_cast < ::thread * >(pthread)))
#define IOS_WINDOW(pwnd) (dynamic_cast < ::ios::window * > (dynamic_cast < ::window * >(pwnd)))

#include "ios_shell.h"

CLASS_DECL_ios void __trace_message(const char * lpszPrefix, signal_details * pobj);
CLASS_DECL_ios void __trace_message(const char * lpszPrefix, LPMESSAGE lpmsg);

CLASS_DECL_ios WINBOOL __cdecl __is_idle_message(signal_details * pobj);
CLASS_DECL_ios WINBOOL __cdecl __is_idle_message(MESSAGE* pMsg);


CLASS_DECL_ios void AfxProcessWndProcException(::exception::base*, signal_details * pobj);
CLASS_DECL_ios void __cdecl __pre_translate_message(signal_details * pobj);
#include "ios_printer.h"

#include "ios_application.h"



WINBOOL PeekMessage(
                    LPMESSAGE lpMsg,
                    oswindow hWnd,
                    UINT wMsgFilterMin,
                    UINT wMsgFilterMax,
                    UINT wRemoveMsg);

WINBOOL GetMessage(
                   LPMESSAGE lpMsg,
                   oswindow hWnd,
                   UINT wMsgFilterMin,
                   UINT wMsgFilterMax);



int32_t CLASS_DECL_ios __ios_main(int32_t argc, char * argv[]);


CLASS_DECL_ios void vfxThrowFileException(base_application * papp, int32_t cause, LONG lOsError, const char * lpszFileName = NULL);
