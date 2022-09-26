#include <string>

#include "button.h"
#include "GameStates.h"
#include "raylib.h"
#include  "../gameLogic/gameLogic.h"
#include  "../system/collisionFunctions.h"

bool test = false;
std::string creator = "                      Game made by Ignacio 'Rojoin' Arrastua";
Button playVsButton = createButton("  PLAY", WHITE);
Button playVsCpuButton = createButton("  PLAY", WHITE);
Button screenButton = createButton(" HOW ", WHITE);
Button rulesButton = createButton(" RULES ", WHITE);
Button exitButton = createButton("  EXIT", WHITE);

void stateMenu(GameStates& gamestate)
{
	playVsButton = createButton("     HOWTO", WHITE);
	playVsCpuButton = createButton(playVsButton.rec.x, (float)GetScreenHeight() / 4, playVsCpuButton.buttonTittle, playVsCpuButton.color);
	screenButton = createButton(playVsButton.rec.x, (float)GetScreenHeight() / 2 - GetScreenHeight() / 11, screenButton.buttonTittle, screenButton.color);
	rulesButton = createButton(playVsButton.rec.x, (float)GetScreenHeight() / 2, rulesButton.buttonTittle, rulesButton.color);
	exitButton = createButton(playVsButton.rec.x, (float)GetScreenHeight() / 2 + GetScreenHeight() / 4, exitButton.buttonTittle, exitButton.color);
	Vector2 mousePoint = GetMousePosition();

	if (CheckCollisionPointRec(mousePoint, playVsButton.rec))
	{
		playVsButton.isOverThisButton = true;


		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			gamestate = GameStates::Game;
			initGame();

		}

	}
	else
	{
		playVsButton.isOverThisButton = false;
	}
	if (CheckCollisionPointRec(mousePoint, playVsCpuButton.rec))
	{
		playVsCpuButton.isOverThisButton = true;
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
	
		}
	}
	else
	{
		playVsCpuButton.isOverThisButton = false;
	}
	if (isPointRecColliding(mousePoint, screenButton.rec))
	{
		screenButton.isOverThisButton = true;
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			if (!IsWindowFullscreen())
			{
				SetWindowSize(1920, 1080);
				ToggleFullscreen();

			}
			else
			{
				ToggleFullscreen();
				SetWindowSize(1280, 720);
			}

		}
	}
	else
	{
		screenButton.isOverThisButton = false;
	}

	if (CheckCollisionPointRec(mousePoint, rulesButton.rec))
	{
		rulesButton.isOverThisButton = true;
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
		
		}
	}
	else
	{
		exitButton.isOverThisButton = false;
	}
	if (CheckCollisionPointRec(mousePoint, exitButton.rec))
	{
		exitButton.isOverThisButton = true;
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			gamestate = GameStates::Exit;
		}
	}
	else
	{
		exitButton.isOverThisButton = false;
	}

}
void drawMenu()
{

	drawButton(playVsButton);
	drawButton(playVsCpuButton);
	drawButton(screenButton);
	drawButton(rulesButton);
	drawButton(exitButton);
	int fontSize = 3 * GetScreenWidth() / 190;
	DrawText(creator.c_str(), GetScreenWidth() / 2 + creator.length(), GetScreenHeight() - fontSize, fontSize, RED);
	std::string titleScreen = "The Last Slice";

	DrawText(titleScreen.c_str(), ((GetScreenWidth() / 2) - titleScreen.length() * fontSize), GetScreenHeight() / 8, fontSize * 4, RED);

}