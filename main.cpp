#include "classes/game.h"
#include "raylib.h"
#include "classes/constants.h"


int main() 
{
    InitWindow(windowWidth, windowHeight, "Projectile");
    SetTargetFPS(60);

    Game game {};

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        {
            game.draw();
        }

        EndDrawing();
    }

    CloseWindow();
}
