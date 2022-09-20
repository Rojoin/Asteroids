
#include "raylib.h"
#include "src/gameObjects/spaceShip.h"

extern SpaceShip spaceShip;

int main(void)
{
    InitWindow(800, 800, "Ship Example");
    Texture2D shipTexture = LoadTexture("resources/pizza.png");
    Vector2 spacePosition = { (float)GetScreenWidth()/2,(float)GetScreenHeight()/2 };
    spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 10);
    while (!WindowShouldClose())
    {
        spaceShip.rotation += 0.1f;
        BeginDrawing();
        drawShip();
        ClearBackground(BLACK);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
