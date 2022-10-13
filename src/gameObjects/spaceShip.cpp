#include  "spaceShip.h"

#include <iostream>
#include <raymath.h>

#include "system/draw.h"

GameObjects::SpaceShip spaceShip;
Sound deathSound;
Texture2D shipTexture;
static float shootTime;
static float currentTimer = 0.0f;
static float destructionIndex;
namespace GameObjects
{

	SpaceShip initSpaceShip(Vector2 position, float rotation, float scale)
	{
		scale *= static_cast<float>(GetScreenHeight()) / 768;
		SpaceShip ship;
		ship.score = 0;
		ship.position = position;
		ship.bulletType = BulletType::Default;
		ship.texture = shipTexture;
		ship.aceleration = { 0,0 };
		ship.scale = scale ;
		ship.deathSound = deathSound;
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

	void initBullets()
	{

		for (int i = 0; i < maxBullets; i++)
		{
			spaceShip.bullet[i] = GameObjects::createBullet(spaceShip.dest.x, spaceShip.dest.y);
			deactivateBullet(spaceShip.bullet[i]);
		}
		spaceShip.bulletIndex = 0;
		spaceShip.bulletType = BulletType::Default;
	}


	void activatetBulletPowerUp()
	{
		spaceShip.bulletType = BulletType::Piercing;

	}
	void deActivateBulletPowerUp()
	{
		spaceShip.bulletType = BulletType::Default;
	}

	void drawShipDestruction()
	{
		float shipHeight = static_cast<float>(spaceShip.texture.height);
		
		spaceShip.source.y = shipHeight/2;
		spaceShip.source.x = 0;
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
		if (spaceShip.isDead)
		{
			static float animTimer = 0.5f;
			drawShipDestruction();
			
			if (spaceShip.source.x > spaceShip.texture.width)
			{
				spaceShip.source.x = 0;
			}
			animTimer -= GetFrameTime();
			if (animTimer <= 0)
			{
				destructionIndex += spaceShip.texture.width / 4;
				if (spaceShip.source.x > spaceShip.texture.width)
				{
					spaceShip.source.x = 0;
					spaceShip.isDead = false;
				}
				animTimer = 0.5f;
			}
			spaceShip.circle = { spaceShip.position.x,spaceShip.position.y,spaceShip.circle.radius };

			spaceShip.source = { spaceShip.source.x + destructionIndex,spaceShip.source.y ,spaceShip.source.width,spaceShip.source.height };
			spaceShip.dest = { spaceShip.position.x,spaceShip.position.y + spaceShip.texture.height / 32.0f ,spaceShip.dest.width,spaceShip.dest.height };
			
		}
	}

	void changeShipPosition()
	{
		spaceShip.position = { spaceShip.position.x + spaceShip.aceleration.x * GetFrameTime()*  static_cast<float>(GetScreenWidth()) / 1024 ,spaceShip.position.y + spaceShip.aceleration.y * GetFrameTime()*static_cast<float>(GetScreenHeight()) / 768 };
	}

	void updateBullet()
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (!spaceShip.bullet[i].isActive)
			{

				if (spaceShip.bullet[i].type != spaceShip.bulletType)
				{
					switch (spaceShip.bulletType)
					{
					case BulletType::Default:
						spaceShip.bullet[i] = createBullet(spaceShip.dest.x, spaceShip.dest.y);
						break;
					case BulletType::Sniper:
						spaceShip.bullet[i] = createSniperBullet(spaceShip.dest.x, spaceShip.dest.y);
						break;
					case BulletType::Piercing:
						spaceShip.bullet[i] = createPiercingBullet(spaceShip.dest.x, spaceShip.dest.y);
						break;
					default:;
					}
				}
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
	void updateShootTimer()
	{

		switch (spaceShip.bullet[spaceShip.bulletIndex].type)
		{
		case BulletType::Default:
			shootTime = 0.5f;
			break;
		case BulletType::Sniper:

			shootTime = 0.1f;
			break;
		case BulletType::Piercing:
			shootTime = 1.5f;
			break;
		}
		currentTimer += GetFrameTime();
	}
	void activateBullet()
	{

		if (!spaceShip.bullet[spaceShip.bulletIndex].isActive && currentTimer >= shootTime)
		{
			updateBullet();
			PlaySound(spaceShip.bullet[spaceShip.bulletIndex].sound);
			spaceShip.bullet[spaceShip.bulletIndex].isActive = true;
			Vector2 normalizedVector = Vector2Normalize(spaceShip.direction);
			spaceShip.bullet[spaceShip.bulletIndex].aceleration.x += normalizedVector.x;
			spaceShip.bullet[spaceShip.bulletIndex].aceleration.y += normalizedVector.y;
			spaceShip.bulletIndex++;
			std::cout << spaceShip.bulletIndex <<std::endl;
			if (spaceShip.bulletIndex == maxBullets)
			{
				spaceShip.bulletIndex = 0;
			}
			currentTimer = 0.0f;
		}
	}
}
