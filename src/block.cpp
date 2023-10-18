#include "block.hpp"
#include "colors.hpp"

Block::Block()
    : cellSize(30)
    , rotationState(0)
    , colors(getCellColors())
    , rowOffset(0)
    , columnOffset(0)
{
}

void Block::draw(int offsetX, int offsetY)
{
    auto tiles = getCellPositions();
    for (Position item : tiles)
    {
        DrawRectangle(item.getColumn() * cellSize + offsetX, item.getRow() * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<Position> Block::getCellPositions()
{
    auto tiles = cells[rotationState];
    auto movedTiles = std::vector<Position>();
    for (Position item : tiles)
    {
        Position newPos = Position(item.getRow() + rowOffset, item.getColumn() + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::rotate()
{
    rotationState++;
    if (rotationState == (int)cells.size()) {
        rotationState = 0;
    }
}

void Block::undoRotation()
{
    rotationState--;
    if (rotationState == -1) {
        rotationState = cells.size() - 1;
    }
}

void Block::setId(int newId)
{
    id = newId;
}

int Block::getId() const
{
    return id;
}
