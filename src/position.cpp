#include "position.hpp"

Position::Position(int row, int column)
    : row(row)
    , column(column)
{
}

int Position::getRow() const
{
    return row;
}

void Position::setRow(int newRow)
{
    row = newRow;
}

int Position::getColumn() const
{
    return column;
}

void Position::setColumn(int newColumn)
{
    column = newColumn;
}
