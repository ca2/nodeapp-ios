//
//  music_midi_core_audio_message_out.hpp
//  music_midi_core_audio
//
//  Created by Camilo Sasuke Tsumanuma on 15/10/18.
//  Copyright © 2018 ca2 Desenvolvimento de Sofware Ltda. All rights reserved.
//

#pragma once


namespace music
{
   
   
   namespace midi_core_midi
   {
      
      
      class CLASS_DECL_VERIWELL_MULTIMEDIA message_out :
      virtual public ::music::midi::message_out
      {
      public:
         
         
         AUGraph        m_graph;
         AudioUnit      m_synthunit;
         AUNode         m_synthnode;
         AUNode         m_outnode;


         
         message_out(::aura::application * papp);
         virtual ~message_out();
         
         virtual bool init();
         virtual void term();
         
         
         virtual void start();
         
         //void ShowStatusMessage(String^ text);
         //void ShowExceptionMessage(Exception^ ex);
         
         //void EnableMessageBuilding();
         //void ResetMessageBuilding(bool resetMessageType);
         
         
         
         //            void OnMessageReceived(MidiInPort ^sender, MidiMessageReceivedEventArgs ^args);
         //
         //            DeviceInformation^ GetDeviceInformationForInPort(String^ friendlyName);
         //            DeviceInformation^ GetDeviceInformationForOutPort(String^ friendlyName);
         
         //            void CloseInPort(String^ portId);
         //            void CloseOutPort(String^ portId);
         
         //            int get_out_port_count();
         //            String ^ get_out_port_name(int i);
         //            void select_out_port(String ^ str);
         //
         //            void add_out_port(String ^ portId);
         //            void clear_out_ports();
         
         //            void send(MidiMessageType etype);
         
         virtual void note_on(int iChannel, unsigned char uchNote, unsigned char uchVelocity);
         virtual void note_off(int iChannel, unsigned char uchNote, unsigned char uchVelocity);
         virtual void program_change(int iChannel, unsigned char uchProgram);
         virtual void control_change(int iChannel, unsigned char uchController, unsigned char uchValue);
         virtual void pitch_bend(int iChannel, unsigned short ushBend);
         
         virtual void reset_all_controllers();
         
         virtual void step();
         
         //  virtual void send(IMidiMessage ^ message);
         
         //         private:
         //    map<MidiMessageType, MidiMessageType, string> _messageTypeMap;
         //      MidiMessageType _messageType;
         //          array<MidiInPort^> _midiInPortArray;
         //        array<IMidiOutPort^> _midiOutPortArray;
         
         //            stringa m_straOut;
         //
         //            ref class MidiDeviceWatcher sealed
         //            {
         //            public:
         //               MidiDeviceWatcher(message_io ^ io, String ^ midiSelector);
         //               virtual ~MidiDeviceWatcher();
         //               void Start();
         //               void Stop();
         //               DeviceInformationCollection^ GetDeviceInformationCollection();
         //               void UpdatePorts();
         //
         //            private:
         //
         //               void OnPortAdded(DeviceWatcher^ deviceWatcher, DeviceInformation^ devInfo);
         //               void OnPortRemoved(DeviceWatcher^ deviceWatcher, DeviceInformationUpdate^ devInfoUpdate);
         //               void OnPortUpdated(DeviceWatcher^ deviceWatcher, DeviceInformationUpdate^ devInfoUpdate);
         //               void OnPortEnumCompleted(DeviceWatcher^ deviceWatcher, Object^ obj);
         //
         //               Windows::Foundation::EventRegistrationToken _portAddedToken;
         //               Windows::Foundation::EventRegistrationToken _portRemovedToken;
         //               Windows::Foundation::EventRegistrationToken _portUpdatedToken;
         //               Windows::Foundation::EventRegistrationToken _portEnumCompleteToken;
         //
         //               message_io ^ m_io;
         //               String ^ _midiSelectorString;
         //               DeviceWatcher ^ _deviceWatcher;
         //               DeviceInformationCollection^ _devInfoCollection;
         //               bool _enumCompleted;
         //            };
         //
         //            MidiDeviceWatcher ^ _midiInDeviceWatcher;
         //            MidiDeviceWatcher ^ _midiOutDeviceWatcher;
         
         virtual bool is_ok();
         
      };
      
   } // namespace midi
   
} // namespace music

