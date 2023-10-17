#include <raylib.h>
#include "game.hpp"

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
    double currentTime = GetTime();

    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    Color darkBlue = { 44, 44, 127, 255 };
    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose()) {
        game.handleInput();
        if (eventTriggered(0.2)) {
            game.moveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.draw();
        EndDrawing();
    }

    CloseWindow();
}
