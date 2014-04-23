//
//  main.m
//  app_ios
//
//  Created by Camilo Sasuke Tsumanuma on 4/20/14.
//  Copyright (c) 2014 Camilo Sasuke Tsumanuma. All rights reserved.
//

//
//  Prefix header
//
//  The contents of this file are implicitly included at the beginning of every source file.
//


#define _POSIC_C_SOURCE 200809L

#import <Availability.h>

#ifndef __IPHONE_3_0
#warning "This project uses features only available in iOS SDK 3.0 and later."
#endif

#ifdef __OBJC__
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#endif


int __ios_main(int argc, char * argv[]);


int main(int argc, char * argv[])
{
    
    return __ios_main(argc, argv);
   
}
