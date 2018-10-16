#include "framework.h"


namespace music
{
   
   
   namespace midi_core_midi
   {
      
      
      sequence_thread::sequence_thread(::aura::application * papp) :
      ::object(papp),
      thread(papp),
      ::music::midi::sequence_thread(papp)
      {
      }
      
      sequence_thread::~sequence_thread()
      {
      }
      
      
      void sequence_thread::install_message_routing(::message::sender * psender)
      {
         
         ::music::midi::sequence_thread::install_message_routing(psender);
         //IGUI_MSG_LINK(::music::midi::player::message_command, pinterface, this, &sequence_thread::OnCommand);
         IGUI_MSG_LINK(::music::midi::sequence::message_event, psender, this, &sequence_thread::OnMidiSequenceEvent);
         //IGUI_MSG_LINK(::music::midi_core_midi::sequence::message_run, pinterface, this, &sequence_thread::OnRun);
      }
      
      
      void sequence_thread::OnMidiSequenceEvent(::message::message * pobj)
      {
         
         SCAST_PTR(::message::base, pbase, pobj);
         
         sp(::music::midi::sequence::event) pevent(pbase->m_lparam);
         
         sp(::music::midi_core_midi::sequence) pseq = pevent->m_psequence;
         
         pseq->OnEvent(pevent);
         
         switch(pevent->m_eevent)
         {
            case ::music::midi::sequence::EventMidiPlaybackEnd:
            {
               ::music::midi::sequence::PlayerLink & link = get_sequence()->GetPlayerLink();
               if(link() & ::music::midi::sequence::FlagTempoChange)
               {
                  PrerollAndWait(link.m_tkRestart);
                  get_sequence()->SetTempoChangeFlag(false);
                  get_sequence()->Start();
                  link() -= ::music::midi::sequence::FlagTempoChange;
               }
               else if(link() & ::music::midi::sequence::FlagSettingPos)
               {
                  link() -= ::music::midi::sequence::FlagSettingPos;
                  try
                  {
                     PrerollAndWait(link.m_tkRestart);
                  }
                  catch(exception *pe)
                  {
                     //               SendMmsgDone(pseq, NULL);
                     pe->Delete();
                     return;
                  }
                  get_sequence()->Start();
                  //PostNotifyEvent(::music::midi::player::notify_event_position_set);
               }
               else if(link() & ::music::midi::sequence::FlagMidiOutDeviceChange)
               {
                  link() -= ::music::midi::sequence::FlagMidiOutDeviceChange;
                  try
                  {
                     PrerollAndWait(link.m_tkRestart);
                  }
                  catch(exception *pe)
                  {
                     //               SendMmsgDone(pseq, NULL);
                     pe->Delete();
                     return;
                  }
                  get_sequence()->Start();
                  /*CNotifyEventData data;
                   data.m_pplayer = this;
                   data.m_enotifyevent = player::notify_event_position_set;
                   SendMessage(
                   m_oswindow_,
                   MIDIPLAYERMESSAGE_NOTIFYEVENT,
                   (WPARAM) &data,
                   0);      */
                  
               }
               else if(link() & ::music::midi::sequence::FlagStopAndRestart)
               {
                  link() -= ::music::midi::sequence::FlagStopAndRestart;
                  try
                  {
                     PrerollAndWait(link.m_tkRestart);
                  }
                  catch(exception *pe)
                  {
                     //               SendMmsgDone(pseq, NULL);
                     pe->Delete();
                     return;
                  }
                  get_sequence()->Start();
                  //PostNotifyEvent(player::notify_event_position_set);
               }
               else
               {
                  
                  //                  if(link.TestFlag(::music::midi::sequence::FlagStop))
                  {
                     link() -= ::music::midi::sequence::FlagStop;
                     link.OnFinishCommand(::music::midi::player::command_stop);
                     //PostNotifyEvent(::music::midi::player::notify_event_playback_end);
                     
                  }
                  
               }
               
            }
               break;
            case ::music::midi::sequence::EventSpecialModeV001End:
            {
               //PostNotifyEvent(::music::midi::player::notify_event_generic_mmsg_done);
            }
               break;
            case ::music::midi::sequence::EventMidiPlaybackStart:
            {
               
               //pseq->seq_start();
               
               pseq->m_psequencer = pseq->create_sequencer();
               
               pseq->m_psequencer->begin();
               
               //post_message(::music::midi::sequence::message_run);
               
               //PostNotifyEvent(::music::midi::player::notify_event_playback_start);
               
            }
               break;
            case ::music::midi::sequence::EventMidiStreamOut:
            {
               //PostNotifyEvent(::music::midi::player::notify_event_midi_stream_out);
            }
               break;
               
         }
         
         
      }
      

      
      
   } // namespace midi_core_midi
   
   
} // namespace music









