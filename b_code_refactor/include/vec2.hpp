#pragma once
#include <sstream>
struct Vec2 {
    double x, y;

    Vec2() : x(0.0), y(0.0) {}
    Vec2(double x_in, double y_in) : x(x_in), y(y_in) {}

    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator-() const {
        return Vec2(-x, -y);
    }

    std::string to_string()
    {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }

};