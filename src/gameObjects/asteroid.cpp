#include "Asteroid.h"

#include <iostream>
#include <raymath.h>

#include "system/draw.h"

namespace GameObjects
{
	Asteroid createSpecialAsteroid()
	{
		Asteroid asteroid;
		asteroid.type = AsteroidType::Special;
		asteroid.circle = { {200,200}, 10 };
		asteroid.aceleration = { 0,	0 };
		asteroid.scale = 2;
		asteroid.rotation = 0;
		asteroid.points = 200;
		asteroid.speed = 50;
		asteroid.maxSpeed = 150.0f;
		asteroid.isActive = false;
		asteroid.circle.radius *= asteroid.scale;
		asteroid.direction = { 0,0 };
		asteroid.currentTimer = 15.0f;

		return asteroid;
	}

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
		asteroid.maxSpeed = 150.0f;
		asteroid.direction = { 0,0 };
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
		asteroid.direction = { 0,0 };
		asteroid.maxSpeed = 150.0f;
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
		asteroid.maxSpeed = 150.0f;
		asteroid.speed = 125;
		asteroid.direction = { 0,0 };
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
		float width = static_cast<float>(GetScreenWidth());
		float height= static_cast<float>(GetScreenHeight());
		switch (GetRandomValue(0, 4))
		{
		case 0:
			asteroid.circle.position = { width,height };
			break;
		case 1:
			asteroid.circle.position = { width,0 };
			break;
		case 2:
			asteroid.circle.position = { 0,height };
			break;
		case 3:
			asteroid.circle.position = { 0,0 };
			break;
		case 4:
			asteroid.circle.position = { 0,height / 2 };
			break;
		case 5:
			asteroid.circle.position = { width / 2,0 };
			break;

		}
		activateAsteroid(asteroid);
	}
	void deactivateAsteroid(Asteroid& asteroid)
	{
		asteroid.isActive = false;
	}
	void activateNewAsteroids(Asteroid& baseAsteroid, Asteroid& newAsteroid,float multiplier)
	{
		float width = static_cast<float>(baseAsteroid.texture.width) ;
		float height = static_cast<float>(baseAsteroid.texture.height);
		newAsteroid.circle.position = {baseAsteroid.circle.position.x - width / 2.0f * multiplier,baseAsteroid.circle.position.y - height / 2 *multiplier};
		activateAsteroid(newAsteroid);
	}
	void activateAsteroid(Asteroid& asteroid)
	{
		asteroid.aceleration = { 0,0 };
		float rX = static_cast<float>(GetRandomValue(-10, 10));
		float rY = static_cast<float>(GetRandomValue(-10, 10));
		Vector2 randomPos{ rX, rY };
		Vector2 normalizedDirection = Vector2Normalize(randomPos);
		asteroid.aceleration.x = normalizedDirection.x;
		asteroid.aceleration.y = normalizedDirection.y;
		std::cout << asteroid.aceleration.x;
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
	void updateSpecialAsteroid(Asteroid& asteroid,Vector2 shipPos)
	{
		if (asteroid.isActive)
		{
			
			Vector2 asteroidPosition = asteroid.circle.position;
			Vector2 direction = {shipPos.x - asteroidPosition.x ,  shipPos.y - asteroidPosition.y};
			float grades = (atanf(direction.y / direction.x)) * (180 / PI);
			if (direction.x < 0)
			{
				grades += 180;
			}
			asteroid.direction = direction;
			asteroid.rotation = grades;
			Vector2 normalizedDirection =Vector2Normalize(direction);

			asteroid.aceleration.x += normalizedDirection.x * GetFrameTime() ;
			asteroid.aceleration.y += normalizedDirection.y * GetFrameTime() ;

			if (asteroid.aceleration.x > asteroid.maxSpeed)
			{
				asteroid.aceleration.x = asteroid.maxSpeed;
			}
			else if (asteroid.aceleration.x < -asteroid.maxSpeed)
			{
				asteroid.aceleration.x = -asteroid.maxSpeed;
			}
			if (asteroid.aceleration.y > asteroid.maxSpeed)
			{
				asteroid.aceleration.y = asteroid.maxSpeed;
			}
			else if (asteroid.aceleration.y < -asteroid.maxSpeed)
			{
				asteroid.aceleration.y = -asteroid.maxSpeed;
			}
		}
		else if (!asteroid.isActive)
		{
			asteroid.currentTimer -= GetFrameTime();
			if (asteroid.currentTimer <= 0)
			{
				asteroid.currentTimer = 15.0f;
				resetAsteroid(asteroid);
			}
		}
	}



}
