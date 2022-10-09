#include "movementLogic.h"
#include  <iostream>
#include <raymath.h>

#include "mouseInputs.h"
#include "gameObjects/Asteroid.h"


namespace GameLogic
{

	Vector2 currentShipPos;
	Vector2 getSpaceShipDirection(SpaceShip ship)
	{
		Vector2 mouse = Inputs::getMouseInput();
		Vector2 shipPos = { ship.dest.x, ship.dest.y };
		Vector2 direction = { mouse.x - shipPos.x, mouse.y - shipPos.y };
		return direction;
	}
	float getSpaceShipRotation(Vector2 direction)
	{
		float grades = (atan(direction.y / direction.x)) * (180 / PI);
		if (direction.x < 0)
		{
			grades += 180;
		}
		return grades;
	}

	void warpOutOfBounds(SpaceShip& ship)
	{
		float width = static_cast<float>(GetScreenWidth());
		float height = static_cast<float>(GetScreenHeight());
		float textureWidth = static_cast<float>(ship.texture.width);
		float textureHeight = static_cast<float>(ship.texture.height);
		if (ship.position.x < 0.0f - textureWidth / 4.0f)
		{
			ship.position.x = width + textureWidth / 4.0f;
		}
		else if (ship.position.x > width + textureWidth / 4.0f)
		{
			ship.position.x = 0.0f;
		}
		if (ship.position.y < 0.0f - textureHeight)
		{
			ship.position.y = height + textureHeight / 2;
		}
		else if (ship.position.y > height + textureHeight / 2)
		{
			ship.position.y = 0.0f - textureHeight / 2;
		}
	}
	void warpOutOfBounds(GameObjects::Asteroid& asteroid)
	{
		float width = static_cast<float>(GetScreenWidth());
		float height = static_cast<float>(GetScreenHeight());
		float textureWidth = static_cast<float>(asteroid.texture.width);
		float textureHeight = static_cast<float>(asteroid.texture.height);
		if (asteroid.circle.position.x < 0.0f - textureWidth)
		{
			asteroid.circle.position.x = width;
		}
		else if (asteroid.circle.position.x > width)
		{
			asteroid.circle.position.x = 0 - textureWidth;
		}
		if (asteroid.circle.position.y < 0 - textureHeight)
		{
			asteroid.circle.position.y = height;
		}
		else if (asteroid.circle.position.y > height)
			asteroid.circle.position.y = 0 - height;
	}
	void warpOutOfBounds(GameObjects::Bullet& bullet)
	{
		float width = static_cast<float>(GetScreenWidth());
		float height = static_cast<float>(GetScreenHeight());
		if ((bullet.circle.position.x < 0 - bullet.texture.width) || (bullet.circle.position.x > width) || (bullet.circle.position.y < 0 - bullet.texture.width) || (bullet.circle.position.y > height))
		{
			deactivateBullet(bullet);
		}

	}
	void moveSpaceShip(SpaceShip& ship)
	{
		ship.direction = GameLogic::getSpaceShipDirection(ship);
		ship.rotation = GameLogic::getSpaceShipRotation(ship.direction);

		if (abs(ship.direction.x) < ship.circle.radius)
		{
			ship.direction.x = 0.0f;
		}
		if (abs(ship.direction.y) < ship.circle.radius)
		{
			ship.direction.y = 0.0f;
		}

		Vector2 normalizedDirection = Vector2Normalize(ship.direction);

		if (Inputs::isMouseKeyDown(MOUSE_BUTTON_RIGHT))
		{

			ship.aceleration.x += normalizedDirection.x * GetFrameTime() * ship.maxSpeed;
			ship.aceleration.y += normalizedDirection.y * GetFrameTime() * ship.maxSpeed;
			ship.textureIndex += ship.texture.width / 4;
			if (ship.textureIndex > ship.texture.width)
			{
				ship.textureIndex = 64;
			}

		}
		else if (!Inputs::isMouseKeyDown(MOUSE_BUTTON_LEFT))
		{
			ship.textureIndex = 0;
		}

		if (ship.aceleration.x > ship.maxSpeed)
		{
			ship.aceleration.x = ship.maxSpeed;
		}
		else if (ship.aceleration.x < -ship.maxSpeed)
		{
			ship.aceleration.x = -ship.maxSpeed;
		}
		if (ship.aceleration.y > ship.maxSpeed)
		{
			ship.aceleration.y = ship.maxSpeed;
		}
		else if (ship.aceleration.y < -ship.maxSpeed)
		{
			ship.aceleration.y = -ship.maxSpeed;
		}




		warpOutOfBounds(ship);
		for (int i = 0; i < 10; ++i)
		{
			warpOutOfBounds(ship.bullet[i]);

		}
	}
	void updateCurrentSpaceShipPos(SpaceShip ship)
	{
		GameLogic::currentShipPos = { ship.dest.x, ship.dest.y };
	}
	void rotateAsteroidTowardSpaceShip(GameObjects::Asteroid& asteroid)
	{
		Vector2 direction = { asteroid.circle.position.x - GameLogic::currentShipPos.x, asteroid.circle.position.y - GameLogic::currentShipPos.y };
		float grades = (atan(direction.y / direction.x)) * (180 / PI);
		if (direction.x < 0)
		{
			grades += 180;
		}
		asteroid.rotation = grades;
	}
	void moveAsteroidAcrossScreen(GameObjects::Asteroid& asteroid)
	{
		rotateAsteroidTowardSpaceShip(asteroid);


		warpOutOfBounds(asteroid);
	}

}