#include "game.hpp"

Game::Game()
    : grid(Grid())
    , blocks(getAllBlocks())
    , currentBlock(getRandomBlock())
    , nextBlock(getRandomBlock())
{

}

Block Game::getRandomBlock()
{

    if (blocks.empty()) {
        blocks = getAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::getAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::draw()
{
    grid.draw();
    currentBlock.draw();
}

void Game::handleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed) {
    case KEY_LEFT:
        moveBlockLeft();
        break;
    case KEY_RIGHT:
        moveBlockRight();
        break;
    case KEY_DOWN:
        moveBlockDown();
        break;
    }
}

void Game::moveBlockLeft()
{
    currentBlock.move(0, -1);
}

void Game::moveBlockRight()
{
    currentBlock.move(0, 1);
}

void Game::moveBlockDown()
{
    currentBlock.move(1, 0);
}
