#include "movementLogic.h"

void moveSpaceShip(SpaceShip& ship)
{
	Vector2 mouse = getMouseInput();
	Vector2 shipPos = ship.position;
	Vector2 direction = { mouse.x - shipPos.x, mouse.y - shipPos.y };

	float rotation = tanf(direction.y / direction.x);
	float grades = rotation * (180 / PI);

	
}
