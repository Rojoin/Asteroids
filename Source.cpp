
#include "raylib.h"
#include "src/gameObjects/spaceShip.h"
#include "src/gameLogic/movementLogic.h"

extern SpaceShip spaceShip;

int main(void)
{
    InitWindow(800, 800, "Ship Example");
    Texture2D shipTexture = LoadTexture("resources/pizza.png");
    Vector2 spacePosition = { (float)GetScreenWidth()/2,(float)GetScreenHeight()/2 };
    spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 2);
    while (!WindowShouldClose())
    {
        moveSpaceShip(spaceShip);
        updateShip();
        changeShipPosition();
        BeginDrawing();
        drawShip();
    
        ClearBackground(BLACK);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
