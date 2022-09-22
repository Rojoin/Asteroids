
#include "raylib.h"
#include "src/gameObjects/spaceShip.h"
#include "src/gameLogic/movementLogic.h"

extern SpaceShip spaceShip;

int main(void)
{
    InitWindow(800, 800, "Ship Example");
    Texture2D shipTexture = LoadTexture("resources/pizza.png");
    Vector2 spacePosition = { (float)GetScreenWidth()/2,(float)GetScreenHeight()/2 };
    spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 10);
    while (!WindowShouldClose())
    {
        moveSpaceShip(spaceShip);
        if (IsKeyDown(KEY_W))
        {
            spaceShip.position.y -= 1.0f;
        }if (IsKeyDown(KEY_A))
        {
            spaceShip.position.x -= 1.0f;
        }if (IsKeyDown(KEY_S))
        {
            spaceShip.position.y += 1.0f;
        }if (IsKeyDown(KEY_D))
        {
            spaceShip.position.x += 1.0f;
        }
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
