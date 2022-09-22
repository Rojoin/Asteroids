#include "movementLogic.h"

void moveSpaceShip(SpaceShip& ship)
{
	Vector2 mouse = getMouseInput();
	Vector2 shipPos = ship.position;
	Vector2 direction = { mouse.x - shipPos.x, mouse.y - shipPos.y };


	float grades = (atan(direction.y / direction.x)) * (180 / PI);
	if (direction.x < 0)
	{
		grades += 180;
	}
	ship.rotation = grades;

	direction = Vector2Normalize(direction);
	if (IsKeyDown(KEY_SPACE))
	{
		ship.aceleration.x += direction.x;
		ship.aceleration.y += direction.y;
	
	}

}
