#include <media_player.hpp>
#include <sstream>

MediaPlayer::MediaPlayer()
{
    on_state = false;
    play_state = Stopped;
}

void MediaPlayer::power_button_pressed()
{
    if (on_state)
    {
        on_state = false;
        return;
    }
    on_state = true;
}

void MediaPlayer::play_pause_button_pressed()
{
    if (!on_state) return;
    if (play_state == Stopped || play_state == Paused)
    {
        play_state = Playing;
        return;
    }
    play_state = Paused;
}

void MediaPlayer::stop_button_pressed()
{
    play_state = Stopped;
}

std::string MediaPlayer::to_string()
{
    std::stringstream ss;
    ss << "\nMedia Player\non_state: " << on_state << "\nplay_state: " << ToString(play_state);
    return ss.str();
}

bool MediaPlayer::get_on_state()
{
    return on_state;
}

PlayStateEnum MediaPlayer::get_play_state()
{
    return play_state;
}
