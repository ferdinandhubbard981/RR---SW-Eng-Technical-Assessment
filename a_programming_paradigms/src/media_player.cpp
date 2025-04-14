#include <sstream>
#include "enum_macro.cpp"

DEFINE_ENUM_WITH_STRING_CONVERSIONS(PlayStateEnum, (Playing)(Paused)(Stopped))
class MediaPlayer
{
    bool on_state;
    PlayStateEnum play_state;

    public: 
        MediaPlayer()
        {
            on_state = false;
            play_state = Stopped;
        }

        void power_button_pressed()
        {
            if (on_state)
            {
                play_state = Stopped;
                on_state = false;
                return;
            }
            on_state = true;
        }

        void play_pause_button_pressed()
        {
            if (!on_state) return;
            if (play_state == Stopped || play_state == Paused)
            {
                play_state = Playing;
                return;
            }
            play_state = Paused;
        }

        void stop_button_pressed()
        {
            play_state = Stopped;
        }

        std::string to_string()
        {
            std::stringstream ss;
            ss << "\nMedia Player\non_state: " << on_state << "\nplay_state: " << ToString(play_state);
            return ss.str();
        }

        bool get_on_state()
        {
            return on_state;
        }

        PlayStateEnum get_play_state()
        {
            return play_state;
        }

};