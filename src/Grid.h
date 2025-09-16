#pragma once
#include <vector>
#include <iostream>

class Grid {
private:
    int size;
    std::vector<std::vector<char>> cells;

public:
    Grid(int n = 0);

    void resize(int n);
    int getSize() const;
    bool isInside(int x, int y) const;
    void mark(int x, int y);
    void print() const;
    const std::vector<std::vector<char>>& getCells() const;
};