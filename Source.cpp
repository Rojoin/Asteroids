
#include "raylib.h"
#include "src/gameLogic/collisionLogic.h"
#include "src/gameObjects/spaceShip.h"
#include "src/gameLogic/movementLogic.h"
#include "src/gameObjects/Bullets.h"
#include "src/gameObjects/Asteroid.h"

extern SpaceShip spaceShip;
GameObjects::Asteroid asteroid;
int main(void)
{
    InitWindow(1280, 720, "Ship Example");
    asteroid = GameObjects::createAsteroid();
    Texture2D shipTexture = LoadTexture("resources/pizzaTiledMap.png");
    Texture2D bulletTexture = LoadTexture("resources/olive.png");
    Texture2D asteroidTexture = LoadTexture("resources/Lips.png");
  
    asteroid.texture = asteroidTexture;
    Vector2 spacePosition = { (float)GetScreenWidth()/2,(float)GetScreenHeight()/2 };
    spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 1);
    initBullets(bulletTexture);
    while (!WindowShouldClose())
    {
        GameLogic::moveSpaceShip(spaceShip);
        for (int i = 0; i < 10; ++i)
        {
        
            GameObjects::moveBullet(spaceShip.bullet[i]);
        }
  
        GameObjects::moveAsteroid(asteroid);
        updateShip();
        updateBullet();
        if (IsKeyPressed(KEY_SPACE))
        {
	        activateBullet();
        } if (IsKeyDown(KEY_V))
        {
	        //resetBulletPosition();
        }
        if (Inputs::isMouseKeyDown(MOUSE_BUTTON_RIGHT))
        {
            GameObjects::activateAsteroid(asteroid);
        }
        changeShipPosition();
        GameLogic::moveAsteroidAcrossScreen(asteroid);
        for (int i = 0; i < 10; ++i)
        {
            GameLogic::asteroidBulletCollision(asteroid, spaceShip.bullet[i]);
        }
        GameLogic::asteroidSpaceShipCollision(asteroid, spaceShip);
        BeginDrawing();
        GameObjects::drawAsteroid(asteroid);
        for (int i = 0; i < 10; ++i)
        {

            GameObjects::drawBullet(spaceShip.bullet[i]);
        }
        drawShip();
    //
        ClearBackground(BLACK);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
