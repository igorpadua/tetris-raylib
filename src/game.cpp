#include "game.hpp"
#include <cstdlib>

Game::Game()
    : grid(Grid())
    , blocks(getAllBlocks())
    , currentBlock(getRandomBlock())
    , nextBlock(getRandomBlock())
    , gameOver(false)
    , score(0)
{
    InitAudioDevice();
    music = LoadMusicStream("sounds/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("sounds/rotate.mp3");
    clearSound = LoadSound("sounds/clear.mp3");
}

Game::~Game()
{
    UnloadMusicStream(music);
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    CloseAudioDevice();
}

Block Game::getRandomBlock()
{

    if (blocks.empty()) {
        blocks = getAllBlocks();
    }

    auto randomIndex = rand() % blocks.size();
    auto block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::getAllBlocks() const
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::draw()
{
    grid.draw();
    currentBlock.draw(11, 11);

    switch (nextBlock.getId()) {
    case 3:
        nextBlock.draw(255, 290);
        break;
    case 4:
        nextBlock.draw(255, 280);
    default:
        nextBlock.draw(270, 270);
        break;
    }
}

void Game::handleInput()
{
    auto keyPressed = GetKeyPressed();

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
        updateScore(0, 1);
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
    auto tiles = currentBlock.getCellPositions();

    for (Position item : tiles) {
        grid.grid[item.getRow()][item.getColumn()] = currentBlock.getId();
    }
    currentBlock = nextBlock;
    if (!blockfits()) {
        gameOver = true;
    }
    nextBlock = getRandomBlock();
    int rowsCleared = grid.clearFullRows();
    if (rowsCleared > 0) {
        PlaySound(clearSound);
        updateScore(rowsCleared, 0);
    }
}

bool Game::isBlockOutside()
{
    auto tiles = currentBlock.getCellPositions();
    for (Position item : tiles) {
        if (grid.isCellOutside(item.getRow(), item.getColumn())) {
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
    } else {
        PlaySound(rotateSound);
    }
}

bool Game::blockfits()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (Position item : tiles) {
        if (!grid.isCellEmpty(item.getRow(), item.getColumn())) {
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
    score = 0;
}

void Game::updateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared) {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownPoints;
}

bool Game::getGameOver() const
{
    return gameOver;
}

int Game::getScore() const
{
    return score;
}

Music Game::getMusic() const
{
    return music;
}
