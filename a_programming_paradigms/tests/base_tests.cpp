#include <gtest/gtest.h>
#include "media_player.hpp"

TEST(BaseTest, InitialiseEmpty) {
  MediaPlayer media_player;
  EXPECT_EQ(media_player.get_on_state(), false);
  EXPECT_EQ(media_player.get_play_state(), Stopped);
}

TEST(BaseTest, PowerButtonPressed) {
  MediaPlayer media_player;
  media_player.power_button_pressed();
  EXPECT_EQ(media_player.get_on_state(), true);
  EXPECT_EQ(media_player.get_play_state(), Stopped);
}

TEST(BaseTest, PlayButtonPressed) {
  MediaPlayer media_player;
  media_player.play_pause_button_pressed(); // expect nothing to happen because mp3 player is not on
  EXPECT_EQ(media_player.get_on_state(), false);
  EXPECT_EQ(media_player.get_play_state(), Stopped);
}

TEST(BaseTest, PowerThenPlayButtonPressed) {
  MediaPlayer media_player;
  media_player.power_button_pressed();
  media_player.play_pause_button_pressed();
  EXPECT_EQ(media_player.get_on_state(), true);
  EXPECT_EQ(media_player.get_play_state(), Playing);
}

TEST(BaseTest, PowerThenPlayButtonTwicePressed) {
  MediaPlayer media_player;
  media_player.power_button_pressed();
  media_player.play_pause_button_pressed();
  media_player.play_pause_button_pressed();
  EXPECT_EQ(media_player.get_on_state(), true);
  EXPECT_EQ(media_player.get_play_state(), Paused);
}

TEST(BaseTest, PowerThenPlayThenStopButtonPressed) {
  MediaPlayer media_player;
  media_player.power_button_pressed();
  media_player.play_pause_button_pressed();
  media_player.stop_button_pressed();
  EXPECT_EQ(media_player.get_on_state(), true);
  EXPECT_EQ(media_player.get_play_state(), Stopped);
}