#include "draw.h"
#include "raylib.h"
#include <string>

void drawTexture(Texture2D texture,Vector2 position,float rotation,float scale,Color tint)
{

	DrawTextureEx(texture, position, rotation, scale, tint);

}

void drawText(std::string text,float posX,float posY, float fontSize,Color color)
{

	DrawText(text.c_str(), posX, posY, fontSize, color);
}