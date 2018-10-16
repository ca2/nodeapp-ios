#pragma once


#define  VERSION_MINOR              0x00
#define  VERSION_MAJOR              0x04
#define  SEQ_VERSION                ((uint32_t)(WORD)((BYTE)VERSION_MINOR | (((WORD)(BYTE)VERSION_MAJOR) << 8)))

#define MMSG_DONE                   (WM_USER+20)


namespace music
{

   
   namespace midi_core_midi
   {
      

      class file;
      class sequence;
      class sequence_thread;


      class CLASS_DECL_VERIWELL_MULTIMEDIA midi_callback_data
      {
      public:


         sequence *          m_psequence;


      };


      class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_CORE_MIDI sequence :
         virtual public ::music::midi::sequence
      {
      public:

         
         sequence(::aura::application * papp);
         virtual ~sequence();
         ::music::midi::message_out * get_message_out();
         

      };



   } // namespace midi_core_midi


} // namespace music







