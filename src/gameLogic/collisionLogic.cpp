#include "collisionLogic.h"

#include <iostream>

#include "../system/collisionFunctions.h"
#include "../gameObjects/spaceShip.h"

extern SpaceShip spaceShip;
extern Asteroid mediumAsteroid[40];
extern Asteroid smallAsteroid[80];
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
			activateNewAsteroids(asteroid, mediumAsteroid[mediumAsteroidCount],-1);
			mediumAsteroidCount++;
			if (mediumAsteroidCount >= 40)
			{
				mediumAsteroidCount=0;
			}
			activateNewAsteroids(asteroid, mediumAsteroid[mediumAsteroidCount],1);
			mediumAsteroidCount++;
			if (mediumAsteroidCount >=40)
			{
				mediumAsteroidCount = 0;
			}
		}
		else if (asteroid.type == AsteroidType::Medium)
		{
			activateNewAsteroids(asteroid, smallAsteroid[smallAsteroidCount],-1);
			smallAsteroidCount++;
			if (smallAsteroidCount >= 80)
			{	
				smallAsteroidCount = 0;
			}
			activateNewAsteroids(asteroid, smallAsteroid[smallAsteroidCount],1);
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
	if (isCircleCircleColliding(asteroid.circle,ship.circle) && asteroid.isActive)
	{
		return true;
	}
	return false;
}
