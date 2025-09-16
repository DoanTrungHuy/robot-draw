#pragma once
#include "Grid.h"
#include <stdexcept>

class Robot {
private:
    int x, y;
    Grid* grid;

public:
    Robot(Grid* g = nullptr);

    void setGrid(Grid* g);
    void moveTo(int nx, int ny);
    void lineTo(int nx, int ny);
};