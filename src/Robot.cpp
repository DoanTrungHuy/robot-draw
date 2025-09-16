#include "Robot.h"
#include <cmath>

using namespace std;

Robot::Robot(Grid* g) : x(0), y(0), grid(g) {}

void Robot::setGrid(Grid* g) { grid = g; }

void Robot::moveTo(int nx, int ny) {
    x = nx;
    y = ny;
}

void Robot::lineTo(int nx, int ny) {
    if (!grid) throw runtime_error("Grid not set");

    int dx = abs(nx - x), dy = abs(ny - y);
    int sx = (x < nx) ? 1 : -1, sy = (y < ny) ? 1 : -1;
    int err = dx - dy;
    int cx = x, cy = y;

    while (true) {
        grid->mark(cx, cy);
        if (cx == nx && cy == ny) break;

        int e2 = err << 1;
        if (e2 > -dy) { err -= dy; cx += sx; }
        if (e2 < dx) { err += dx; cy += sy; }
    }

    x = nx;
    y = ny;
}