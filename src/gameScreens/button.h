#pragma once
#include "raylib.h"
#include "string"

struct Button
{
	Rectangle rec;
	bool isOverThisButton;
	bool isSelected;
	Color color;
	const char* buttonTittle;
};
static float buttonWidth = 200;
static float buttonHeight = 40;

void drawButton(Button button);
void drawButtonTranslucent(Button button);
Button createButton(float x, float y, float width, float height, const char* buttonTitle, Color color);
Button createButton(float x, float y, const char* buttonTitle, Color color);
Button createButton(const char* buttonTitle, Color color);

