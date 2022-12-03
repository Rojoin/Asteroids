#include <raylib.h>

#include "button.h"
#include "GameStates.h"
#include "optionsState.h"


Button backButton = createButton(" GO BACK", RED);
Button fullScreen;
Button changeScreen;
static int resolutionIndex = 1;
static int maxResolutionIndex = 4;
Vector2 screenSize {1280,768};
const Vector2 DEFAULT_SCREEN_SIZE[4] = {{1280,768},{1600,900},{1920,1080},{2560 , 1440}};

void statesOptions()
{

	backButton = createButton(0, (float)screenSize.y - backButton.rec.height * 2, backButton.buttonTittle, backButton.color);
	fullScreen = createButton(static_cast<float>(screenSize.x / 2), static_cast<float>(screenSize.y / 2), 200 , 60.0f * static_cast<float>(screenSize.y / 768), "FullScreen", RED);
	changeScreen = createButton(static_cast<float>(screenSize.x / 4), static_cast<float>(screenSize.y / 2), 200 , 60.0f * static_cast<float>(screenSize.y / 768), "Change Res", WHITE);
	Vector2 mousePoint = GetMousePosition();

	if (CheckCollisionPointRec(mousePoint, backButton.rec))
	{
		backButton.isOverThisButton = true;

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			setGameState(GameStates::Menu);
		}
	}
	else
	{
		backButton.isOverThisButton = false;
	}

	if (CheckCollisionPointRec(mousePoint, fullScreen.rec))
	{
		fullScreen.isOverThisButton = true;

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			ToggleFullscreen();
		}
	}
	else
	{
		fullScreen.isOverThisButton = false;
	}

	if (GetScreenWidth() < 2560)
	{
		maxResolutionIndex = 3;
	}
	else if (GetScreenWidth() < 1920)
	{
		maxResolutionIndex = 2;
	}
	else if (GetScreenWidth() < 1600)
	{
		maxResolutionIndex = 1;
	}

	if (CheckCollisionPointRec(mousePoint, changeScreen.rec))
	{
		changeScreen.isOverThisButton = true;

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			resolutionIndex++;
			if (resolutionIndex > maxResolutionIndex)
			{
				resolutionIndex = 1;
			}
		}
	}
	else
	{
		changeScreen.isOverThisButton = false;
	}

	switch (resolutionIndex)
	{
		case 1:
			SetWindowSize(1024 , 768);
			screenSize = DEFAULT_SCREEN_SIZE[0];
			break;
		case 2:
			SetWindowSize(1600, 900);
			screenSize = DEFAULT_SCREEN_SIZE[1];
			break;
		case 3:
			SetWindowSize(1920 , 1080);
			screenSize = DEFAULT_SCREEN_SIZE[2];
			break;
		case 4:
			SetWindowSize(2560 , 1440);
			screenSize = DEFAULT_SCREEN_SIZE[3];
			break;
	}

	

}
void drawOptions()
{

	ClearBackground(BLACK);
	drawButton(fullScreen);
	drawButton(changeScreen);
	drawButton(backButton);

}