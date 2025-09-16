#include "gtest/gtest.h"
#include "Robot.h"
#include "Grid.h"

TEST(RobotTest, DiagonalLineToMarksGrid) {
    Grid grid(5);
    Robot robot(&grid);

    robot.moveTo(0, 0);

    robot.lineTo(3, 3);

    const auto& cells = grid.getCells();

    EXPECT_EQ(cells[0][0], '+');
    EXPECT_EQ(cells[1][1], '+');
    EXPECT_EQ(cells[2][2], '+');
    EXPECT_EQ(cells[3][3], '+');

    EXPECT_EQ(cells[0][1], '.');
    EXPECT_EQ(cells[1][0], '.');
}