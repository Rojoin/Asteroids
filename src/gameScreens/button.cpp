#include "button.h"
#include "raylib.h"
#include "string"
#include "system/draw.h"

Font customFont;
extern Vector2 screenSize;
void drawButton(Button button)
{
	float roundness = 10;
	int segments = 8;
	DrawRectangleRounded(button.rec, roundness, segments, button.color);

	drawText(button.buttonTittle, button.rec.x, button.rec.y + button.rec.height / 3, 25, BLACK, customFont);

	if (button.isOverThisButton)
	{
		DrawRectangleRoundedLines(button.rec, roundness, segments, 5, BLACK);
	}

}
void drawButtonTranslucent(Button button)
{
	Color translucentButton = button.color;
	Color translucentFont = BLACK;
	translucentButton.a /= 2;
	translucentFont.a /= 2;
	float roundness = 10;
	int segments = 8;

	DrawRectangleRounded(button.rec, roundness, segments, translucentButton);
	drawText(button.buttonTittle, button.rec.x , button.rec.y + button.rec.height / 3 , 25 *static_cast<float>(screenSize.y) / 768, translucentFont, customFont);

	if (button.isOverThisButton)
	{
		DrawRectangleRounded(button.rec, roundness, segments, button.color);
		drawText(button.buttonTittle, button.rec.x , button.rec.y + button.rec.height / 3 , 25 *static_cast<float>(screenSize.y) / 768, BLACK, customFont);
		DrawRectangleRoundedLines(button.rec, roundness, segments, 5, BLACK);
	}
}
Button createButton(const char* buttonTitle, Color color)
{
	Button button;

	button.rec = { static_cast<float>(screenSize.x / 2 - buttonWidth / 2),  static_cast<float>(screenSize.y / 3), buttonWidth * static_cast<float>(screenSize.x) / 102, buttonHeight * static_cast<float>(GetScreenHeight()) / 768 };
	button.buttonTittle = buttonTitle;
	button.isSelected = false;
	button.isOverThisButton = false;
	button.color = color;

	return button;
}
Button createButton(float x, float y, const char* buttonTitle, Color color)
{
	Button button;

	button.rec = { x,y , buttonWidth * static_cast<float>(screenSize.x) / 1024, buttonHeight * static_cast<float>(screenSize.y) / 768 };
	button.buttonTittle = buttonTitle;
	button.isSelected = false;
	button.isOverThisButton = false;
	button.color = color;

	return button;
}
Button createButton(float x, float y, float width, float height, const char* buttonTitle, Color color)
{
	Button button;

	button.rec = { x,y , width * static_cast<float>(screenSize.x) / 1024, height * static_cast<float>(screenSize.y) / 768 };
	button.buttonTittle = buttonTitle;
	button.isSelected = false;
	button.isOverThisButton = false;
	button.color = color;

	return button;
}