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
		float speed;
		float points;
		bool isActive;
	};
	Asteroid createBigAsteroid();
	Asteroid createMediumAsteroid();
	void activateNewAsteroids(Asteroid& baseAsteroid, Asteroid& newAsteroid, int multiplier);
	Asteroid createSmallAsteroid();
	void changeAsteroidPosition(Asteroid& asteroid);
	void updateAsteroid(Asteroid& asteroid);
	void deactivateAsteroid(Asteroid& asteroid);
	void activateAsteroid(Asteroid& asteroid);
	void resetAsteroid(Asteroid& asteroid);
	void drawAsteroid(Asteroid& asteroid);
}