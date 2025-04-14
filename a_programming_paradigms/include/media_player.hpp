#pragma once
#include <string>
#include "enum_macro.hpp"

DEFINE_ENUM_WITH_STRING_CONVERSIONS(PlayStateEnum, (Playing)(Paused)(Stopped))

class MediaPlayer
{
    bool on_state;
    PlayStateEnum play_state;

public: 
    MediaPlayer();

    void power_button_pressed();
    void play_pause_button_pressed();
    void stop_button_pressed();
    std::string to_string();
    bool get_on_state();
    PlayStateEnum get_play_state();
};
