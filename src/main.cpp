#include "grid.hpp"
#include <raylib.h>
#include "blocks.cpp"

int main()
{
    Color darkBlue = { 44, 44, 127, 255 };
    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.print();

    LBlock block = LBlock();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.draw();
        block.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
