//
//  round_window.cpp
//  os
//
//  Created by Camilo Sasuke Tsumanuma on 6/8/13.
//  Copyright (c) 2013 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//
#import "ios_mm.h"
#import "AppDelegate.h"


round_window * ios_start_window(struct plane_system * psystem, CGRect rect);
void ios_initialize_window(round_window * pwindow, UIWindow * window);


UIWindow * new_round_window(round_window * pwindow, CGRect rect)
{
   
   
    
   
   pwindow->m_proundwindow = [RoundWindow alloc];
   
   pwindow->m_proundwindow->m_pwindow = pwindow;
  
   return [pwindow->m_proundwindow initWithFrame:[[UIScreen mainScreen] bounds]];

}



UIWindow * new_round_window(struct plane_system * psystem, CGRect rect)
{
   
   round_window * pwindow = ios_start_window(psystem, rect);
   
   UIWindow * window = new_round_window(pwindow, rect);
   
   ios_initialize_window(pwindow, window);
                       
   return window;
   
}


void ui_application_main(int argc, char * argv[])
{
    
    @autoreleasepool
    {
        
//        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));

        UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));

    }
    
}



void ui_app_run(int argc, char * argv[])
{
    
    
}



void round_window::round_window_show()
{
   
//   [[m_proun dd_invokeOnMainThread] showWindow : m_proundwindow];
   
}

void round_window::round_window_redraw()
{

   [[m_proundwindow dd_invokeOnMainThread] display ];
   
}


void round_window::round_window_invalidate()
{
   
//   [[m_proundwindow->m_controller dd_invokeOnMainThread] setViewsNeedDisplay : TRUE];
   
}
