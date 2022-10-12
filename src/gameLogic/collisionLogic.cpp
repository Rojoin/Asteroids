#include "collisionLogic.h"

#include <iostream>

#include "system/collisionFunctions.h"
#include "gameObjects/spaceShip.h"


using namespace GameObjects;
extern SpaceShip spaceShip;
extern Asteroid mediumAsteroids[40];
extern Asteroid smallAsteroids[80];
extern int mediumAsteroidCount;
extern int smallAsteroidCount;
Sound collisionSound;
void GameLogic::asteroidBulletCollision(Asteroid& asteroid, Bullet& bullet)
{

	if (isCircleCircleColliding(asteroid.circle, bullet.circle) && bullet.isActive && asteroid.isActive)
	{
		deactivateAsteroid(asteroid);
		deactivateBullet(bullet);
		spaceShip.score += asteroid.points;
		PlaySound(collisionSound);
		if (asteroid.type == AsteroidType::Default)
		{
			activateNewAsteroids(asteroid, mediumAsteroids[mediumAsteroidCount], -1.0f);
			mediumAsteroidCount++;
			if (mediumAsteroidCount >= 40)
			{
				mediumAsteroidCount = 0;
			}
			activateNewAsteroids(asteroid, mediumAsteroids[mediumAsteroidCount], 1.0f);
			mediumAsteroidCount++;
			if (mediumAsteroidCount >= 40)
			{
				mediumAsteroidCount = 0;
			}
		}
		else if (asteroid.type == AsteroidType::Medium)
		{
			activateNewAsteroids(asteroid, smallAsteroids[smallAsteroidCount], -1);
			smallAsteroidCount++;
			if (smallAsteroidCount >= 80)
			{
				smallAsteroidCount = 0;
			}
			activateNewAsteroids(asteroid, smallAsteroids[smallAsteroidCount], 1);
			smallAsteroidCount++;
			if (smallAsteroidCount >= 80)
			{
				smallAsteroidCount = 0;
			}
		}
	}

}

bool GameLogic::asteroidSpaceShipCollision(Asteroid& asteroid, SpaceShip& ship)
{
	if (isCircleCircleColliding(asteroid.circle, ship.circle) && asteroid.isActive)
	{
		return true;
	}
	return false;
}
