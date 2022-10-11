#include <raylib.h>
#include "creditsState.h"
#include  "GameStates.h"
#include "system/draw.h"
#include "button.h"

extern Font customFont;
Texture2D creditsTexture;
extern Button escapeButton;
void statesCredits()
{
	Vector2 mousePoint = GetMousePosition();
	escapeButton = createButton(0, (float)GetScreenHeight() - escapeButton.rec.height * 2, escapeButton.buttonTittle, escapeButton.color);
	if (CheckCollisionPointRec(mousePoint, escapeButton.rec))
	{
		escapeButton.isOverThisButton = true;

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			setGameState(GameStates::Menu);
		}
	}
	else
	{
		escapeButton.isOverThisButton = false;
	}
}
void drawCredits()
{

	float width = static_cast<float>(GetScreenWidth());
	ClearBackground(BLACK);
	float scale = 0.12f;

	drawTexture(creditsTexture, { width / 2.0f -(creditsTexture.width/2.0f)* scale, 0}, 0, scale, WHITE);
	drawButton(escapeButton);


}