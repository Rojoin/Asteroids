
#include "raylib.h"
#include "src/gameObjects/spaceShip.h"
#include "src/gameLogic/movementLogic.h"
#include "src/gameObjects/Bullets.h"

extern SpaceShip spaceShip;
GameObjects::Bullet bullet;

int main(void)
{
    InitWindow(800, 800, "Ship Example");
    bullet = GameObjects::createBullet();
   
    Texture2D shipTexture = LoadTexture("resources/pizza.png");
    bullet.texture = shipTexture;
    Vector2 spacePosition = { (float)GetScreenWidth()/2,(float)GetScreenHeight()/2 };
    spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 2);
    while (!WindowShouldClose())
    {
        moveSpaceShip(spaceShip);
        GameObjects::moveBullet(bullet);
        updateShip();
        GameObjects::updateBullet(bullet,spaceShip);
        if (IsKeyDown(KEY_SPACE))
        {
	        GameObjects::activateBullet(bullet,spaceShip);
        } if (IsKeyDown(KEY_V))
        {
	        GameObjects::resetBulletPosition(bullet,spaceShip);
        }
        changeShipPosition();
        GameObjects::moveBullet(bullet);
        BeginDrawing();
        drawShip();
      GameObjects::drawBullet(bullet);
     //
        ClearBackground(BLACK);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
