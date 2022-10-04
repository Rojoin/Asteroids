#include "button.h"
#include "raylib.h"
#include "string"
#include "system/draw.h"

Font customFont;

void drawButton(Button button)
{
	float roundness = 10;
	int segments = 8;
	DrawRectangleRounded(button.rec, roundness, segments, button.color);
	//DrawRectangleRec(button.rec, button.color);
	
	drawText(button.buttonTittle, button.rec.x, button.rec.y + button.rec.height / 3, 25, BLACK, customFont);
	//DrawText(button.buttonTittle.c_str(), button.rec.x, button.rec.y + button.rec.height / 3, 3 * GetScreenWidth() / 190, BLACK);

	if (button.isOverThisButton)
	{
		DrawRectangleRoundedLines(button.rec, roundness, segments, 5, BLACK);
	//	DrawRectangleLinesEx(button.rec, 5, RED);
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
	
	//DrawRectangleRec(button.rec, button.color);

	drawText(button.buttonTittle, button.rec.x, button.rec.y + button.rec.height / 3, 25, translucentFont, customFont);
	//DrawText(button.buttonTittle.c_str(), button.rec.x, button.rec.y + button.rec.height / 3, 3 * GetScreenWidth() / 190, BLACK);

	if (button.isOverThisButton)
	{
		DrawRectangleRounded(button.rec, roundness, segments, button.color);
		drawText(button.buttonTittle, button.rec.x, button.rec.y + button.rec.height / 3, 25, BLACK, customFont);
		DrawRectangleRoundedLines(button.rec, roundness, segments, 5, BLACK);
		//	DrawRectangleLinesEx(button.rec, 5, RED);
	}
}
Button createButton(std::string buttonTitle, Color color)
{
	Button button;
	//float width = GetScreenWidth() / 9;
	//float height = GetScreenHeight() / 20;

	button.rec = { (float)GetScreenWidth() / 2 - buttonWidth / 2, (float)GetScreenHeight() / 3, buttonWidth, buttonHeight };
	button.buttonTittle = buttonTitle;
	button.isSelected = false;
	button.isOverThisButton = false;
	button.color = color;
	return button;
}
Button createButton(float x, float y, std::string buttonTitle, Color color)
{
	Button button;
	//float width = GetScreenWidth() / 9;
	//float height = GetScreenHeight() / 20;

	button.rec = { x,y, buttonWidth, buttonHeight };
	button.buttonTittle = buttonTitle;
	button.isSelected = false;
	button.isOverThisButton = false;
	button.color = color;
	return button;
}
Button createButton(float x, float y, float width, float height, std::string buttonTitle, Color color)
{
	Button button;

	button.rec = { x,y, width, height };
	button.buttonTittle = buttonTitle;
	button.isSelected = false;
	button.isOverThisButton = false;
	button.color = color;
	return button;
}