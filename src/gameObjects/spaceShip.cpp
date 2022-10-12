#include  "spaceShip.h"

#include <raymath.h>

#include "system/draw.h"

	GameObjects::SpaceShip spaceShip;
namespace GameObjects
{

	SpaceShip initSpaceShip(Texture2D texture, Vector2 position, float rotation, float scale, Sound sound)
	{
		SpaceShip ship;
		ship.score = 0;
		ship.texture = texture;
		ship.position = position;
		ship.aceleration = { 0,0 };
		ship.scale = scale;
		ship.deathSound = sound;
		ship.rotation = rotation;
		ship.lives = 3;
		ship.isDead = false;
		ship.maxSpeed = 200.0f;
		ship.bulletIndex = 0;
		ship.circle = { ship.position.x,ship.position.y,ship.scale * ship.texture.width / 8 };
		ship.source = { 0,0,(float)ship.texture.width / 4,(float)ship.texture.height / 2 };
		ship.dest = { position.x,position.y,(float)ship.texture.width / 4 * scale,(float)ship.texture.height / 2 * scale };
		return ship;
	}

	void resetSpaceShip(SpaceShip& ship, Vector2 position)
	{
		PlaySound(ship.deathSound);
		ship.position = position;
		ship.lives--;
		ship.aceleration = { 0,0 };
		ship.circle = { ship.position.x,ship.position.y,ship.scale * ship.texture.width / 8 };
		ship.source = { 0,0,static_cast<float>(ship.texture.width) / 4,static_cast<float>(ship.texture.height) / 2 };
		ship.dest = { position.x,position.y,static_cast<float>(ship.texture.width) / 4 * ship.scale,static_cast<float>(ship.texture.height) / 2 * ship.scale };
	}

	void initBullets(Texture2D bulletTexture, Sound sound)
	{
		for (int i = 0; i < 10; i++)
		{
			spaceShip.bullet[i] = GameObjects::createBullet(spaceShip.dest.x, spaceShip.dest.y);
			spaceShip.bullet[i].texture = bulletTexture;
			spaceShip.bullet[i].sound = sound;
			deactivateBullet(spaceShip.bullet[i]);
		}
	}

	void drawShipDestruction()
	{
		float shipHeight = static_cast<float>(spaceShip.texture.height);
		float shipWidth = static_cast<float>(spaceShip.texture.width);
		spaceShip.source = { 0,shipHeight/2,shipWidth / 4.0f,shipHeight / 2 };
	}

	void drawShip()
	{
#if _DEBUG

		DrawRectangle(static_cast<int>(spaceShip.position.x), static_cast<int>(spaceShip.position.y), 2, 2, BLUE);
		DrawCircle(static_cast<int>(spaceShip.circle.position.x), static_cast<int>(spaceShip.circle.position.y), spaceShip.circle.radius, RED);
#endif
		drawTexture(spaceShip.texture, spaceShip.source, spaceShip.dest, { static_cast<float>(spaceShip.texture.width) / 8.0f, static_cast<float>(spaceShip.texture.height) / 4.0f }, spaceShip.rotation, spaceShip.scale, WHITE);
	}

	void updateShip()
	{
		if (spaceShip.source.x > spaceShip.texture.width)
		{
			spaceShip.source.x = 0;
		}
		spaceShip.circle = { spaceShip.position.x,spaceShip.position.y,spaceShip.circle.radius };

		spaceShip.source = { spaceShip.source.x + spaceShip.textureIndex,spaceShip.source.y ,spaceShip.source.width,spaceShip.source.height };
		spaceShip.dest = { spaceShip.position.x,spaceShip.position.y + spaceShip.texture.height / 32.0f ,spaceShip.dest.width,spaceShip.dest.height };
	}

	void changeShipPosition()
	{
		spaceShip.position = { spaceShip.position.x + spaceShip.aceleration.x * GetFrameTime(),spaceShip.position.y + spaceShip.aceleration.y * GetFrameTime() };

	}

	void updateBullet()
	{
		for (int i = 0; i < 10; i++)
		{
			if (!spaceShip.bullet[i].isActive)
			{
				spaceShip.bullet[i].rotation = spaceShip.rotation;
				spaceShip.bullet[i].aceleration = { 0,0 };
				spaceShip.bullet[i].circle.position = { spaceShip.dest.x, spaceShip.dest.y };
			}
		}



	}

	void deactivateBullet(GameObjects::Bullet& bullet)
	{
		bullet.isActive = false;
	}

	void activateBullet()
	{
		if (!spaceShip.bullet[spaceShip.bulletIndex].isActive)
		{
			updateBullet();
			PlaySound(spaceShip.bullet[spaceShip.bulletIndex].sound);
			spaceShip.bullet[spaceShip.bulletIndex].isActive = true;
			Vector2 normalizedVector = Vector2Normalize(spaceShip.direction);
			spaceShip.bullet[spaceShip.bulletIndex].aceleration.x += normalizedVector.x;
			spaceShip.bullet[spaceShip.bulletIndex].aceleration.y += normalizedVector.y;
			spaceShip.bulletIndex++;
			if (spaceShip.bulletIndex > 9)	spaceShip.bulletIndex = 0;
		}
	}
}
