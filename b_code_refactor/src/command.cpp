#include "command.hpp"
#include <iostream>
#include <vector>
#include <memory>

void MoveToCommand::execute()
{
    std::vector<std::unique_ptr<ICommand>> commands;
    Vec2 last_odom = robot.get_odometry();
    Vec2 delta = this->destination - last_odom;
    if (delta.x != 0.0)
    {
        Vec2 temp_position(destination.x, last_odom.y);
        double distance = robot.calculate_distance(temp_position);
        Direction* direction;
        if (delta.x > 0)
        {
            direction = new Direction(FORWARD);
        }
        else
        {
            direction = new Direction(BACKWARD);
        }
        std::unique_ptr<MoveCommand> move_x(new MoveCommand(this->robot, distance, *direction, this->speed));
        commands.push_back(std::move(move_x));
    }
    if (delta.y != 0.0)
    {
        Vec2 temp_position(last_odom.x, destination.y);
        double distance = robot.calculate_distance(temp_position);
        Direction* direction;
        if (delta.y > 0)
        {
            direction = new Direction(RIGHT);
        }
        else
        {
            direction = new Direction(LEFT);
        }
        std::unique_ptr<MoveCommand> move_y (new MoveCommand(this->robot, distance, *direction, this->speed));
        commands.push_back(std::move(move_y));
    }
    for (auto& command : commands) command.get()->execute();
}

void MoveCommand::execute()
{
    robot.check_battery_cost(distance, speed); // charge battery and/or modify speed if necessary
    std::cout << "Moving " << this->direction.to_string() << " " << distance << " meters with speed " << speed << std::endl;
    robot.update_battery_level(distance, speed);
    Vec2 last_odom = robot.get_odometry();
    Vec2 displacement = this->direction.get_displacement(distance);
    Vec2 new_position = last_odom + displacement;
    robot.update_odometry(new_position.x, new_position.y);
    // change motor state
}