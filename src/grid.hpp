#pragma once
#include <vector>
#include <raylib.h>
#include "colors.hpp"

class Grid {

public:
    Grid();
    void initialize();
    void print();
    void draw();
    bool isCellOutside(int row, int column);
    int grid[20][10];

private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};
