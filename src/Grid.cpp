#include "Grid.h"
#include <vector>

using namespace std;

Grid::Grid(int n) : size(n), cells(n, vector<char>(n, '.')) {}

void Grid::resize(int n) {
    size = n;
    cells.assign(n, vector<char>(n, '.'));
}

int Grid::getSize() const { return size; }

bool Grid::isInside(int x, int y) const {
    return 0 <= x && x < size && 0 <= y && y < size;
}

void Grid::mark(int x, int y) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        cells[y][x] = '+';
    }
}

void Grid::print() const {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            cout << cells[y][x];
            if (x < size - 1) cout << " ";
        }
        cout << "\n";
    }
}

const vector<vector<char>>& Grid::getCells() const {
    return cells;
}