#pragma once
#include "gameObjects/asteroid.h"
#include "gameObjects/bullets.h"
#include "gameObjects/powerUp.h"


using namespace GameObjects;
namespace GameLogic
{
	void asteroidBulletCollision(Asteroid& asteroid, Bullet& bullet);
	bool powerUpSpaceShipCollision(PowerUp& powerUp);
	bool asteroidSpaceShipCollision(Asteroid& asteroid);
}
