#pragma once


namespace music
{

   namespace midi_core_midi
   {


      class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_CORE_MIDI sequence_thread : 
         virtual public ::music::midi::sequence_thread
      {
      public:
         

         sequence_thread(::aura::application * papp);
         virtual ~sequence_thread();


         void install_message_routing(::message::sender * pinterface);
 
         void OnMidiSequenceEvent(::message::message * pobj);


      };


   } // namespace midi_core_midi


} // namespace music




