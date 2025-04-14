#pragma once
class Robot
{
    int battery;
    bool is_charging;
    bool motor_state;
    double last_odom_x, last_odom_y;

    public:
        Robot();
        void move_robot_forward(double distance, double speed);
        void move_robot_backward(double distance, double speed);
        void move_robot_right(double distance, double speed);
        void move_robot_left(double distance, double speed);
        double* get_odometry(double distance, double speed);
        void update_odometry(double x, double y);
        double calculate_distance(double target_x, double target_y);
        void check_battery();
        void update_battery_level(double distance, double speed);
        void set_battery_level(int battery_level);
        void charge_battery();
};