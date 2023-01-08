#include  "initialAnimationScreen.h"

#include "gameLogic/mouseInputs.h"
#include <raylib.h>

#include  "GameStates.h"
#include "system/draw.h"
#include "button.h"

extern Font customFont;
Texture2D splashScreen;
float normalizedTime = 0.0f;
float timePlayed = 0.0f;
float maxTime = 12.0f;
int currentAlpha = 0;
int maxAlpha = 255;
Color transparency ={255,255,255,0};
void statesInitialAnimation()
{
	normalizedTime = timePlayed / maxTime;
	timePlayed += GetFrameTime();

	if (timePlayed < maxTime/2 && normalizedTime <0.5f)
	{
		currentAlpha = static_cast<int>(normalizedTime *255*4);
		if (currentAlpha == maxAlpha)
		{
			setGameState(GameStates::Menu);
		}
	}
	transparency.a = static_cast<unsigned char>(currentAlpha);
}

void drawInitialAnimation()
{
	float width = static_cast<float>(GetScreenWidth());
	float height = static_cast<float>(GetScreenHeight());
	ClearBackground(BLACK);
	float fontSize = 3 * width / 190;
	const std::string GamePresentTittle = "Rojoin presenta:";
	drawText(GamePresentTittle.c_str(), width / 2.0f - static_cast<float>(GamePresentTittle.length()) * 1.5f * fontSize, height / 40, fontSize * 8.0f, DARKBROWN, customFont);
	drawTexture(splashScreen, { 0,0 }, 0, 0.5f, transparency);
}
