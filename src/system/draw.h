#pragma once
#include "raylib.h"
#include <string>

void drawTexture(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
void drawTexture(Texture2D texture, Rectangle source, Rectangle dest, Vector2 position, float rotation,float scale, Color tint);

void drawText(std::string text, float posX, float posY, float fontSize, Color color, Font font);


