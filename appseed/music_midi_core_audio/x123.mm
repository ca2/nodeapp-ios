//
//  x123.m
//  music_midi_core_audio
//
//  Created by Camilo Sasuke Tsumanuma on 16/10/18.
//  Copyright © 2018 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//

#import <Foundation/Foundation.h>


CFURLRef  resource_sound_font_url(const char * psz, const char *pszExt)
{
   
   NSString * strName = [[NSString alloc] initWithUTF8String: psz];
   
   NSString * strExtension = [[NSString alloc] initWithUTF8String: pszExt];
   
   return (CFURLRef) CFBridgingRetain([[NSBundle mainBundle] URLForResource: strName withExtension: strExtension]);
   
   
}
