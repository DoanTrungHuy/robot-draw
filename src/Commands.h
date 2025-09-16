#pragma once
#include "ICommand.h"
#include <memory>
#include <stdexcept>

class DimensionCommand : public ICommand {
private:
    int n;
public:
    DimensionCommand(int n_);
    void execute(Grid& grid, Robot& robot) override;
};

class MoveCommand : public ICommand {
private:
    int x, y;
public:
    MoveCommand(int x_, int y_);
    void execute(Grid& grid, Robot& robot) override;
};

class LineCommand : public ICommand {
private:
    int x, y;
public:
    LineCommand(int x_, int y_);
    void execute(Grid& grid, Robot& robot) override;
};