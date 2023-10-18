#pragma once

class Position
{
public:
    Position(int row, int column);

    int getRow() const;
    int getColumn() const;

private:
    int row;
    int column;
};

