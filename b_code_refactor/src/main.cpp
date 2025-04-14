#include <array>
#include "robot.hpp"
#include "vec2.hpp"

int main()
{
    std::array<std::array<double, 2>, 5> positions {{
        {{20, 0}},
        {{20, 20}},
        {{-20, 20}},
        {{-20, -20}},
        {{20, -20}}
    }};
    Robot robot;
    for (auto position : positions)
    {
        Vec2 vecposition(position[0], position[1]);
        robot.move_to(vecposition, 1.0);
    }
    return 0;
}
