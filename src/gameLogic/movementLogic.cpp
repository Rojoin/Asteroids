#include "movementLogic.h"
#include  <iostream>


Vector2 getSpaceShipDirection(SpaceShip ship)
{
	Vector2 mouse = getMouseInput();
	Vector2 shipPos = { ship.dest.x, ship.dest.y };
	Vector2 direction = { mouse.x - shipPos.x, mouse.y - shipPos.y };
	return direction;
}
float getSpaceShipRotation(Vector2 direction)
{
	float grades = (atan(direction.y / direction.x)) * (180 / PI);
	if (direction.x < 0)
	{
		grades += 180;
	}
	return grades;
}
void moveSpaceShip(SpaceShip& ship)
{
	Vector2 direction = getSpaceShipDirection(ship);

	
	ship.rotation = getSpaceShipRotation(direction);

	Vector2 normalizedDirection = Vector2Normalize(direction);


	

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{

		ship.aceleration.x += normalizedDirection.x * GetFrameTime() * ship.maxSpeed;
		ship.aceleration.y += normalizedDirection.y * GetFrameTime() * ship.maxSpeed;

	}
	if (ship.aceleration.x > ship.maxSpeed) 	ship.aceleration.x = ship.maxSpeed;
	else if (ship.aceleration.x < -ship.maxSpeed)ship.aceleration.x = -ship.maxSpeed;
	if (ship.aceleration.y > ship.maxSpeed)		ship.aceleration.y = ship.maxSpeed;
	else if (ship.aceleration.y < -ship.maxSpeed)ship.aceleration.y = -ship.maxSpeed;


//Check ShipAceletarion
#if _DEBUG 
	std::cout << ship.aceleration.y << std::endl;
	std::cout << ship.aceleration.x << std::endl;
#endif

	warpSpaceShipOutOfBounds(ship);
}

void warpSpaceShipOutOfBounds(SpaceShip& spaceShip)
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
