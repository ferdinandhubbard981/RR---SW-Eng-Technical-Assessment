#pragma once
#include "robot.hpp"
#include "vec2.hpp"
#include "util.hpp"

class ICommand
{
    public:
        virtual void execute() = 0;
        virtual ~ICommand() = default;
};

class MoveToCommand : public ICommand
{
    Robot& robot;
    Vec2 destination;
    double speed;
    public:
        MoveToCommand(Robot& r, Vec2 dest, double sp) : robot(r), destination(dest), speed(sp) {};
        void execute() override;
};

class MoveCommand : public ICommand
{
    Robot& robot;
    double distance;
    Direction direction;
    double speed;
    public:
        MoveCommand(Robot& r, double dist, Direction dir, double sp) : robot(r), distance(dist), direction(dir), speed(sp) {};
        void execute() override;
};