#include "game.hpp"

Game::Game()
{
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
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

    if (gameOver and keyPressed != 0) {
        gameOver = false;
        reset();
    }

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
    case KEY_UP:
        rotateBlock();
        break;
    }
}

void Game::moveBlockLeft()
{
    if (gameOver) {
        return;
    }
    currentBlock.move(0, -1);
    if (isBlockOutside() or !blockfits()) {
        currentBlock.move(0, 1);
    }
}

void Game::moveBlockRight()
{
    if (gameOver) {
        return;
    }
    currentBlock.move(0, 1);
    if (isBlockOutside() or !blockfits()) {
        currentBlock.move(0, -1);
    }
}

void Game::moveBlockDown()
{
    if (gameOver) {
        return;
    }
    currentBlock.move(1, 0);
    if (isBlockOutside() or !blockfits()) {
        currentBlock.move(-1, 0);
        lockBlock();
    }
}

void Game::lockBlock()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();

    for (Position item : tiles) {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if (!blockfits()) {
        gameOver = true;
    }
    nextBlock = getRandomBlock();
    grid.clearFullRows();
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (Position item : tiles) {
        if (grid.isCellOutside(item.row, item.column)) {
            return true;
        }
    }
    return false;
}

void Game::rotateBlock()
{
    if (gameOver) {
        return;
    }
    currentBlock.rotate();
    if (isBlockOutside()) {
        currentBlock.undoRotation();
    }
}

bool Game::blockfits()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (Position item : tiles) {
        if (!grid.isCellEmpty(item.row, item.column)) {
            return false;
        }
    }
    return true;
}

void Game::reset()
{
    grid.initialize();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}
