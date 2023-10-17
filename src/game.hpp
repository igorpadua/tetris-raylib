#pragma once
#include "block.hpp"
#include "blocks.cpp"
#include "grid.hpp"
#include <random>

class Game
{
public:
    Game();
    Grid grid;
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    void draw();
    void handleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();

private:
    bool isBlockOutside();
    void rotateBlock();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};

