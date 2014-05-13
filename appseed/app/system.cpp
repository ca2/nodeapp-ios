//
//  system.cpp
//  app
//
//  Created by Thomas Borregaard Sørensen on 12/05/14.
//  Copyright (c) 2014 Camilo Sasuke Tsumanuma. All rights reserved.
//

#include "app.h"










//
//  app_system.cpp
//  app
//
//  Created by Thomas Borregaard Sørensen on 12/05/14.
//  Copyright (c) 2014 Camilo Sasuke Tsumanuma. All rights reserved.
//







plane_system * new_system(const char * pszId)
{
   
   on_init_thread();
   
   
   return new ::plane_system(pszId);
   
   
   
}

plane_system::plane_system(const char * pszId)
{
   
   m_psystem = new ::plane::system();
   
   m_psystem->m_posdata->m_pui = new ::user::interaction(m_psystem);
   
   ::ios::main_init_data * pinitmaindata  = new ::ios::main_init_data;
   
   
   
   pinitmaindata->m_hInstance             = NULL;
   pinitmaindata->m_hPrevInstance         = NULL;
   pinitmaindata->m_vssCommandLine        = pszId;
   pinitmaindata->m_nCmdShow              = 0;
   
   m_psystem->init_main_data(pinitmaindata);
   
   
   
}

UIWindow * init_part_2ex(plane_system * psystem, CGRect rect)
{
   
   return psystem->init_part_2ex(rect);
   
}


UINT system_main(LPVOID lp)
{
   ::plane::system * m_psystem = (::plane::system *) lp;
   try
   {
      m_psystem->set_thread(m_psystem);
      m_psystem->m_iReturnCode = 0;
      m_psystem->m_bReady = true;
      m_psystem->m_bRun = true;
      m_psystem->thread::m_p->m_bRun= true;
      m_psystem->m_iReturnCode = m_psystem->on_run();
      if(m_psystem->m_iReturnCode != 0)
      {
         ::OutputDebugStringW(L"application::main on_run termination failure");
      }
      if(m_psystem->is_system())
      {
         m_psystem->os().post_to_all_threads(WM_QUIT, 0, 0);
      }
      try
      {
         m_psystem->m_iReturnCode = m_psystem->exit();
      }
      catch(...)
      {
         m_psystem->m_iReturnCode = -1;
      }
      
   }
   catch(::exit_exception &)
   {
      
      m_psystem->os().post_to_all_threads(WM_QUIT, 0, 0);
      
   }
   
   return 0;
}


UIWindow * plane_system::init_part_2ex(CGRect rect)
{
   
   //m_psystem->m_window = ios_start_window(this, rect);
   
   int nReturnCode = 0;
   
   nReturnCode = m_psystem->main_start();
   
   UIWindow * pwindow = new_round_window(this, rect);
   
   //::user::native_window_initialize initialize;
   
   //initialize.pwindow = this;
   //initialize.window = m_window.Get();
   
   //m_psystem->m_posdata->m_pui->initialize(&initialize);
   
   //m_psystem->m_ptwf = create_twf_2ex();
   
   //m_psystem->m_ptwf->twf_start();
   
   stringa straLibrary = m_psystem->command()->m_varTopicQuery["app"];
   
   for(int i = 0; i < m_psystem->command()->m_varTopicQuery["app"].get_count(); i++)
   {
      string strApp = m_psystem->command()->m_varTopicQuery["app"][i];
   }
   
   straLibrary.replace("\\", "_");
   straLibrary.replace("-", "_");
   
   for(int i = 0; i < straLibrary.get_count(); i++)
   {
      string strLibrary = straLibrary[i];
      strsize iFind = strLibrary.find("/");
      if(iFind >= 0)
         strLibrary = strLibrary.Left(iFind) + '_' + strLibrary.Mid(iFind + 1);
      iFind = strLibrary.find("/", iFind + 1);
      if(iFind >= 0)
         strLibrary.Truncate(iFind);
      m_psystem->m_mapAppLibrary[m_psystem->command()->m_varTopicQuery["app"][i]] = strLibrary;
   }
   
   for(int i = 0; i < m_psystem->command()->m_varTopicQuery["app"].get_count(); i++)
   {
      string strApp = m_psystem->command()->m_varTopicQuery["app"][i];
   }
   
   m_psystem->m_mapAppLibrary["app/ca2/cube"] = "ca2";
   m_psystem->m_mapAppLibrary["app/ca2/bergedge"] = "ca2";
   
   return pwindow;
}


void system_begin_main(plane_system * psystem)
{
   
   psystem->begin();
   
}

void plane_system::begin()
{
   
   __begin_thread(m_psystem, &system_main, m_psystem);
   
}

