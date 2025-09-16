#pragma once
#include "Grid.h"
#include "Robot.h"

class ICommand {
public:
    virtual void execute(Grid& grid, Robot& robot) = 0;
    virtual ~ICommand() = default;
};