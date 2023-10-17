#pragma once


class Position
{
public:
    Position(int row, int column);

    int getRow() const;
    void setRow(int newRow);
    int getColumn() const;
    void setColumn(int newColumn);

private:
    int row;
    int column;
};

