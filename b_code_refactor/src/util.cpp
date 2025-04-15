#include <exception>
#include "util.hpp"
#include "vec2.hpp"

Vec2 Direction::get_displacement(double distance)
{
    Vec2 out;
    switch (this->direction)
    {
    // I would've thought that forward would increment y and not x. However this is the logic that was implemented, so I won't change it (at least now without speaking to the person who wrote the code)
        case FORWARD:
            out.x += distance;
            break;

        case BACKWARD:
            out.x -= distance;
            break;

        case RIGHT:
            out.y += distance;
            break;

        case LEFT:
            out.y -= distance;
            break;
        
        default:
            throw std::runtime_error("expected a direction, instead got: " + this->direction);
    }
    return out;
}

std::string Direction::to_string()
{
    switch (this->direction)
    {
    case FORWARD:
        return "forward";
        break;

    case BACKWARD:
        return "backward";
        break;
    
    case RIGHT:
        return "right";
        break;

    case LEFT:
        return "left";
        break;
        
    default:
        throw std::runtime_error("expected a direction, instead got: " + this->direction);
    }
}