#pragma once
#include "Bullets.h"
#include "GameObjectsEnums.h"
#include "../system/circle.h"


namespace GameObjects
{
	struct Asteroid
	{
		GameObjects::AsteroidType type;
		Texture2D texture;
		Circle circle;
		Vector2 aceleration;
		float rotation;
		float scale;
		float points;
		bool isActive;
	};
	Asteroid createAsteroid();
	Asteroid createMediumAsteroid();
	void activateNewAsteroids(Asteroid& baseAsteroid, Asteroid& newAsteroid);
	Asteroid createSmallAsteroid();
	void moveAsteroid(Asteroid& asteroid);
	void updateAsteroid(Asteroid& asteroid);
	void deactivateAsteroid(Asteroid& asteroid);
	void activateAsteroid(Asteroid& asteroid);
	void resetAsteroid(Asteroid& asteroid);
	void drawAsteroid(Asteroid& asteroid);
}