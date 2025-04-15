#include <array>
#include <vector>
#include <memory>
#include "robot.hpp"
#include "vec2.hpp"
#include "command.hpp"

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
    std::vector<std::unique_ptr<ICommand>> commands;
    for (auto position : positions)
    {
        Vec2 vec_position(position[0], position[1]);
        std::unique_ptr<ICommand> command(new MoveToCommand(robot, vec_position, 1.0));
        commands.push_back(std::move(command));
    }
    for (auto& command : commands) command.get()->execute();
    return 0;
}
