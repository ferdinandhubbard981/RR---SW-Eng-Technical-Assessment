#include <iostream>
#include "robot.hpp"

Robot::Robot()
{
    this->battery = 100;
    this->is_charging = false;
    this->motor_state = false;
    this->last_odom_x = 0.0;
    this->last_odom_y = 0.0;
}

void Robot::move_robot_forward(double distance, double speed)
{
    this->motor_state = true;
    this->update_battery_level(distance, speed);
    this->update_odometry(this->last_odom_x + distance, this->last_odom_y);
    std::cout << "Moving forward " << distance << " meters with speed " << speed << std::endl;
    // TODO reset motor_state
}

void Robot::move_robot_backward(double distance, double speed)
{
    this->motor_state = true;
    this->update_battery_level(distance, speed);
    this->update_odometry(this->last_odom_x - distance, this->last_odom_y);
    std::cout << "Moving backward " << distance << " meters with speed " << speed << std::endl;
    // TODO reset motor_state
}

void Robot::move_robot_right(double distance, double speed)
{
    this->motor_state = true;
    this->update_battery_level(distance, speed);
    this->update_odometry(this->last_odom_x, this->last_odom_y + distance);
    std::cout << "Moving right " << distance << " meters with speed " << speed << std::endl;
    // TODO reset motor_state
}

void Robot::move_robot_left(double distance, double speed)
{
    this->motor_state = true;
    this->update_battery_level(distance, speed);
    this->update_odometry(this->last_odom_x, this->last_odom_y - distance);
    std::cout << "Moving left " << distance << " meters with speed " << speed << std::endl;
    // TODO reset motor_state
}

double* Robot::get_odometry(double distance, double speed)
{
    double* pos = new double[2];
    pos[0] = this->last_odom_x;
    pos[1] = this->last_odom_y;
    return pos;
}

void Robot::update_odometry(double x, double y)
{
    this->last_odom_x = x;
    this->last_odom_y = y;
    std::cout << "Odometry updated to (" << x << ", " << y << ")" << std::endl;
}

double Robot::calculate_distance(double target_x, double target_y)
{
    // This is not correct, we need to abs() the x and y components respectively before adding them together
    double result = this->last_odom_x + this->last_odom_y - (target_x + target_y);
    return (result > 0) ? result : -result;
}

void Robot::check_battery()
{
    if (battery < 20) {
        std::cout << "Warning: Battery Low!" << std::endl;
    }
    if (battery == 0) {
        std::cout << "Error: Battery Empty!" << std::endl;
    }
}

void Robot::set_battery_level(int battery_level)
{
    this->battery = battery_level;
    std::cout << "Battery set to: " << this->battery << std::endl;
}

void Robot::update_battery_level(double distance, double speed)
{
    // TODO check battery level is sufficient
    this->battery -= distance * speed;
    std::cout << "Battery level updated to: " << battery << std::endl;
}

void Robot::charge_battery()
{
    this->is_charging = true;
    this->battery++;
    std::cout << "Charging..." << std::endl;
}