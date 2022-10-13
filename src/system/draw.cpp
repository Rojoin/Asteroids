#include "draw.h"
#include "raylib.h"

static int width;
static int height;

void updateScale()
{
	width=	GetScreenWidth() * 1 / 1024	 ;
	height =GetScreenHeight() * 1 / 768	 ;
}
void drawTexture(Texture2D texture,Vector2 position,float rotation,float scale,Color tint)
{

	DrawTextureEx(texture, position, rotation, scale, tint);

}
void drawTexture(Texture2D texture,Rectangle source,Rectangle dest, Vector2 position, float rotation,float scale, Color tint)
{
	position.x *= scale;
	position.y *= scale;
	DrawTextureTiled(texture, source, dest, position, rotation,scale, tint);

}

void drawText(const char* text,float posX,float posY, float fontSize,Color color,Font font)
{

	DrawTextEx(font, text, { posX, posY }, fontSize,10, color);
}
 int getScaleWidth()
{
	return width;
}
 int getScaleHeight()
{
	return height;
}