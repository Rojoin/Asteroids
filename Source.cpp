
#include "raylib.h"
#include "src/gameObjects/spaceShip.h"
#include "src/gameLogic/movementLogic.h"
#include "src/gameObjects/Bullets.h"

extern SpaceShip spaceShip;
Asteroids::Bullet bullet;

int main(void)
{
    InitWindow(800, 800, "Ship Example");
    bullet = Asteroids::createBullet();
   
    Texture2D shipTexture = LoadTexture("resources/pizza.png");
    bullet.texture = shipTexture;
    Vector2 spacePosition = { (float)GetScreenWidth()/2,(float)GetScreenHeight()/2 };
    spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 2);
    while (!WindowShouldClose())
    {
        moveSpaceShip(spaceShip);
        Asteroids::moveBullet(bullet);
        updateShip();
        Asteroids::updateBullet(bullet,spaceShip);
        if (IsKeyDown(KEY_SPACE))
        {
	        Asteroids::activateBullet(bullet,spaceShip);
        } if (IsKeyDown(KEY_V))
        {
	        Asteroids::resetBulletPosition(bullet,spaceShip);
        }
        changeShipPosition();
        Asteroids::moveBullet(bullet);
        BeginDrawing();
        drawShip();
      Asteroids::drawBullet(bullet);
     //
        ClearBackground(BLACK);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
