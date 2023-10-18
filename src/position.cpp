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

int Position::getColumn() const
{
    return column;
}
