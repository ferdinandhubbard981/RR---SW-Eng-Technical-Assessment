#include <iostream>
#include <string>
#include "media_player.cpp"
int main()
{
    MediaPlayer* media_player = new MediaPlayer();
    media_player->power_button_pressed();
    std::cout << (*media_player).to_string() << std::endl;
}
