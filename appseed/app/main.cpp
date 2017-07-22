
//
//  main.cpp
//  app
//
//  Created by Camilo Sasuke Tsumanuma on 12/05/14.
//  Copyright (c) 2014 Camilo Sasuke Tsumanuma. All rights reserved.
//

#include "app.h"






UIWindow * new_round_window(struct plane_system * psystem, CGRect rect);







//int32_t CLASS_DECL_BASE ca2_main(HINSTANCE hInstance, HINSTANCE hPrevInstance, const char * lpCmdLine, int32_t nCmdShow)
//{
//   try
//   {
//      
//      //      _set_purecall_handler(_ca2_purecall);
//      
//      ::plane::system * psystem = new ::plane::system();
//      
//      
//      //Sleep(30 * 1000);
//      
//      
//      ASSERT(hPrevInstance == NULL);
//      
//      int32_t nReturnCode = 0;
//      
//      ::ios::main_init_data * pinitmaindata  = new ::ios::main_init_data;
//      
//      pinitmaindata->m_hInstance             = hInstance;
//      pinitmaindata->m_hPrevInstance         = hPrevInstance;
//      pinitmaindata->m_strCommandLine        = lpCmdLine;
//      pinitmaindata->m_nCmdShow              = nCmdShow;
//      
//      
//      psystem->init_main_data(pinitmaindata);
//      
//      
//      nReturnCode = psystem->main();
//      
//      
//      __ios_term();
//      
//      
//      try
//      {
//         delete psystem;
//      }
//      catch(...)
//      {
//      }
//      
//      psystem = NULL;
//      
//      try
//      {
//         //         delete __get_module_state()->m_pmapHWND;
//      }
//      catch(...)
//      {
//      }
//      /*      try
//       {
//       delete __get_module_state()->m_pmapHDC;
//       }
//       catch(...)
//       {
//       }*/
//      /*      try
//       {
//       delete __get_module_state()->m_pmapHGDIOBJ;
//       }
//       catch(...)
//       {
//       }*/
//      //      delete __get_module_state()->m_pmapHMENU;
//      try
//      {
//         __get_module_state()->m_pmapHWND     = NULL;
//      }
//      catch(...)
//      {
//      }
//      /*      try
//       {
//       __get_module_state()->m_pmapHDC      = NULL;
//       }
//       catch(...)
//       {
//       }
//       try
//       {
//       __get_module_state()->m_pmapHGDIOBJ  = NULL;
//       }
//       catch(...)
//       {
//       }*/
//      
//      //      set_heap_mutex(NULL);
//      
//      
//      return nReturnCode;
//   }
//   catch(...)
//   {
//   }
//   return -1;
//}



void __cdecl _null_se_translator(uint32_t uiCode, EXCEPTION_POINTERS * ppointers)
{
   UNREFERENCED_PARAMETER(uiCode);
   UNREFERENCED_PARAMETER(ppointers);
}






//::base::application *     win_application_create(::application * pappSystem, const char * pszId);
//::application *     win_instantiate_application(::application * pappSystem, const char * pszId);
//int32_t                     win_application_procedure(::application * pappSystem)
//UINT c_cdecl          win_application_thread_proc(LPVOID);
/////////////////////////////////////////////////////////////////////////////
// Standard WinMain implementation
//  Can be replaced as long as '::ca2::WinInit' is called first






