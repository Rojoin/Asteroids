#include "gameLogic.h"

#include <iostream>

#include "collisionLogic.h"
#include "movementLogic.h"
#include "shootLogic.h"
#include "../system/collisionFunctions.h"
#include "mouseInputs.h"
#include "../gameScreens/button.h"
#include "../gameScreens/GameStates.h"
#include "../system/draw.h"


extern SpaceShip spaceShip;
extern Font customFont;
extern GameStates gameStates;
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
Texture2D livesTexture;
Texture2D shipTexture;
Texture2D bulletTexture;
Texture2D asteroidTexture;
Texture2D asteroidMediumTexture;
Sound deathSound;
Sound bulletSound;
Button pauseMenuButton = createButton(GetScreenWidth() / 2 - buttonWidth, 0, buttonWidth, buttonHeight, "PAUSE", GREEN);
Button continueMenuButton = createButton(GetScreenWidth() / 2 - buttonWidth, GetScreenHeight() / 2, buttonWidth, buttonHeight, "CONTINUE", BROWN);
Button restartMenuButton = createButton(GetScreenWidth() / 3 + GetScreenWidth() / 4 - buttonWidth, GetScreenHeight() / 2.0f + buttonHeight, buttonWidth, buttonHeight, "RESTART", GREEN);
Button exitMenuButton = createButton((GetScreenWidth() / 3) * 2 - GetScreenWidth() / 4 - buttonWidth, GetScreenHeight() / 2.0f + buttonHeight, " EXIT", GREEN);
bool isGamePaused = false;
void initGame()
{
	isGamePaused = false;
	continueMenuButton = createButton(GetScreenWidth() / 2 - buttonWidth/2, GetScreenHeight() / 2- GetScreenHeight()/8, buttonWidth, buttonHeight, " CONTINUE", DARKGREEN);
	restartMenuButton = createButton(GetScreenWidth() / 3 + GetScreenWidth() / 4 - buttonWidth/2, GetScreenHeight() / 2.0f - buttonHeight, buttonWidth, buttonHeight, " RESTART", RED);
	exitMenuButton = createButton((GetScreenWidth() / 3)  + GetScreenWidth() / 4 - buttonWidth*1.5f, GetScreenHeight() / 2.0f - buttonHeight, "   EXIT", DARKPURPLE);
	pauseMenuButton = createButton(GetScreenWidth() / 2 - buttonWidth / 2, 0 + buttonHeight / 2, buttonWidth, buttonHeight, "  PAUSE", DARKGREEN);
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
	spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 1, deathSound);
	initBullets(bulletTexture, bulletSound);
}
void resetGame()
{
	isGamePaused = false;
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
	initBullets(bulletTexture, bulletSound);
	if (spaceShip.lives <= 0)
	{
		setGameState(GameStates::Menu);
	}
}

void playGame()
{
#if _DEBUG
	if (IsKeyPressed(KEY_P))
	{
		isGamePaused = true;
	}
	else if (IsKeyPressed(KEY_O))
	{
		isGamePaused = false;
	}

#endif

	if (!isGamePaused)
	{

		if (isPointRecColliding(Inputs::getMouseInput(), pauseMenuButton.rec))
		{
			pauseMenuButton.isOverThisButton = true;


			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			{

				isGamePaused = true;

			}

		}
		else
		{
			pauseMenuButton.isOverThisButton = false;
		}

		GameLogic::moveSpaceShip(spaceShip);
		for (int i = 0; i < maxBullets; i++)
		{
			GameObjects::changeBulletPosition(spaceShip.bullet[i]);
		}
		for (int i = 0; i < maxBigAsteroids; i++)
		{
			GameObjects::changeAsteroidPosition(bigAsteroid[i]);
		}
		for (int i = 0; i < maxMediumAsteroids; ++i)
		{
			GameObjects::changeAsteroidPosition(mediumAsteroid[i]);
		}for (int i = 0; i < maxSmallAsteroids; ++i)
		{
			GameObjects::changeAsteroidPosition(smallAsteroid[i]);
		}

		GameLogic::updateCurrentSpaceShipPos(spaceShip);
		updateShip();
		updateBullet();
		shootBullets(spaceShip);

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
	else if (isGamePaused)
	{

		if (isPointRecColliding(Inputs::getMouseInput(), exitMenuButton.rec))
		{
			exitMenuButton.isOverThisButton = true;


			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			{

				setGameState(GameStates::Menu);

			}

		}
		else
		{
			exitMenuButton.isOverThisButton = false;
		}
		if (isPointRecColliding(Inputs::getMouseInput(), continueMenuButton.rec))
		{
			continueMenuButton.isOverThisButton = true;


			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			{

				isGamePaused = false;

			}

		}
		else
		{
			continueMenuButton.isOverThisButton = false;
		}
		if (isPointRecColliding(Inputs::getMouseInput(), restartMenuButton.rec))
		{
			restartMenuButton.isOverThisButton = true;


			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			{

				initGame();

			}

		}
		else
		{
			restartMenuButton.isOverThisButton = false;
		}

	}
}
void drawPauseMenu()
{

	DrawRectangle(GetScreenWidth() / 4, GetScreenHeight() / 3, GetScreenWidth() / 2, GetScreenHeight() / 4, BROWN);
	std::string pauseTitle = "PAUSE MENU";
	std::string pauseSubtitle = TextFormat("Press the ESC to play");
	std::string pauseSubtitle2 = TextFormat("Press SPACE to go back to menu");
	DrawText(pauseTitle.c_str(), (GetScreenWidth() / 3) + pauseTitle.length() * 16 / 3, GetScreenHeight() / 3, 16, BLACK);
	DrawText(pauseSubtitle.c_str(), (GetScreenWidth() / 4) + pauseSubtitle.length() * 16 / (pauseSubtitle.length() / 2), GetScreenHeight() / 2.5f, 16, BLACK);
	DrawText(pauseSubtitle2.c_str(), (GetScreenWidth() / 4) + pauseSubtitle2.length() * 16 / (pauseSubtitle2.length() / 2), GetScreenHeight() / 2.2f, 16, BLACK);
}
void drawUI()
{
	for (int i = 0; i < spaceShip.lives; i++)
	{
		drawTexture(livesTexture, { GetScreenWidth() - livesTexture.width * (i + 1.0f),0 }, 0, 1, WHITE);
	}
	drawText(TextFormat("SCORE: %1i", spaceShip.score), 0, 0, 50, BLACK, customFont);
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
	drawButtonTranslucent(pauseMenuButton);
	drawUI();

	if (isGamePaused)
	{
		
		DrawRectangle(GetScreenWidth() / 4, GetScreenHeight() / 3, GetScreenWidth() / 2, GetScreenHeight() / 4, BROWN);
		std::string pauseTitle = "PAUSE MENU";
		drawButton(continueMenuButton);
		drawButton(restartMenuButton);
		drawButton(exitMenuButton);






	}
}

