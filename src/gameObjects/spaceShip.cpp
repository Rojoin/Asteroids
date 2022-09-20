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
	return ship;
}

void drawShip()
{
	drawTexture(spaceShip.texture,  spaceShip.position,spaceShip.rotation, spaceShip.scale, WHITE);
}

void changeShipPosition()
{
	spaceShip.position = { spaceShip.position.x + spaceShip.aceleration.x * GetFrameTime(),spaceShip.position.y + spaceShip.aceleration.y * GetFrameTime()};
}


