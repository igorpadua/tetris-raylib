#include "grid.hpp"
#include <raylib.h>

int main()
{
    Color darkBlue = { 44, 44, 127, 255 };
    InitWindow(300, 600, "Raylib Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.print();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
