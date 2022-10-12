#pragma once
#include "Bullets.h"
#include "GameObjectsEnums.h"
#include "system/circle.h"


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
		float maxSpeed;
		float points;
		float currentTimer;
		bool isActive;
		Vector2 direction;
	};

	Asteroid createSpecialAsteroid();
	Asteroid createBigAsteroid();
	Asteroid createMediumAsteroid();
	void activateNewAsteroids(Asteroid& baseAsteroid, Asteroid& newAsteroid, float multiplier);
	Asteroid createSmallAsteroid();
	void changeAsteroidPosition(Asteroid& asteroid);
	void updateSpecialAsteroid(Asteroid& asteroid,Vector2 shipPos);
	void deactivateAsteroid(Asteroid& asteroid);
	void activateAsteroid(Asteroid& asteroid);
	void resetAsteroid(Asteroid& asteroid);
	void drawAsteroid(Asteroid& asteroid);
}