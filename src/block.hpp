#pragma once

#include <vector>
#include <map>

#include "position.hpp"
#include "colors.hpp"

class Block
{
public:
    Block();
    int id;
    std::map<int, std::vector<Position>> cells;
    void draw();

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
};

