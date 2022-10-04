#include "Asteroid.h"

#include <raymath.h>

#include "../system/draw.h"

namespace GameObjects
{
	Asteroid createBigAsteroid()
	{
		Asteroid asteroid;
		asteroid.type = AsteroidType::Default;
		asteroid.circle = { {200,200}, 10 };
		asteroid.aceleration = { 0,	0 };
		asteroid.scale = 2;
		asteroid.rotation = 0;
		asteroid.points = 50;
		asteroid.speed = 75;
		asteroid.isActive = false;
		asteroid.circle.radius *= asteroid.scale;

		return asteroid;
	}

	Asteroid createMediumAsteroid()
	{
		Asteroid asteroid;
		asteroid.type = AsteroidType::Medium;
		asteroid.circle = { {200,200}, 10 };
		asteroid.aceleration = { 0,	0 };
		asteroid.scale = 1.5f;
		asteroid.rotation = 0;
		asteroid.points = 100;
		asteroid.speed = 100;
		asteroid.isActive = false;
		asteroid.circle.radius *= asteroid.scale;

		return asteroid;
	}
	Asteroid createSmallAsteroid()
	{
		Asteroid asteroid;
		asteroid.type = AsteroidType::Small;
		asteroid.circle = { {0,0}, 10 };
		asteroid.aceleration = { 0,	0 };
		asteroid.scale = 1.0f;
		asteroid.rotation = 0;
		asteroid.points = 200;
		asteroid.speed = 125;
		asteroid.isActive = false;
		asteroid.circle.radius *= asteroid.scale;

		return asteroid;
	}

	void changeAsteroidPosition(Asteroid& asteroid)
	{
		if (asteroid.isActive)
		{
			asteroid.circle.position.y += asteroid.aceleration.y * GetFrameTime() * asteroid.speed;
			asteroid.circle.position.x += asteroid.aceleration.x * GetFrameTime() * asteroid.speed;
		}

	}
	void resetAsteroid(Asteroid& asteroid)
	{
		switch (GetRandomValue(0, 4))
		{
		case 0:
			asteroid.circle.position = { (float)GetScreenWidth(),(float)GetScreenHeight() };
			break;
		case 1:
			asteroid.circle.position = { (float)GetScreenWidth(),0 };
			break;
		case 2:
			asteroid.circle.position = { 0,(float)GetScreenHeight() };
			break;
		case 3:
			asteroid.circle.position = { 0,0 };
			break;
		case 4:
			asteroid.circle.position = { 0,(float)GetScreenHeight() / 2 };
			break;
		case 5:
			asteroid.circle.position = { (float)GetScreenWidth() / 2,0 };
			break;

		}
		activateAsteroid(asteroid);
	}
	void deactivateAsteroid(Asteroid& asteroid)
	{
		asteroid.isActive = false;
	}
	void activateNewAsteroids(Asteroid& baseAsteroid, Asteroid& newAsteroid,int multiplier)
	{
		newAsteroid.circle.position = { baseAsteroid.circle.position.x - baseAsteroid.texture.width / 2 * multiplier,baseAsteroid.circle.position.y - baseAsteroid.texture.height / 2 *multiplier};
		activateAsteroid(newAsteroid);
	}
	void activateAsteroid(Asteroid& asteroid)
	{
		asteroid.aceleration = { 0,0 };
		Vector2 randomPos{ (float)GetRandomValue(-10, 10), (float)GetRandomValue(-10, 10) };
		Vector2 normalizedDirection = Vector2Normalize(randomPos);
		asteroid.aceleration.x += normalizedDirection.x;
		asteroid.aceleration.y += normalizedDirection.y;
		asteroid.isActive = true;
	}

	void drawAsteroid(Asteroid& asteroid)//AGREGAR SCALE
	{
		if (asteroid.isActive)
		{

			Rectangle source{ 0,0,(float)asteroid.texture.width,(float)asteroid.texture.height };
			Rectangle dest{ asteroid.circle.position.x  ,asteroid.circle.position.y,(float)asteroid.texture.width * asteroid.scale / 2,(float)asteroid.texture.height * asteroid.scale / 2 };
#if _DEBUG

			DrawCircle(static_cast<int>(asteroid.circle.position.x), static_cast<int>(asteroid.circle.position.y), asteroid.circle.radius, WHITE);
#endif

			drawTexture(asteroid.texture, source, dest, { static_cast<float>(asteroid.texture.width) / 2.0f,static_cast<float>(asteroid.texture.height) / 2.0f }, asteroid.rotation, asteroid.scale / 2, WHITE);
		}
	}



}
