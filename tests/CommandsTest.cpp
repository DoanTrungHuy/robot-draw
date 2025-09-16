#include "gtest/gtest.h"
#include "Commands.h"
#include "Grid.h"
#include "Robot.h"

TEST(DimensionCommandTest, ExecuteValid) {
    Grid grid(1);
    Robot robot(&grid);
    DimensionCommand cmd(3);

    EXPECT_NO_THROW(cmd.execute(grid, robot));
    EXPECT_EQ(grid.getSize(), 3);
}

TEST(DimensionCommandTest, ExecuteInvalid) {
    Grid grid(1);
    Robot robot(&grid);
    DimensionCommand cmd(0);

    EXPECT_THROW(cmd.execute(grid, robot), std::runtime_error);
}

TEST(MoveCommandTest, ExecuteInsideGrid) {
    Grid grid(5);
    Robot robot(&grid);
    MoveCommand cmd(3, 3);

    EXPECT_NO_THROW(cmd.execute(grid, robot));
}

TEST(MoveCommandTest, ExecuteOutsideGrid) {
    Grid grid(5);
    Robot robot(&grid);
    MoveCommand cmd(6, 6);

    EXPECT_THROW(cmd.execute(grid, robot), std::runtime_error);
}

TEST(LineCommandTest, ExecuteInsideGrid) {
    Grid grid(5);
    Robot robot(&grid);
    robot.moveTo(0, 0);
    LineCommand cmd(4, 4);

    EXPECT_NO_THROW(cmd.execute(grid, robot));
}

TEST(LineCommandTest, ExecuteOutsideGrid) {
    Grid grid(5);
    Robot robot(&grid);
    robot.moveTo(0, 0);
    LineCommand cmd(5, 5);

    EXPECT_THROW(cmd.execute(grid, robot), std::runtime_error);
}