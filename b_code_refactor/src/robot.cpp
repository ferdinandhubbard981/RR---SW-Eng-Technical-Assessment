#include <iostream>
#include "robot.hpp"
#include "vec2.hpp"

Robot::Robot()
{
    this->battery = 100.0;
    this->is_charging = false;
    this->motor_state = false;
    this->last_odom = Vec2();
}

void Robot::check_battery_cost(double distance, double &speed) 
{
    double battery_cost = this->calculate_battery_cost(distance, speed);
    if (battery_cost > 100.0) {
        speed = 99.0 / distance; // max speed to travel this distance with 1% left on the battery
    }
    if (battery_cost > this->battery) this->charge_battery();
}

Vec2 Robot::get_odometry()
{
    return this->last_odom;
}

void Robot::update_odometry(double x, double y)
{
    this->last_odom.x = x;
    this->last_odom.y = y;
    std::cout << "Odometry updated to (" << x << ", " << y << ")" << std::endl;
}

double Robot::calculate_distance(Vec2 target)
{
    // This is not correct, we need to abs() the x and y components respectively before adding them together
    double result = this->last_odom.x + this->last_odom.y - (target.x + target.y);
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

void Robot::set_battery_level(double battery_level)
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

double Robot::calculate_battery_cost(double distance, double speed)
{
    return distance*speed;
}

void Robot::charge_battery()
{
    this->is_charging = true;
    this->battery = 100;
    std::cout << "Charging..." << std::endl;
}

void Robot::print_info()
{
    std::cout << "\nBattery level: " << this->battery << "\nposition: " << this->last_odom.to_string() << std::endl << std::endl;
}