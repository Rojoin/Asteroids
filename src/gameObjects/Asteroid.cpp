#include "Asteroid.h"

#include <raymath.h>

#include "../system/draw.h"

namespace GameObjects
{
	Asteroid createAsteroid()
	{
		Asteroid asteroid;
		asteroid.type = AsteroidType::Default;
		asteroid.circle = { {200,200}, 10};
		asteroid.aceleration = { 0,	0 };
		asteroid.scale = 2;
		asteroid.rotation = 0;
		asteroid.isActive = false;
		asteroid.circle.radius *= asteroid.scale;

		return asteroid;
	}

	void moveAsteroid(Asteroid& asteroid)
	{
	
								   
		asteroid.circle.position.y +=  asteroid.aceleration.y*GetFrameTime()*200;
		asteroid.circle.position.x +=  asteroid.aceleration.x*GetFrameTime()*200;
			
		
	}

	void deactivateAsteroid(Asteroid& asteroid)
	{
		asteroid.isActive = false;
	}

	void activateAsteroid(Asteroid& asteroid)
	{
		asteroid.aceleration = { 0,0};
		Vector2 randomPos{(float)GetRandomValue(-10, 10), (float)GetRandomValue(-10, 10)};
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
		Rectangle dest{ asteroid.circle.position.x  ,asteroid.circle.position.y,(float)asteroid.texture.width*asteroid.scale / 2,(float)asteroid.texture.height* asteroid.scale / 2 };

		DrawCircle(asteroid.circle.position.x, asteroid.circle.position.y, asteroid.circle.radius, WHITE);
		drawTexture(asteroid.texture, source, dest, { asteroid.texture.width / 2.0f,asteroid.texture.height / 2.0f }, asteroid.rotation, asteroid.scale/2, BLUE);
		}
	}

	void updateAsteroid(Asteroid& asteroid)
	{
	}

}
