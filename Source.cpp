
#include "raylib.h"
#include "src/gameLogic/collisionLogic.h"
#include "src/gameObjects/spaceShip.h"
#include "src/gameLogic/movementLogic.h"
#include "src/gameObjects/Bullets.h"
#include "src/gameObjects/Asteroid.h"

extern SpaceShip spaceShip;
GameObjects::Bullet bullet;
GameObjects::Asteroid asteroid;
int main(void)
{
    InitWindow(1280, 720, "Ship Example");
    bullet = GameObjects::createBullet();
    asteroid = GameObjects::createAsteroid();
    Texture2D shipTexture = LoadTexture("resources/pizza.png");
    bullet.texture = shipTexture;
    asteroid.texture = shipTexture;
    Vector2 spacePosition = { (float)GetScreenWidth()/2,(float)GetScreenHeight()/2 };
    spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 2);
    while (!WindowShouldClose())
    {
        moveSpaceShip(spaceShip);
        GameObjects::moveBullet(bullet);
        GameObjects::moveAsteroid(asteroid);
        updateShip();
        GameObjects::updateBullet(bullet,spaceShip);
        if (IsKeyDown(KEY_SPACE))
        {
	        GameObjects::activateBullet(bullet,spaceShip);
        } if (IsKeyDown(KEY_V))
        {
	        GameObjects::resetBulletPosition(bullet,spaceShip);
        }
        if (Inputs::isMouseKeyDown(MOUSE_BUTTON_RIGHT))
        {
            GameObjects::activateAsteroid(asteroid);
        }
        changeShipPosition();
        moveAsteroidAcrossScreen(asteroid);
        GameLogic::asteroidBulletCollision(asteroid, bullet);
        BeginDrawing();
        drawShip();
        GameObjects::drawAsteroid(asteroid);
      GameObjects::drawBullet(bullet);
     //
        ClearBackground(BLACK);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
