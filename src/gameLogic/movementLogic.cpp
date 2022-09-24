#include "movementLogic.h"
#include  <iostream>


Vector2 getSpaceShipDirection(SpaceShip ship)
{
	Vector2 mouse = getMouseInput();
	Vector2 shipPos = { ship.dest.x, ship.dest.y };
	Vector2 direction = { mouse.x - shipPos.x, mouse.y - shipPos.y };
	return direction;
}
void moveSpaceShip(SpaceShip& ship)
{
	Vector2 direction = getSpaceShipDirection(ship);

	float grades = (atan(direction.y / direction.x)) * (180 / PI);
	if (direction.x < 0)
	{
		grades += 180;
	}
	ship.rotation = grades;

	Vector2 normalizedDirection = Vector2Normalize(direction);


	float maxSpeed = 200.0f;//tiene que ir en o

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{

		ship.aceleration.x += normalizedDirection.x * GetFrameTime() * maxSpeed;
		ship.aceleration.y += normalizedDirection.y * GetFrameTime() * maxSpeed;

	}
	if (ship.aceleration.x > maxSpeed) 	ship.aceleration.x = maxSpeed;
	else if (ship.aceleration.x < -maxSpeed)ship.aceleration.x = -maxSpeed;
	if (ship.aceleration.y > maxSpeed)		ship.aceleration.y = maxSpeed;
	else if (ship.aceleration.y < -maxSpeed)ship.aceleration.y = -maxSpeed;


//Check ShipAceletarion
#if _DEBUG 
	std::cout << ship.aceleration.y << std::endl;
	std::cout << ship.aceleration.x << std::endl;
#endif

	warpSpaceShip(ship);
}

void warpSpaceShip(SpaceShip& spaceShip)
{
	if (spaceShip.position.x < 0 - spaceShip.texture.width)
	{
		spaceShip.position.x = GetScreenWidth() - spaceShip.texture.width;
	}
	else if (spaceShip.position.x > GetScreenWidth())
	{
		spaceShip.position.x = 0 + spaceShip.texture.width;
	}
	if (spaceShip.position.y < 0 - spaceShip.texture.width)
	{
		spaceShip.position.y = GetScreenHeight() - spaceShip.texture.height;
	}
	else if (spaceShip.position.y > GetScreenHeight())
	{
		spaceShip.position.y = 0 + spaceShip.texture.height;
	}
}
