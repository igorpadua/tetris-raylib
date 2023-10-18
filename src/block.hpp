#pragma once

#include <vector>
#include <map>
#include <raylib.h>

#include "position.hpp"

class Block
{
public:
    Block();
    std::map<int, std::vector<Position>> cells;
    void draw(int offsetX, int offsetY);
    void move(int rows, int  columns);
    std::vector<Position> getCellPositions();
    void rotate();
    void undoRotation();

    void setId(int newId);
    int getId() const;

private:
    int id;
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};

