//
//  app.h
//  app
//
//  Created by Thomas Borregaard Sørensen on 12/05/14.
//  Copyright (c) 2014 Camilo Sasuke Tsumanuma. All rights reserved.
//

#ifndef app_app_h
#define app_app_h


#include "core/core/core/core.h"



UIWindow * new_round_window(struct plane_system * psystem, CGRect rect);


uint32_t __run_system(void * p);

plane_system * new_system(const char * pszId);

UIWindow * init_part_2ex(plane_system * psystem, CGRect rect);

void system_begin_main(plane_system * psystem);



#endif
