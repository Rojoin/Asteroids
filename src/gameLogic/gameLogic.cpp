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


using namespace GameObjects;
extern SpaceShip spaceShip;
extern Font customFont;
extern GameStates gameStates;
const int maxBigAsteroids = 4;
const int maxMediumAsteroids = 40;
const int maxSmallAsteroids = 80;
Asteroid specialAsteroid;
Asteroid bigAsteroids[maxBigAsteroids];
Asteroid mediumAsteroids[maxMediumAsteroids];
Asteroid smallAsteroids[maxSmallAsteroids];

int mediumAsteroidCount = 0;
int smallAsteroidCount = 0;

float highScore = 0;
int mediumAsteroidsOnScreen = 40 / 2;
int smallAsteroidsOnScreen = 80 / 2;
Texture2D livesTexture;



Button pauseMenuButton = createButton(0, 0, buttonWidth, buttonHeight, "PAUSE", GREEN);
Button continueMenuButton = createButton(0, 0, buttonWidth, buttonHeight, "CONTINUE", BROWN);
Button restartMenuButton = createButton(0, 0, buttonWidth, buttonHeight, "RESTART", GREEN);
Button exitMenuButton = createButton(0, 0, " EXIT", GREEN);
bool isGamePaused = false;
bool isGameOver = false;
bool isPlayerDead = false;
namespace GameLogic
{


