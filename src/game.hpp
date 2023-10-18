#pragma once
#include "block.hpp"
#include "blocks.cpp"
#include "grid.hpp"

class Game
{
public:
    Game();
    ~Game();
    void draw();
    void handleInput();
    void moveBlockDown();
    void lockBlock();

    bool getGameOver() const;
    int getScore() const;
    Music getMusic() const;

private:
    Grid grid;
    void moveBlockLeft();
    void moveBlockRight();
    Block getRandomBlock();
    std::vector<Block> getAllBlocks() const;
    bool isBlockOutside();
    void rotateBlock();
    bool blockfits();
    void reset();
    void updateScore(int linesCleared, int moveDownPoints);
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
    bool gameOver;
    int score;
    Music music;
};

