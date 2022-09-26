
#include "raylib.h"
#include "src/gameLogic/collisionLogic.h"
#include "src/gameObjects/spaceShip.h"
#include "src/gameLogic/movementLogic.h"
#include "src/gameObjects/Bullets.h"
#include "src/gameObjects/Asteroid.h"
#include "src/system/draw.h"

extern SpaceShip spaceShip;
GameObjects::Asteroid bigAsteroid[10];
GameObjects::Asteroid mediumAsteroid[20];
GameObjects::Asteroid smallAsteroid[40];
int bigAsteroidCount = 10;
int mediumAsteroidCount = 0;
int smallAsteroidCount = 0;
int main()
{
	InitWindow(1024, 768, "Ship Example");
	Font customFont = LoadFontEx("resources/LoftygoalsRegular-9Y5Xy.otf", 96, 0, 0);
	Texture2D shipTexture = LoadTexture("resources/pizzaTiledMap.png");
	Texture2D bulletTexture = LoadTexture("resources/olive.png");
	Texture2D asteroidTexture = LoadTexture("resources/bigHand.png");

	for (int i = 0; i < 10; ++i)
	{
		bigAsteroid[i] = GameObjects::createAsteroid();
		bigAsteroid[i].texture = asteroidTexture;
	}
	for (int i = 0; i < 20; ++i)
	{
		mediumAsteroid[i] = GameObjects::createMediumAsteroid();
		mediumAsteroid[i].texture = asteroidTexture;
	}
	for (int i = 0; i < 20; ++i)
	{
		smallAsteroid[i] = GameObjects::createSmallAsteroid();
		smallAsteroid[i].texture = asteroidTexture;
	}
	GenTextureMipmaps(&customFont.texture);
	SetTextureFilter(customFont.texture, TEXTURE_FILTER_TRILINEAR);
	Vector2 spacePosition = { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 };
	spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 1);
	initBullets(bulletTexture);
	while (!WindowShouldClose())
	{
		GameLogic::moveSpaceShip(spaceShip);
		for (int i = 0; i < 10; i++)
		{
			GameObjects::moveAsteroid(bigAsteroid[i]);
			GameObjects::moveBullet(spaceShip.bullet[i]);
		}
		for (int i = 0; i < 20; ++i)
		{
			GameObjects::moveAsteroid(mediumAsteroid[i]);
		}for (int i = 0; i < 40; ++i)
		{
			GameObjects::moveAsteroid(smallAsteroid[i]);
		}

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
			for (int i = 0; i < 10; ++i)
			{

				GameObjects::activateAsteroid(bigAsteroid[i]);
			
			}
		}
		changeShipPosition();
		for (int i = 0; i < 10; i++)
		{
			GameLogic::moveAsteroidAcrossScreen(bigAsteroid[i]);
			GameLogic::asteroidSpaceShipCollision(bigAsteroid[i], spaceShip);
			for (int j = 0; j < 10; j++)
			{

				GameLogic::asteroidBulletCollision(bigAsteroid[j], spaceShip.bullet[i]);
			}
			for (int j = 0; j < 20; j++)
			{
			GameLogic::moveAsteroidAcrossScreen(mediumAsteroid[j]);
				GameLogic::asteroidSpaceShipCollision(mediumAsteroid[i], spaceShip);
				GameLogic::asteroidBulletCollision(mediumAsteroid[j], spaceShip.bullet[i]);
			}for (int j = 0; j < 40; j++)
			{
			GameLogic::moveAsteroidAcrossScreen(smallAsteroid[j]);
				GameLogic::asteroidSpaceShipCollision(smallAsteroid[j], spaceShip);
				GameLogic::asteroidBulletCollision(smallAsteroid[j], spaceShip.bullet[i]);
			}
			//if (!bigAsteroid[i].isActive)
			//{
			//	resetAsteroid(bigAsteroid[i]);
			//}
		}
		BeginDrawing();
		for (int i = 0; i < 10; i++)
		{
			GameObjects::drawAsteroid(bigAsteroid[i]);

			GameObjects::drawBullet(spaceShip.bullet[i]);
		}
		for (int i = 0; i < 20; ++i)
		{
			GameObjects::drawAsteroid(mediumAsteroid[i]);
		}
		for (int i = 0; i < 40; ++i)
		{
			
			GameObjects::drawAsteroid(smallAsteroid[i]);
		}
		drawShip();
		drawText(TextFormat("SCORE: %1i", spaceShip.score), 0, 100, 50, WHITE, customFont);
		ClearBackground(BLACK);
		EndDrawing();

	}
	CloseWindow();
	return 0;
}
