#pragma once
#include "vec2.hpp"
class Robot
{
    double battery;
    bool is_charging;
    bool motor_state;
    Vec2 last_odom;

    double calculate_battery_cost(double distance, double speed);

    public:
        Robot();
        void check_battery_cost(double distance, double& speed);
        Vec2 get_odometry();
        void update_odometry(double x, double y);
        double calculate_distance(Vec2 target);
        void check_battery();
        void update_battery_level(double distance, double speed);
        void set_battery_level(double battery_level);
        void charge_battery();
        void print_info();
};