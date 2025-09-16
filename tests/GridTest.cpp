#include "gtest/gtest.h"
#include "Grid.h"

TEST(GridTest, ResizeAndIsInside) {
    Grid grid(5);
    EXPECT_EQ(grid.getSize(), 5);
    EXPECT_TRUE(grid.isInside(0, 0));
    EXPECT_TRUE(grid.isInside(4, 4));
    EXPECT_FALSE(grid.isInside(5, 5));

    grid.resize(3);
    EXPECT_EQ(grid.getSize(), 3);
    EXPECT_FALSE(grid.isInside(3, 3));
}

TEST(GridTest, MarkAndPrint) {
    Grid grid(3);
    grid.mark(1, 1);
    EXPECT_NO_THROW(grid.print());
}