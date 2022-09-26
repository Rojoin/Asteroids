#include "collisionLogic.h"

#include <iostream>

#include "../system/collisionFunctions.h"
#include "../gameObjects/spaceShip.h"

extern SpaceShip spaceShip;
extern Asteroid mediumAsteroid[20];
extern Asteroid smallAsteroid[40];
extern int mediumAsteroidCount ;
extern int smallAsteroidCount ;
void GameLogic::asteroidBulletCollision(Asteroid& asteroid, Bullet& bullet)
{

	if (isCircleCircleColliding(asteroid.circle,bullet.circle)&& bullet.isActive&&asteroid.isActive)
	{
		deactivateAsteroid(asteroid);
		deactivateBullet(bullet);
		spaceShip.score += asteroid.points;
		if (asteroid.type==AsteroidType::Default)
		{
			activateNewAsteroids(asteroid, mediumAsteroid[mediumAsteroidCount]);
			mediumAsteroidCount++;
			activateNewAsteroids(asteroid, mediumAsteroid[mediumAsteroidCount]);
			mediumAsteroidCount++;
		}
		else if (asteroid.type == AsteroidType::Medium)
		{
			activateNewAsteroids(asteroid, smallAsteroid[smallAsteroidCount]);
			smallAsteroidCount++;						 
			activateNewAsteroids(asteroid, smallAsteroid[smallAsteroidCount]);
		smallAsteroidCount++;
		}
	}

}

void GameLogic::asteroidSpaceShipCollision(Asteroid& asteroid, SpaceShip& ship)
{
	if (isCircleCircleColliding(asteroid.circle,ship.circle) && asteroid.isActive)
	{
		std::cout << "Perdiste";
	}
}
