#include "gameLogic.h"

#include "collisionLogic.h"
#include "movementLogic.h"


extern SpaceShip spaceShip;
const int maxBigAsteroids = 10;
const int maxBullets = 10;
const int maxMediumAsteroids = 40;
const int maxSmallAsteroids = 80;
GameObjects::Asteroid bigAsteroid[maxBigAsteroids];
GameObjects::Asteroid mediumAsteroid[maxMediumAsteroids];
GameObjects::Asteroid smallAsteroid[maxSmallAsteroids];
int mediumAsteroidCount = 0;
int smallAsteroidCount = 0;

int bigAsteroidsOnScreen = 10 / 2;
int mediumAsteroidsOnScreen = 40 / 2;
int smallAsteroidsOnScreen = 80 / 2;
 Texture2D shipTexture;
 Texture2D bulletTexture;
 Texture2D asteroidTexture;
 Texture2D asteroidMediumTexture;
void initGame()
{

	for (int i = 0; i < maxSmallAsteroids; ++i)
	{
		if (i < 10 )
		{
			bigAsteroid[i] = GameObjects::createAsteroid();
			bigAsteroid[i].texture = asteroidTexture;
		}
		if (i < maxMediumAsteroids )
		{
			mediumAsteroid[i] = GameObjects::createMediumAsteroid();
			mediumAsteroid[i].texture = asteroidMediumTexture;
		}

		smallAsteroid[i] = GameObjects::createSmallAsteroid();
		smallAsteroid[i].texture = asteroidTexture;
	}

	Vector2 spacePosition = { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 };
	spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 1);
	initBullets(bulletTexture);
}
void resetGame()
{

	for (int i = 0; i < maxSmallAsteroids; ++i)
	{
		if (i < 10)
		{
			bigAsteroid[i] = GameObjects::createAsteroid();
			bigAsteroid[i].texture = asteroidTexture;
		}
		if (i < maxMediumAsteroids)
		{
			mediumAsteroid[i] = GameObjects::createMediumAsteroid();
			mediumAsteroid[i].texture = asteroidMediumTexture;
		}

		smallAsteroid[i] = GameObjects::createSmallAsteroid();
		smallAsteroid[i].texture = asteroidTexture;
	}

	Vector2 spacePosition = { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 };
	resetSpaceShip(spaceShip, spacePosition);
	initBullets(bulletTexture);
}

void playGame()
{

	GameLogic::moveSpaceShip(spaceShip);
	for (int i = 0; i < maxBullets; i++)
	{
		GameObjects::moveBullet(spaceShip.bullet[i]);
	}
	for (int i = 0; i < maxBigAsteroids; i++)
	{
		GameObjects::moveAsteroid(bigAsteroid[i]);
	}
	for (int i = 0; i < maxMediumAsteroids; ++i)
	{
		GameObjects::moveAsteroid(mediumAsteroid[i]);
	}for (int i = 0; i < maxSmallAsteroids; ++i)
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
		for (int i = 0; i < maxBigAsteroids; ++i)
		{

			GameObjects::activateAsteroid(bigAsteroid[i]);

		}
	}
	changeShipPosition();
	for (int i = 0; i < maxBullets; i++)
	{
		for (int j = 0; j < maxBigAsteroids; j++)
		{
		GameLogic::moveAsteroidAcrossScreen(bigAsteroid[i]);
		if (GameLogic::asteroidSpaceShipCollision(bigAsteroid[i], spaceShip))
		{
			resetGame();
		}
	
			GameLogic::asteroidBulletCollision(bigAsteroid[j], spaceShip.bullet[i]);
			
		}
		for (int j = 0; j < maxMediumAsteroids; j++)
		{
			GameLogic::moveAsteroidAcrossScreen(mediumAsteroid[j]);
			if (GameLogic::asteroidSpaceShipCollision(mediumAsteroid[j], spaceShip))
			{
				resetGame();
			}
			GameLogic::asteroidBulletCollision(mediumAsteroid[j], spaceShip.bullet[i]);
		}for (int j = 0; j < maxSmallAsteroids; j++)
		{
			GameLogic::moveAsteroidAcrossScreen(smallAsteroid[j]);
			if (GameLogic::asteroidSpaceShipCollision(smallAsteroid[j], spaceShip))
			{
				resetGame();
			}
			GameLogic::asteroidBulletCollision(smallAsteroid[j], spaceShip.bullet[i]);
		}
		if (!bigAsteroid[i].isActive)
			{
				resetAsteroid(bigAsteroid[i]);
			}
	}
}
void drawGame()
{
	for (int i = 0; i < maxBullets; ++i)
	{
		
		GameObjects::drawBullet(spaceShip.bullet[i]);
	}
	for (int i = 0; i < maxBigAsteroids; i++)
	{
		GameObjects::drawAsteroid(bigAsteroid[i]);

	}
	for (int i = 0; i < maxMediumAsteroids; ++i)
	{
		GameObjects::drawAsteroid(mediumAsteroid[i]);
	}
	for (int i = 0; i < maxSmallAsteroids; ++i)
	{

		GameObjects::drawAsteroid(smallAsteroid[i]);
	}
	drawShip();

}

