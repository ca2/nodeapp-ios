//
//  music_midi_core_audio_message_out.cpp
//  music_midi_core_audio
//
//  Created by Camilo Sasuke Tsumanuma on 15/10/18.
//  Copyright © 2018 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//

//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

//
// message_io.xaml.cpp
// Implementation of the message_io class
//

#include "framework.h"
//http://www.howtobuildsoftware.com/index.php/how-do/pQ9/ios-core-audio-midi-audiounit-audiotoolbox-ios-how-to-play-midi-notes
const int PITCH_BEND_CENTER = 8192;


namespace music
{
   
   
   namespace midi_core_midi
   {

      
      message_out::message_out(::aura::application * papp) :
         ::object(papp),
         ::music::midi::message_out(papp)
      {
         
         m_graph = NULL;
         m_synthunit = NULL;
         m_synthnode = NULL;
         m_outnode = NULL;
         
      }
      
      message_out::~message_out()
      {
         //            _midiInDeviceWatcher->Stop();
         //            _midiOutDeviceWatcher->Stop();
         //term();
      }
      
      
      bool  message_out::init()
      {
         
         NewAUGraph(&m_graph);
         
         AudioComponentDescription cd;
         
         cd.componentManufacturer = kAudioUnitManufacturer_Apple;
         
         cd.componentType = kAudioUnitType_MusicDevice;
         
         cd.componentSubType = kAudioUnitSubType_MIDISynth;
         
         //cd.componentSubType = kAudioUnitSubType_Sampler;
         
         AUGraphAddNode(m_graph, &cd, &m_synthnode);
         
         cd.componentType = kAudioUnitType_Output;
         
         cd.componentSubType = kAudioUnitSubType_RemoteIO;
         
         AUGraphAddNode(m_graph, &cd, &m_outnode);
         
         AUGraphOpen(m_graph);
         
         AUGraphConnectNodeInput(m_graph, m_synthnode, 0, m_outnode, 0);
         
         AUGraphNodeInfo(m_graph, m_synthnode, 0, &m_synthunit);
         
         AUGraphInitialize(m_graph);
         
         CAShow(m_graph);
         
         return true;
         
      }
      
      
      void  message_out::term()
      {
         
         AUGraphStop(m_graph);
         
         DisposeAUGraph(m_graph);
         
      }
      
      
      bool message_out::is_ok()
      {
         
         return true;
         
      }
      
      
      void message_out::note_on(int iChannel, unsigned char uchNote, unsigned char uchVelocity)
      {
         
         UInt32 kChannelMessage_NoteOn = 0x90;
         UInt8 channel = iChannel;
         UInt8 note = uchNote;
         UInt32 velocity = uchVelocity;
         
         MusicDeviceMIDIEvent(m_synthunit,
                              kChannelMessage_NoteOn | channel,
                              note,
                              velocity,
                              0);

      }
      
      
      void message_out::note_off(int iChannel, unsigned char uchNote, unsigned char uchVelocity)
      {
         
         UInt32 kChannelMessage_NoteOff = 0x80;
         UInt8 channel = iChannel;
         UInt8 note = uchNote;
         UInt32 velocity = uchVelocity;
         
         MusicDeviceMIDIEvent(m_synthunit,
                              kChannelMessage_NoteOff | channel,
                              note,
                              velocity,
                              0);
         
      }
      
      
      void message_out::program_change(int iChannel, unsigned char uchProgram)
      {
         
         UInt32 kChannelMessage_ProgramChange = 0xC0;
         UInt8 channel = iChannel;
         UInt8 program = uchProgram;
         
         MusicDeviceMIDIEvent(m_synthunit,
                              kChannelMessage_ProgramChange | channel,
                              program,
                              0,
                              0);
         
      }
      
      void message_out::control_change(int iChannel, unsigned char uchController, unsigned char uchValue)
      {
         
         UInt32 kChannelMessage_ControlChange = 0xB0;
         UInt8 channel = iChannel;
         UInt8 controller = uchController;
         UInt32 value = uchValue;
         
         MusicDeviceMIDIEvent(m_synthunit,
                              kChannelMessage_ControlChange | channel,
                              controller,
                              value,
                              0);
         
      }
      
      
      void message_out::pitch_bend(int iChannel, unsigned short ushBend)
      {
         
         
         UInt32 kChannelMessage_PitchBend = 0xE0;
         UInt8 channel = iChannel;
         UInt32 bendMSB = (ushBend >> 7) & 0x7F;
         UInt32 bendLSB = ushBend & 0x7F;
         
         MusicDeviceMIDIEvent(m_synthunit,
                              kChannelMessage_PitchBend | channel,
                              bendLSB,
                              bendMSB,
                              0);
         
      }
      
      void message_out::reset_all_controllers()
      {
         
         for (int channel = 0; channel < 16; channel++)
         {
            
            control_change(channel, 0x78 /*120*/ /* all sound off */, 0);
            
            control_change(channel, 0x79 /*121*/ /* reset controllers */, 0);
            
            control_change(channel, 7 /* reset volume */, 100);
            
            control_change(channel, 10 /* reset pan */, 64);
            
            pitch_bend(channel, PITCH_BEND_CENTER);
            
         }
         
         program_change(15, 127);
         
      }
      
      void message_out::step()
      {
         
         
         
      }
      
      void message_out::start()
      {
         
         CFURLRef urlSoundFont = resource_sound_font_url("Yamaha_XG_Sound_Set", "sf2");
         
         AudioUnitSetProperty(m_synthunit,
                              kMusicDeviceProperty_SoundBankURL,
                              kAudioUnitScope_Global,
                              0,
                              &urlSoundFont,
                              sizeof(urlSoundFont));
         
         AUGraphStart(m_graph);
         
//         ::file::path path;
//         
//         path.;
//         
//         CFStringRef header_ref      = CFStringCreateWithCString( NULL, path,  path.length()    );
//         
//         CFURLRef bankURL = CFURLCreateWithFileSystemPath
//         (kCFAllocatorDefault, (CFStringRef)str, kCFURLPOSIXPathStyle, NO);
         
         
      }
      
   } // namespace midi_core_midi
   
   
} // namespace music



