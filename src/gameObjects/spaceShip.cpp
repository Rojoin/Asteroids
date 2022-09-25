#include  "spaceShip.h"

#include <raymath.h>

#include "../system/draw.h"


SpaceShip spaceShip;


	SpaceShip initSpaceShip(Texture2D texture, Vector2 position, float rotation, float scale)
	{
		SpaceShip ship;

		ship.texture = texture;
		ship.position = position;
		ship.aceleration = { 0,0 };
		ship.scale = scale;
		ship.rotation = rotation;
		ship.maxSpeed = 200.0f;
		ship.bulletIndex = 0;
		ship.source = { 0,0,(float)ship.texture.width,(float)ship.texture.height };
		ship.dest = { 0,0,(float)ship.texture.width * scale,(float)ship.texture.height * scale };
		return ship;
	}

void initBullets()
	{
		for (int i = 0; i < 10; ++i)
		{
			spaceShip.bullet[i] = GameObjects::createBullet(spaceShip.dest.x,spaceShip.dest.y);
			spaceShip.bullet[i].texture = spaceShip.texture;
		}
			
	}
	void drawShip()
	{
		drawTexture(spaceShip.texture, spaceShip.source, spaceShip.dest, { spaceShip.texture.width / 2.0f, spaceShip.texture.height / 2.0f }, spaceShip.rotation, spaceShip.scale, WHITE);
	}
	void updateShip()
	{
		spaceShip.dest = { spaceShip.position.x + spaceShip.texture.width ,spaceShip.position.y + spaceShip.texture.height / 2.0f ,spaceShip.dest.width,spaceShip.dest.height };
	}
	void changeShipPosition()
	{
		spaceShip.position = { spaceShip.position.x + spaceShip.aceleration.x * GetFrameTime(),spaceShip.position.y + spaceShip.aceleration.y * GetFrameTime() };

	}

	void updateBullet()
	{
		for (int i = 0; i < 10; ++i)
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
			spaceShip.bullet[spaceShip.bulletIndex].isActive = true;
			Vector2 normalizedVector = Vector2Normalize(spaceShip.direction);
			spaceShip.bullet[spaceShip.bulletIndex].aceleration.x += normalizedVector.x;
			spaceShip.bullet[spaceShip.bulletIndex].aceleration.y += normalizedVector.y;
			spaceShip.bulletIndex++;
			if (spaceShip.bulletIndex>9 )	spaceShip.bulletIndex= 0;
		
		}


	}


