#pragma once
#include "raylib.h"

#include "gameObjects/spaceShip.h"
#include "gameObjects/Asteroid.h"


using namespace GameObjects;
namespace GameLogic
{

	float getSpaceShipRotation(Vector2 direction);
	Vector2 getSpaceShipDirection(SpaceShip ship);
	void moveSpaceShip(SpaceShip& ship);
	void warpOutOfBounds(SpaceShip& ship);
	void updateCurrentSpaceShipPos(SpaceShip ship);
	void moveAsteroidAcrossScreen(Asteroid& asteroid);
}