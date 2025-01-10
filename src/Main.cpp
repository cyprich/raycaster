#include "Board.h"
#include "Player.h"
#include "raylib.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    InitWindow(512, 512, "raycaster");
    SetTargetFPS(100);

    std::cout << "Hello to raycaster!" << std::endl;

    Board *b = new Board();
    Player *p = new Player();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        b->update();
        p->update();

        EndDrawing();
    }

    CloseWindow();

    delete p;
    delete b;

    return 0;
}
