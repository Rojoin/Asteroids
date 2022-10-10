#include <string>

#include "button.h"
#include "GameStates.h"
#include "menuState.h"
#include "raylib.h"
#include  "gameLogic/gameLogic.h"
#include  "system/collisionFunctions.h"
#include "system/draw.h"

Vector2 middleScreen = { GetScreenWidth() / 2.0f,GetScreenHeight() / 2.0f };
extern Font customFont;

Vector2 Screen = { GetScreenWidth() / 2.0f,GetScreenHeight() / 2.0f };
std::string creator = "                      Game made by Ignacio 'Rojoin' Arrastua";
Button playButton = createButton("     PLAY", DARKGREEN);
Button howToPlayButton = createButton("   RULES", YELLOW);
Button optionsButton = createButton("  OPTIONS ", YELLOW);
Button creditsButton = createButton("  CREDITS ", YELLOW);
Button exitButton = createButton("   EXIT", RED);



void statesMenu(GameStates& gamestate)
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
			setGameState(GameStates::Rules);
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
			setGameState(GameStates::Credits);
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
	float width = static_cast<float>(GetScreenWidth());
	float height = static_cast<float>(GetScreenHeight());
	drawButton(playButton);
	drawButton(howToPlayButton);
	drawButton(optionsButton);
	drawButton(creditsButton);
	drawButton(exitButton);
	float fontSize = 3.0f * width / 190.0f;
	fontSize = 16;
	drawText(creator.c_str(), width / 2.0f + static_cast<float>(creator.length()), height - fontSize, fontSize, RED,customFont);
	std::string titleScreen = "The Last Slice";
	
	drawText(titleScreen, width / 2.0f - static_cast<float>(titleScreen.length()) * fontSize *1.5f, (height / 8.0f), fontSize * 8.0f, BLACK,customFont);
	//DrawText(titleScreen.c_str(), ((GetScreenWidth() / 2) - titleScreen.length() * fontSize), GetScreenHeight() / 8, fontSize * 4, RED);

}