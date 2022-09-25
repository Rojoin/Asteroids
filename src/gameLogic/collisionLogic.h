#pragma once
#include "../gameObjects/Asteroid.h"
#include "../gameObjects/spaceShip.h"
#include "../gameObjects/Bullets.h"


using namespace GameObjects;
namespace GameLogic
{
	void asteroidBulletCollision(Asteroid& asteroid, Bullet& bullet);

	void asteroidSpaceShipCollision(Asteroid& asteroid, SpaceShip& ship);



}
