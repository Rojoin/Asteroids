#include "movementLogic.h"

void moveSpaceShip(SpaceShip& ship)
{
	Vector2 mouse = getMouseInput();
	Vector2 shipPos = { ship.dest.x, ship.dest.y };
	Vector2 direction = { mouse.x - shipPos.x, mouse.y - shipPos.y };


	float grades = (atan(direction.y / direction.x)) * (180 / PI);
	if (direction.x < 0)
	{
		grades += 180;
	}
	ship.rotation = grades;

	direction = Vector2Normalize(direction);
	
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		
		ship.aceleration.x += direction.x;
		ship.aceleration.y += direction.y;

	}
	
	
	warpSpaceShip(ship);
}

void warpSpaceShip(SpaceShip& spaceShip)
{
	if (spaceShip.position.x < 0- spaceShip.texture.width)
	{
		spaceShip.position.x = GetScreenWidth() - spaceShip.texture.width;
	}
	else if (spaceShip.position.x > GetScreenWidth())
	{
		spaceShip.position.x = 0 + spaceShip.texture.width;
	}
	if (spaceShip.position.y < 0- spaceShip.texture.width)
	{
		spaceShip.position.y = GetScreenHeight() - spaceShip.texture.height;
	}
	else if (spaceShip.position.y > GetScreenHeight())
	{
		spaceShip.position.y = 0 + spaceShip.texture.height;
	}
}
