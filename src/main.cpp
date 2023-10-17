#include <raylib.h>
#include "game.hpp"

int main()
{
    Color darkBlue = { 44, 44, 127, 255 };
    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose()) {
        game.handleInput();
        BeginDrawing();
//        game.moveBlockDown();
        ClearBackground(darkBlue);
        game.draw();
        EndDrawing();
    }

    CloseWindow();
}
