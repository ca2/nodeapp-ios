#include "framework.h"





namespace music
{
   
   
   namespace midi_core_midi
   {
      
      
      sequence::sequence(::aura::application * papp) :
      ::object(papp),
      ::music::midi::object(papp),
      ::ikaraoke::karaoke(papp),
      ::music::midi::sequence(papp)
      {
         

         
      }
      
      
      sequence::~sequence()
      {
         
         
      }
      
      ::music::midi::message_out * sequence::get_message_out()
      {
         
         Application.midi().cast < midi >()->m_pmessageout->m_ps = m_psequencer;
         
         return Application.midi().cast < midi >()->m_pmessageout;
         
      }
      

   } // namespace midi_core_midi
   
   
} // namespace music