	void initGame()
	{
		isGameOver = false;
		isGamePaused = false;
		float width = static_cast<float>(GetScreenWidth());
		float height = static_cast<float>(GetScreenHeight());
		isGamePaused = false;
		continueMenuButton = createButton(width / 2 - buttonWidth / 2, height / 2 - height / 8, buttonWidth, buttonHeight, " CONTINUE", DARKGREEN);
		restartMenuButton = createButton(width / 3 + width / 4 - buttonWidth / 2, height / 2.0f - buttonHeight, buttonWidth, buttonHeight, " RESTART", DARKPURPLE);
		exitMenuButton = createButton(width / 3 + width / 8 - buttonWidth, height / 2.0f - buttonHeight, buttonWidth, buttonHeight, "   EXIT", RED);
		pauseMenuButton = createButton(width / 2 - buttonWidth / 2, 0 + buttonHeight / 2, buttonWidth, buttonHeight, "  PAUSE", DARKGREEN);
		specialAsteroid = createSpecialAsteroid();
		resetAsteroid(specialAsteroid);

		specialAsteroid.isActive = true;
		for (int i = 0; i < maxSmallAsteroids; ++i)
		{
			if (i < maxBigAsteroids)
			{
				bigAsteroids[i] = createBigAsteroid();
				;
			}

			if (i < maxMediumAsteroids)
			{
				mediumAsteroids[i] = createMediumAsteroid();

			}

			smallAsteroids[i] = createSmallAsteroid();

		}

		Vector2 spacePosition = { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 };
		spaceShip = initSpaceShip(spacePosition, 0, 1);
		initBullets();
		highScore = static_cast<float>(LoadStorageValue(0));
	}
	void resetGame()
	{
		isGamePaused = false;
		specialAsteroid = createSpecialAsteroid();
		resetAsteroid(specialAsteroid);

		specialAsteroid.isActive = true;

		for (int i = 0; i < maxSmallAsteroids; ++i)
		{
			if (i < maxBigAsteroids)
			{
				bigAsteroids[i] = createBigAsteroid();

			}
			if (i < maxMediumAsteroids)
			{
				mediumAsteroids[i] = createMediumAsteroid();

			}

			smallAsteroids[i] = createSmallAsteroid();

		}

		Vector2 spacePosition = { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 };
		resetSpaceShip(spaceShip, spacePosition);
		initBullets();
		if (spaceShip.lives <= 0)
		{
			if (spaceShip.score > highScore)
			{
				highScore = spaceShip.score;
				if (SaveStorageValue(0, static_cast<int>(highScore)))
				{
					std::cout << "Se guardo Correctamente";
				}
			}
			isGameOver = true;
		}
	}
	void playGame()
	{
#if _DEBUG
		if (IsKeyPressed(KEY_P))
		{

			activatetBulletPowerUp();

		}
		else if (IsKeyPressed(KEY_O))
		{

			spaceShip.bulletType = BulletType::Sniper;
		}

#endif

		if (isGameOver)
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

		else if (!isGamePaused)
		{
			updateShootTimer();
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
			changeAsteroidPosition(specialAsteroid);
			for (int i = 0; i < maxBullets; i++)
			{
				changeBulletPosition(spaceShip.bullet[i]);
			}
			for (int i = 0; i < maxBigAsteroids; i++)
			{
				changeAsteroidPosition(bigAsteroids[i]);
			}
			for (int i = 0; i < maxMediumAsteroids; ++i)
			{
				changeAsteroidPosition(mediumAsteroids[i]);
			}
			for (int i = 0; i < maxSmallAsteroids; ++i)
			{
				changeAsteroidPosition(smallAsteroids[i]);
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
					GameLogic::moveAsteroidAcrossScreen(bigAsteroids[i]);
					if (GameLogic::asteroidSpaceShipCollision(bigAsteroids[i], spaceShip))
					{
						resetGame();
					}

					GameLogic::asteroidBulletCollision(bigAsteroids[j], spaceShip.bullet[i]);

				}

				for (int j = 0; j < maxMediumAsteroids; j++)
				{
					GameLogic::moveAsteroidAcrossScreen(mediumAsteroids[j]);
					if (GameLogic::asteroidSpaceShipCollision(mediumAsteroids[j], spaceShip))
					{
						resetGame();
					}
					GameLogic::asteroidBulletCollision(mediumAsteroids[j], spaceShip.bullet[i]);


				}
				for (int j = 0; j < maxSmallAsteroids; j++)
				{
					GameLogic::moveAsteroidAcrossScreen(smallAsteroids[j]);
					if (GameLogic::asteroidSpaceShipCollision(smallAsteroids[j], spaceShip))
					{
						resetGame();
					}
					GameLogic::asteroidBulletCollision(smallAsteroids[j], spaceShip.bullet[i]);
				}

			}
			for (int j = 0; j < maxBigAsteroids; ++j)
			{

				if (!bigAsteroids[j].isActive)
				{
					resetAsteroid(bigAsteroids[j]);
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
		drawButton(continueMenuButton);
		drawButton(restartMenuButton);
		drawButton(exitMenuButton);
	}
	void drawEndMenu()
	{
		DrawRectangle(GetScreenWidth() / 4, GetScreenHeight() / 3, GetScreenWidth() / 2, GetScreenHeight() / 4, BROWN);
		std::string playerScore = TextFormat("Score:%0.0F", spaceShip.score);
		Vector2 playerScoreMeasure = MeasureTextEx(customFont, playerScore.c_str(), 50, 0);
		drawText(playerScore, GetScreenWidth() / 2 - playerScoreMeasure.x * 1.5f, GetScreenHeight() / 2.5f - playerScoreMeasure.y, 50, BLACK, customFont);
		drawButton(restartMenuButton);
		drawButton(exitMenuButton);
	}
	void drawUI()
	{

		std::string playerScore = TextFormat("Score:%0.0F", spaceShip.score);
		std::string maxScore = TextFormat("Max:%0.0F", highScore);
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
			

				drawBullet(spaceShip.bullet[i]);
			
		}

		for (int i = 0; i < maxBigAsteroids; i++)
		{
			drawAsteroid(bigAsteroids[i]);

		}
		for (int i = 0; i < maxMediumAsteroids; ++i)
		{
			drawAsteroid(mediumAsteroids[i]);
		}
		for (int i = 0; i < maxSmallAsteroids; ++i)
		{

			drawAsteroid(smallAsteroids[i]);
		}
		drawAsteroid(specialAsteroid);
		drawShip();
		drawButtonTranslucent(pauseMenuButton);
		drawUI();
		if (isGameOver)
		{
			drawEndMenu();
		}
		else if (isGamePaused)
		{
			drawPauseMenu();
		}
	}
}

