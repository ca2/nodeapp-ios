//
//  window.cpp
//  app
//
//  Created by Thomas Borregaard Sørensen on 12/05/14.
//  Copyright (c) 2014 Camilo Sasuke Tsumanuma. All rights reserved.
//

#include "app.h"


round_window * ios_start_window(plane_system * psystem, CGRect rect)
{
   
   ::user::interaction * pui = psystem->m_psystem->m_posdata->m_pui;
   
   ::user::native_window_initialize initialize;
   
   initialize.m_rect.left = rect.origin.x;
   initialize.m_rect.top = rect.origin.y;
   initialize.m_rect.right = rect.origin.x + rect.size.width;
   initialize.m_rect.bottom = rect.origin.x + rect.size.height;
   
   pui->initialize(&initialize);
   
   return pui->m_pimpl.cast < ::ios::window > ();
   
}

int ios_initialize_window(round_window * proundwindow, UIWindow * window)
{
   
   ::ios::window * pwindow = dynamic_cast < ::ios::window * > (proundwindow);
   
   pwindow->m_oswindow = oswindow_get(window);
   
   pwindow->m_oswindow->set_user_interaction(pwindow->m_pui);
   CREATESTRUCT cs;
   cs.dwExStyle = 0;
   cs.lpszClass = 0;
   cs.lpszName = NULL;
   cs.style = 0;
   cs.x = 0;
   cs.y = 0;
   cs.cx = 0;
   cs.cy = 0;
   //      cs.hwndParent = hWndParent;
   //   cs.hMenu = hWndParent == NULL ? NULL : nIDorHMenu;
   cs.hMenu = NULL;
   //      cs.hInstance = System.m_hInstance;
   cs.lpCreateParams = NULL;
   
   if(pwindow->m_pui != NULL && pwindow->m_pui != pwindow)
   {
      
      if(!pwindow->m_pui->pre_create_window(cs))
      {
         
         pwindow->PostNcDestroy();
         
         return FALSE;
         
      }
      
   }
   else
   {
      
      if (!pwindow->pre_create_window(cs))
      {
         
         pwindow->PostNcDestroy();
         
         return FALSE;
         
      }
      
   }
   
   if(cs.hwndParent == NULL)
   {
      
      cs.style &= ~WS_CHILD;
      
   }
   
   pwindow->m_pui->m_pthread = ::get_thread();
   
   pwindow->send_message(WM_CREATE, 0, (LPARAM) &cs);
   
   ::rect rectMainScreen;
   
   GetMainScreenRect(rectMainScreen);
   
   pwindow->SetPlacement(rectMainScreen);
   
   return TRUE;
   
}







UIWindow * new_round_window(struct plane_system * psystem, CGRect rect)
{
   
   round_window * pwindow = ios_start_window(psystem, rect);
   
   UIWindow * window = new_round_window(pwindow, rect);
   
   ios_initialize_window(pwindow, window);
   
   return window;
   
}