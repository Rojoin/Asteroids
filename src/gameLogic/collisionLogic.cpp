#include "collisionLogic.h"

#include <iostream>

#include "../system/collisionFunctions.h"
#include "../gameObjects/spaceShip.h"


void GameLogic::asteroidBulletCollision(Asteroid& asteroid, Bullet& bullet)
{

	if (isCircleCircleColliding(asteroid.circle,bullet.circle)&& bullet.isActive&&asteroid.isActive)
	{
		deactivateAsteroid(asteroid);
		deactivateBullet(bullet);

	}

}

void GameLogic::asteroidSpaceShipCollision(Asteroid& asteroid, SpaceShip& ship)
{
	if (isCircleCircleColliding(asteroid.circle,ship.circle) && asteroid.isActive)
	{
		std::cout << "Perdiste";
	}
}
