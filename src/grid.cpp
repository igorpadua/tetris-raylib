#include "grid.hpp"
#include <iostream>
#include "colors.hpp"

Grid::Grid()
    : numRows(20)
    , numCols(10)
    , cellSize(30)
    , colors(getCellColors())
{
    initialize();
}

void Grid::initialize()
{
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            grid[row][column] = 0;
        }
    }
}

void Grid::print() const
{
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::draw() const
{
    for (int row = 0; row < numRows; ++row) {
        for (int column = 0; column < numCols; ++column) {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column) const
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols) {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int column) const
{
    if (grid[row][column] == 0) {
        return true;
    }
    return false;
}

int Grid::clearFullRows()
{
    auto completed = 0;

    for (int row = numRows - 1; row >= 0; --row) {
        if (isRowFull(row)) {
            clearRow(row);
            ++completed;
        } else if (completed > 0) {
            moveRowDown(row, completed);
        }
    }

    return completed;
}

bool Grid::isRowFull(int row) const
{
    for (int column = 0; column < numCols; ++column) {
        if (grid[row][column] == 0) {
            return false;
        }
    }

    return true;
}

void Grid::clearRow(int row)
{
    for (int column = 0; column < numCols; ++column) {
        grid[row][column] = 0;
    }
}

void Grid::moveRowDown(int row, int numRows)
{
    for (int column = 0; column < numCols; ++column) {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
