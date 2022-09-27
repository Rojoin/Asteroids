#include <string>

#include "button.h"
#include "GameStates.h"
#include "raylib.h"
#include  "../gameLogic/gameLogic.h"
#include  "../system/collisionFunctions.h"
#include "../system/draw.h"

Vector2 middleScreen = { GetScreenWidth() / 2.0f,GetScreenHeight() / 2.0f };
extern Font customFont;

Vector2 Screen = { GetScreenWidth() / 2.0f,GetScreenHeight() / 2.0f };
std::string creator = "                      Game made by Ignacio 'Rojoin' Arrastua";
Button playButton = createButton("     PLAY", DARKGREEN);
Button howToPlayButton = createButton("   RULES", YELLOW);
Button optionsButton = createButton("  OPTIONS ", YELLOW);
Button creditsButton = createButton("  CREDITS ", YELLOW);
Button exitButton = createButton("   EXIT", RED);

void stateMenu(GameStates& gamestate)
{

	middleScreen = { GetScreenWidth() / 2.0f,GetScreenHeight() / 2.0f };
	playButton = createButton(middleScreen.x-playButton.rec.width/2,middleScreen.y -playButton.rec.height / 2, "   PLAY", DARKGREEN);
	howToPlayButton = createButton(middleScreen.x-howToPlayButton.rec.width/2, playButton.rec.y+ howToPlayButton.rec.height*2, howToPlayButton.buttonTittle, howToPlayButton.color);
	optionsButton = createButton(middleScreen.x - optionsButton.rec.width / 2, howToPlayButton.rec.y + optionsButton.rec.height * 2, optionsButton.buttonTittle, optionsButton.color);
	creditsButton = createButton(middleScreen.x - creditsButton.rec.width / 2, optionsButton.rec.y + creditsButton.rec.height * 2, creditsButton.buttonTittle, creditsButton.color);
	exitButton = createButton(middleScreen.x - exitButton.rec.width / 2, creditsButton.rec.y + exitButton.rec.height * 2 ,exitButton.buttonTittle, exitButton.color);
	Vector2 mousePoint = GetMousePosition();

	if (isPointRecColliding(mousePoint, playButton.rec))
	{
		playButton.isOverThisButton = true;


		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			gamestate = GameStates::Game;
			initGame();

		}

	}
	else
	{
		playButton.isOverThisButton = false;
	}
	if (isPointRecColliding(mousePoint, howToPlayButton.rec))
	{
		howToPlayButton.isOverThisButton = true;
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			setGameState(GameStates::HowTo);
		}
	}
	else
	{
		howToPlayButton.isOverThisButton = false;
	}
	if (isPointRecColliding(mousePoint, optionsButton.rec))
	{
		optionsButton.isOverThisButton = true;
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
		optionsButton.isOverThisButton = false;
	}

	if (isPointRecColliding(mousePoint, creditsButton.rec))
	{
		creditsButton.isOverThisButton = true;
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
		
		}
	}
	else
	{
		exitButton.isOverThisButton = false;
	}
	if (isPointRecColliding(mousePoint, exitButton.rec))
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

	drawButton(playButton);
	drawButton(howToPlayButton);
	drawButton(optionsButton);
	drawButton(creditsButton);
	drawButton(exitButton);
	int fontSize = 3 * GetScreenWidth() / 190;
	fontSize = 16;
	DrawText(creator.c_str(), GetScreenWidth() / 2 + creator.length(), GetScreenHeight() - fontSize, fontSize, RED);
	std::string titleScreen = "The Last Slice";
	
	drawText(titleScreen, ((GetScreenWidth() / 2) - titleScreen.length() * fontSize*1.5), GetScreenHeight() / 8, fontSize * 8, BLACK,customFont);
	//DrawText(titleScreen.c_str(), ((GetScreenWidth() / 2) - titleScreen.length() * fontSize), GetScreenHeight() / 8, fontSize * 4, RED);

}