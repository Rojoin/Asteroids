#include "collisionLogic.h"
#include "../system/collisionFunctions.h"



void GameLogic::asteroidBulletCollision(Asteroid& asteroid, Bullet& bullet)
{
	if (isCircleCircleColliding(asteroid.circle,bullet.circle))
	{
		deactivateAsteroid(asteroid);
		deactivateBullet(bullet);

	}

}
