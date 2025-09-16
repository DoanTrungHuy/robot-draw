#include "Commands.h"

using namespace std;

DimensionCommand::DimensionCommand(int n_) : n(n_) {}

void DimensionCommand::execute(Grid& grid, Robot& robot) {
    if (n <= 0) throw runtime_error("Invalid dimension");
    grid.resize(n);
    robot.setGrid(&grid);
    robot.moveTo(0, 0);
}

MoveCommand::MoveCommand(int x_, int y_) : x(x_), y(y_) {}

void MoveCommand::execute(Grid& grid, Robot& robot) {
    if (!grid.isInside(x, y)) throw runtime_error("MoveCommand: outside grid");
    robot.moveTo(x, y);
}

LineCommand::LineCommand(int x_, int y_) : x(x_), y(y_) {}

void LineCommand::execute(Grid& grid, Robot& robot) {
    if (!grid.isInside(x, y)) throw runtime_error("LineCommand: outside grid");
    robot.lineTo(x, y);
}
