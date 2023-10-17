#include "block.hpp"

Block::Block()
    : cellSize(30)
    , rotationState(0)
    , colors(getCellColors())
{

}

void Block::draw()
{
    std::vector<Position> tiles = cells[rotationState];

    for (Position item : tiles) {
        DrawRectangle(item.getColumn() + cellSize + 1, item.getRow() * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}
