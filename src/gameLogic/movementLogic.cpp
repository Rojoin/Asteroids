#include "movementLogic.h"
#include  <iostream>

#include "../gameObjects/Asteroid.h"


namespace GameLogic
{
	

Vector2 getSpaceShipDirection(SpaceShip ship)
{
	Vector2 mouse = Inputs::getMouseInput();
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
	void warpOutOfBounds(SpaceShip& spaceShip)
{
	if (spaceShip.position.x < 0 - spaceShip.texture.width)
	{
		spaceShip.position.x = GetScreenWidth() - spaceShip.texture.width;
	}
	else if (spaceShip.position.x > GetScreenWidth())
	{
		spaceShip.position.x = 0 - spaceShip.texture.width;
	}
	if (spaceShip.position.y < 0 - spaceShip.texture.width)
	{
		spaceShip.position.y = GetScreenHeight() - spaceShip.texture.height;
	}
	else if (spaceShip.position.y > GetScreenHeight())
	{
		spaceShip.position.y = 0 - spaceShip.texture.height;
	}
}
void warpOutOfBounds(GameObjects::Asteroid& asteroid)
{
	if (asteroid.circle.position.x < 0 - asteroid.texture.width)
	{
		asteroid.circle.position.x = GetScreenWidth() - asteroid.texture.width;
	}
	else if (asteroid.circle.position.x > GetScreenWidth())
	{
		asteroid.circle.position.x = 0 - asteroid.texture.width;
	}
	if (asteroid.circle.position.y < 0 - asteroid.texture.width)
	{
		asteroid.circle.position.y = GetScreenHeight() - asteroid.texture.height;
	}
	else if (asteroid.circle.position.y > GetScreenHeight())
	{
		asteroid.circle.position.y = 0 - asteroid.texture.height;
	}
}
void warpOutOfBounds(GameObjects::Bullet & bullet)
{
	if ((bullet.circle.position.x < 0 - bullet.texture.width)|| (bullet.circle.position.x > GetScreenWidth())|| (bullet.circle.position.y < 0 - bullet.texture.width)||(bullet.circle.position.y > GetScreenHeight()))
	{
		deactivateBullet(bullet);
	}

}
void moveSpaceShip(SpaceShip& ship)
{
	ship.direction = getSpaceShipDirection(ship);

	
	ship.rotation = getSpaceShipRotation(ship.direction);

	Vector2 normalizedDirection = Vector2Normalize(ship.direction);


	

	if (Inputs::isMouseKeyDown(MOUSE_BUTTON_LEFT))
	{

		ship.aceleration.x += normalizedDirection.x * GetFrameTime() * ship.maxSpeed;
		ship.aceleration.y += normalizedDirection.y * GetFrameTime() * ship.maxSpeed;

	}
	if (ship.aceleration.x > ship.maxSpeed) 	ship.aceleration.x = ship.maxSpeed;
	else if (ship.aceleration.x < -ship.maxSpeed)ship.aceleration.x = -ship.maxSpeed;
	if (ship.aceleration.y > ship.maxSpeed)		ship.aceleration.y = ship.maxSpeed;
	else if (ship.aceleration.y < -ship.maxSpeed)ship.aceleration.y = -ship.maxSpeed;




	warpOutOfBounds(ship);
	for (int i = 0; i < 10; ++i)
	{
		warpOutOfBounds(ship.bullet[i]);
		
	}
}


void moveAsteroidAcrossScreen(GameObjects::Asteroid& asteroid)
{

	warpOutOfBounds(asteroid);
}

}