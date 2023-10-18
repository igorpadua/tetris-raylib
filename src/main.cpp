#include <raylib.h>
#include "game.hpp"
#include "colors.hpp"

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
    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while (!WindowShouldClose()) {
        game.handleInput();
        if (eventTriggered(0.2)) {
            game.moveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);

        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        if (game.gameOver) {
            DrawTextEx(font, "GAMER OVER", {320, 450}, 32, 2, WHITE);
        }

        game.draw();
        EndDrawing();
    }

    CloseWindow();
}
