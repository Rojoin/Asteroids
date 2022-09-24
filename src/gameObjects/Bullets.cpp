#include "Bullets.h"
#include "../gameLogic/movementLogic.h"
#include "../system/draw.h"

namespace Asteroids
{
	Bullet createBullet()
	{
		Asteroids::Bullet bullet;
		bullet.type = Asteroids::BulletType::Default;
		bullet.isActive = false;
		bullet.aceleration = { 0,0 };
		bullet.circle.position = { 0,0 };
		bullet.circle.radius = { 10 };
		bullet.rotation = 0;
		return bullet;
	}

	void moveBullet(Asteroids::Bullet& bullet)
	{
		bullet.circle.position.x += bullet.aceleration.x *bulletMaxSpeed* GetFrameTime();
		bullet.circle.position.y += bullet.aceleration.y *bulletMaxSpeed* GetFrameTime();
	}

	void updateBullet(Asteroids::Bullet& bullet, SpaceShip ship)
	{
	
		if (!bullet.isActive)
		{
			bullet.rotation = ship.rotation;
			bullet.aceleration = { 0,0 };
			bullet.circle.position = { ship.dest.x, ship.dest.y };
		}
	}
	void deactivateBullet(Asteroids::Bullet& bullet)
	{
		bullet.isActive = false;
	}
	void activateBullet(Asteroids::Bullet& bullet, SpaceShip ship)
	{
		if (!bullet.isActive)
		{
			updateBullet(bullet, ship);
		bullet.isActive = true;
		Vector2 normalizedVector = Vector2Normalize(getSpaceShipDirection(ship));
		bullet.aceleration.x += normalizedVector.x;
		bullet.aceleration.y += normalizedVector.y;
		}
		

	}
	void resetBulletPosition(Asteroids::Bullet& bullet, SpaceShip ship)
	{
		deactivateBullet(bullet);
		bullet.aceleration = { 0,0 };
		bullet.circle.position = { ship.dest.x, ship.dest.y };
	}
	void drawBullet(Asteroids::Bullet& bullet)
	{
		Rectangle source{0,0,(float)bullet.texture.width,(float)bullet.texture.height};
		Rectangle dest{ bullet.circle.position.x  ,bullet.circle.position.y,(float)bullet.texture.width,(float)bullet.texture.height };
		
		drawTexture(bullet.texture,source,dest	, { bullet.texture.width /2.0f,bullet.texture.height / 2.0f },bullet.rotation,1,RED);
	
	}



}