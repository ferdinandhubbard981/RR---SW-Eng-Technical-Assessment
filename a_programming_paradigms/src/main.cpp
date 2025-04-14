#include <iostream>
#include <string>
#include "media_player.cpp"

void print_instructions() {
    std::cout << "Controls:\n"
              << "1 - Power Button\n"
              << "2 - Play/Pause Button\n"
              << "3 - Stop Button\n"
              << "h - Help (show controls)\n"
              << "q - Quit\n" << std::endl;
}

int main()
{
    print_instructions();

    MediaPlayer media_player;
    char ch;
    while (std::cin >> ch)
    {
        if (ch == 'q') break;
        if (ch == 'h') {
            print_instructions();
            continue;
        }
        if (ch == '1') media_player.power_button_pressed();
        if (ch == '2') media_player.play_pause_button_pressed();
        if (ch == '3') media_player.stop_button_pressed();
        std::cout << media_player.to_string() << std::endl;
    }
    return 0;
}
