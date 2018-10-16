#include "framework.h"


namespace music
{
   
   
   namespace midi_core_midi
   {
      
      
      namespace player
      {
         
         
         player::player(::aura::application * papp) :
         ::object(papp),
         thread(papp),
         ::music::midi::player::player(papp)
         {
            
            
         }
         
         player::~player()
         {
            
         }
         
         
         
      } // namespace player
      
      
   } // namespace midi_core_midi
   
   
} // namespace music









