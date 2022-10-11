#include "gameLogic.h"

#include <iostream>

#include "collisionLogic.h"
#include "movementLogic.h"
#include "shootLogic.h"
#include "mouseInputs.h"
#include "gameScreens/button.h"
#include "gameScreens/GameStates.h"
#include "system/collisionFunctions.h"
#include "system/draw.h"


extern SpaceShip spaceShip;
extern Font customFont;
extern GameStates gameStates;
const int maxBullets = 20;
const int maxBigAsteroids = 4;
const int maxMediumAsteroids = 40;
const int maxSmallAsteroids = 80;
GameObjects::Asteroid specialAsteroid;
GameObjects::Asteroid bigAsteroid[maxBigAsteroids];
GameObjects::Asteroid mediumAsteroid[maxMediumAsteroids];
GameObjects::Asteroid smallAsteroid[maxSmallAsteroids];

int mediumAsteroidCount = 0;
int smallAsteroidCount = 0;


int mediumAsteroidsOnScreen = 40 / 2;
int smallAsteroidsOnScreen = 80 / 2;
Texture2D livesTexture;
Texture2D shipTexture;
Texture2D bulletTexture;
Texture2D asteroidSpecialTexture;
Texture2D asteroidBigTexture;
Texture2D asteroidMediumTexture;
Texture2D asteroidSmallTexture;
Sound deathSound;
Sound bulletSound;
Button pauseMenuButton = createButton(0, 0, buttonWidth, buttonHeight, "PAUSE", GREEN);
Button continueMenuButton = createButton(0, 0, buttonWidth, buttonHeight, "CONTINUE", BROWN);
Button restartMenuButton = createButton(0, 0, buttonWidth, buttonHeight, "RESTART", GREEN);
Button exitMenuButton = createButton(0, 0, " EXIT", GREEN);
bool isGamePaused = false;
bool isGameOver = false;
void initGame()
{
	float width = static_cast<float>(GetScreenWidth());
	float height = static_cast<float>(GetScreenHeight());
	isGamePaused = false;
	continueMenuButton = createButton(width / 2 - buttonWidth / 2, height / 2 - height / 8, buttonWidth, buttonHeight, " CONTINUE", DARKGREEN);
	restartMenuButton = createButton(width / 3 + width / 4 - buttonWidth / 2, height / 2.0f - buttonHeight, buttonWidth, buttonHeight, " RESTART", DARKPURPLE);
	exitMenuButton = createButton(width / 3 + width / 8 - buttonWidth, height / 2.0f - buttonHeight, buttonWidth, buttonHeight, "   EXIT", RED);
	pauseMenuButton = createButton(width / 2 - buttonWidth / 2, 0 + buttonHeight / 2, buttonWidth, buttonHeight, "  PAUSE", DARKGREEN);
	specialAsteroid = GameObjects::createSpecialAsteroid();
	specialAsteroid.texture = asteroidSpecialTexture;
	specialAsteroid.isActive = true;
	for (int i = 0; i < maxSmallAsteroids; ++i)
	{
		if (i < maxBigAsteroids)
		{
			bigAsteroid[i] = GameObjects::createBigAsteroid();
			bigAsteroid[i].texture = asteroidBigTexture;
		}
		if (i < maxMediumAsteroids)
		{
			mediumAsteroid[i] = GameObjects::createMediumAsteroid();
			mediumAsteroid[i].texture = asteroidMediumTexture;
		}

		smallAsteroid[i] = GameObjects::createSmallAsteroid();
		smallAsteroid[i].texture = asteroidSmallTexture;
	}

	Vector2 spacePosition = { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 };
	spaceShip = initSpaceShip(shipTexture, spacePosition, 0, 1, deathSound);
	initBullets(bulletTexture, bulletSound);
}
void resetGame()
{
	isGamePaused = false;
	specialAsteroid = GameObjects::createSpecialAsteroid();
	specialAsteroid.texture = asteroidSpecialTexture;
	specialAsteroid.isActive = true;

	for (int i = 0; i < maxSmallAsteroids; ++i)
	{
		if (i < maxBigAsteroids)
		{
			bigAsteroid[i] = GameObjects::createBigAsteroid();
			bigAsteroid[i].texture = asteroidBigTexture;
		}
		if (i < maxMediumAsteroids)
		{
			mediumAsteroid[i] = GameObjects::createMediumAsteroid();
			mediumAsteroid[i].texture = asteroidMediumTexture;
		}

		smallAsteroid[i] = GameObjects::createSmallAsteroid();
		smallAsteroid[i].texture = asteroidBigTexture;
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
		GameObjects::changeAsteroidPosition(specialAsteroid);
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
		}
		for (int i = 0; i < maxSmallAsteroids; ++i)
		{
			GameObjects::changeAsteroidPosition(smallAsteroid[i]);
		}

		GameLogic::updateCurrentSpaceShipPos(spaceShip);
		updateShip();
		updateBullet();
		shootBullets();

		changeShipPosition();
		for (int i = 0; i < maxBullets; i++)
		{
			GameLogic::moveAsteroidAcrossScreen(specialAsteroid);
			if (GameLogic::asteroidSpaceShipCollision(specialAsteroid, spaceShip))
			{
				resetGame();
			}

			GameLogic::asteroidBulletCollision(specialAsteroid, spaceShip.bullet[i]);

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
			

			}
			for (int j = 0; j < maxSmallAsteroids; j++)
			{
				GameLogic::moveAsteroidAcrossScreen(smallAsteroid[j]);
				if (GameLogic::asteroidSpaceShipCollision(smallAsteroid[j], spaceShip))
				{
					resetGame();
				}
				GameLogic::asteroidBulletCollision(smallAsteroid[j], spaceShip.bullet[i]);
			}

		}
		for (int j = 0; j < maxBigAsteroids; ++j)
		{

			if (!bigAsteroid[j].isActive)
			{
				resetAsteroid(bigAsteroid[j]);
			}
		}
		

		updateSpecialAsteroid(specialAsteroid, spaceShip.position);
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
	drawButton(continueMenuButton);
	drawButton(restartMenuButton);
	drawButton(exitMenuButton);
}
void drawUI()
{

	std::string playerScore = TextFormat("Score:%0.0F", spaceShip.score);
	std::string maxScore = TextFormat("Max:%1i", spaceShip.score);
	Vector2 scoreMeasure = MeasureTextEx(customFont, playerScore.c_str(), 50, 0);
	Vector2 maxScoreMeasure = MeasureTextEx(customFont, maxScore.c_str(), 50, 0);
	drawText(playerScore, 0, 0, 50, BLACK, customFont);
	for (int i = 0; i < spaceShip.lives; i++)
	{
		drawTexture(livesTexture, { livesTexture.width * (i + 1.0f),scoreMeasure.y }, 0, 1, WHITE);
	}
	//Implementar MaxScore
	drawText(maxScore, GetScreenWidth() - maxScoreMeasure.x * 1.5f, 0, 50, BLACK, customFont);
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
	GameObjects::drawAsteroid(specialAsteroid);
	drawShip();
	drawButtonTranslucent(pauseMenuButton);
	drawUI();

	if (isGamePaused)
	{
		drawPauseMenu();
	}
}

