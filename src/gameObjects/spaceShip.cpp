#include  "spaceShip.h"
#include "../system/draw.h"

SpaceShip spaceShip;
SpaceShip initSpaceShip(Texture2D texture,Vector2 position,  float rotation, float scale)
{
	SpaceShip ship;

	ship.texture = texture;
	ship.position = position;
	ship.aceleration = { 0,0 };
	ship.scale = scale;
	ship.rotation = rotation;
	ship.speed = 400.0f;
	ship.source = { 0,0,32,32 };
	ship.dest = { 0,0,32,32 };
	return ship;
}

void drawShip()
{
	drawTexture(spaceShip.texture, spaceShip.source, spaceShip.dest, {spaceShip.texture.width / 2.0f, spaceShip.texture.height / 2.0f }, spaceShip.rotation,spaceShip.scale, WHITE);
}
void updateShip()
{
	spaceShip.dest = { spaceShip.position.x + spaceShip.texture.width ,spaceShip.position.y + spaceShip.texture.height / 2.0f ,spaceShip.dest.width,spaceShip.dest.height };
}
void changeShipPosition()
{
	spaceShip.position = { spaceShip.position.x + spaceShip.aceleration.x * GetFrameTime(),spaceShip.position.y + spaceShip.aceleration.y * GetFrameTime()};
	
}


