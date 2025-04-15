#pragma once
#include <string>
#include "vec2.hpp"
enum DirectionEnum
{
    FORWARD,
    BACKWARD,
    RIGHT,
    LEFT
};

class Direction
{
    public:
        DirectionEnum direction;
        Direction(DirectionEnum dir) : direction(dir) {};
        Vec2 get_displacement(double distance);
        std::string to_string();
};
