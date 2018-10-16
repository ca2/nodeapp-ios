#pragma once


#include "music_midi_core_audio_player_callback.h"
#include "music_midi_core_audio_player_interface.h"





namespace music
{


   namespace midi_core_midi
   {


      class sequence_thread;


      namespace player
      {

         class player_callback;
         class player_interface;




         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_CORE_MIDI player :
            virtual public ::music::midi::player::player
         {
         public:


            player(::aura::application * papp);
            virtual ~player();



         };


      } // namespace player


   } // namespace midi_core_midi


} // namespace music






