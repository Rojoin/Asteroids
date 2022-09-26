#include "button.h"
#include "raylib.h"
#include "string"
#include "../system/draw.h"

Font customFont;
void drawButton(Button button)
{
	DrawRectangleRec(button.rec, button.color);
	drawText(button.buttonTittle, button.rec.x, button.rec.y + button.rec.height / 3, 30, BLACK, customFont);
	//DrawText(button.buttonTittle.c_str(), button.rec.x, button.rec.y + button.rec.height / 3, 3 * GetScreenWidth() / 190, BLACK);

	if (button.isOverThisButton)
	{
		DrawRectangleLinesEx(button.rec, 5, RED);
	}

}
Button createButton(std::string buttonTitle, Color color)
{
	Button button;
	float width = GetScreenWidth() / 9;
	float height = GetScreenHeight() / 20;
	button.rec = { (float)GetScreenWidth() / 2 - width / 2, (float)GetScreenHeight() / 3, width, height };
	button.buttonTittle = buttonTitle;
	button.isSelected = false;
	button.isOverThisButton = false;
	button.color = color;
	return button;
}
Button createButton(float x, float y, std::string buttonTitle, Color color)
{
	Button button;
	float width = GetScreenWidth() / 9;
	float height = GetScreenHeight() / 20;
	button.rec = { x,y, width, height };
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