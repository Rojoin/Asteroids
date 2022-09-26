#pragma once
#include "raylib.h"
#include "string"

struct Button
{
	Rectangle rec;
	bool isOverThisButton;
	bool isSelected;
	Color color;
	std::string buttonTittle;

};
void drawButton(Button button);
Button createButton(float x, float y, float width, float height, std::string buttonTitle, Color color);
Button createButton(float x, float y, std::string buttonTitle, Color color);
Button createButton(std::string buttonTitle, Color color);

