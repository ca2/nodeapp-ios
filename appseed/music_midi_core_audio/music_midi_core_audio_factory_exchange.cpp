#include "framework.h"


namespace music
{


   namespace midi_core_midi
   {


      factory_exchange::factory_exchange(::aura::application * papp) :
      ::object(papp)
      {

         System.factory().cloneable_large < sequence               >  (System.type_info < ::music::midi::sequence                  > ());
         System.factory().cloneable_large < file              >  (System.type_info < ::music::midi::file::buffer                 > ());
         System.factory().cloneable_large < sequence_thread              >  (System.type_info < ::music::midi::sequence_thread                 > ());
         System.factory().cloneable_large < ::music::midi_core_midi::player::player              >  (System.type_info < ::music::midi::player::player                 > ());
         System.factory().cloneable_large < ::music::midi_core_midi::midi              >  (System.type_info < ::music::midi::midi               > ());
         System.factory().cloneable_large < ::music::midi_core_midi::message_out              >  (System.type_info < ::music::midi::message_out               > ());

      }


      factory_exchange::~factory_exchange()
      {
      }


   } // namespace midi_core_midi


} // namespace music


extern "C"
void music_midi_core_audio_ca2_factory_exchange(::aura::application * papp)
{

   ::music::midi_core_midi::factory_exchange factoryexchange(papp);

}









