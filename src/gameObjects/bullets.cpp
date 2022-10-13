#include "Bullets.h"
#include "gameLogic/movementLogic.h"
#include "system/draw.h"

Sound bulletDefaultSound;
Sound bulletSniperSound;
Sound bulletPiercingSound;
 Texture2D bulletTexture;
 Texture2D bulletPiercingTexture;
 Texture2D bulletSniperTexture;
namespace GameObjects
{
	Bullet createBullet(float x, float y)
	{
		Bullet bullet;
		bullet.type = GameObjects::BulletType::Default;
		bullet.isActive = false;
		bullet.aceleration = { 0,0 };
		bullet.circle = { {x,y},  10 };
		bullet.rotation = 0;
		bullet.speed = 300;
		bullet.scale = 1.0f;
		bullet.sound = bulletDefaultSound;
		bullet.texture = bulletTexture;
		bullet.circle.radius *= bullet.scale;
		return bullet;
	}
	Bullet createSniperBullet(float x, float y)
	{
		Bullet bullet;
		bullet.type = GameObjects::BulletType::Sniper;
		bullet.isActive = false;
		bullet.aceleration = { 0,0 };
		bullet.circle = {{ x,y },10};
		bullet.rotation = 0;
		bullet.speed = 500;
		bullet.scale = 2.0f;
		bullet.sound = bulletSniperSound;
		bullet.texture = bulletSniperTexture;
		bullet.circle.radius *= bullet.scale;
		return bullet;
	}
	Bullet createPiercingBullet(float x, float y)
	{
		Bullet bullet;
		bullet.type = GameObjects::BulletType::Piercing;
		bullet.isActive = false;
		bullet.aceleration = { 0,0 };
		bullet.circle = {{ x,y },10};
		bullet.rotation = 0;
		bullet.speed = 100;
		bullet.scale = 5.0f;
		bullet.sound = bulletPiercingSound;
		bullet.texture = bulletPiercingTexture;
		bullet.circle.radius *= bullet.scale;
		return bullet;
	}
	void changeBulletPosition(GameObjects::Bullet& bullet)
	{
		bullet.circle.position.x += bullet.aceleration.x * bullet.speed * GetFrameTime();
		bullet.circle.position.y += bullet.aceleration.y * bullet.speed * GetFrameTime();

	}


	void drawBullet(GameObjects::Bullet& bullet)
	{
		if (bullet.isActive)
		{
			
		Rectangle source{ 0,0,static_cast<float>(bullet.texture.width),static_cast<float>(bullet.texture.height) };
		Rectangle dest{ bullet.circle.position.x  ,bullet.circle.position.y,static_cast<float>(bullet.texture.width)*bullet.scale,static_cast<float>(bullet.texture.height)*bullet.scale  };

#if _DEBUG

		//DrawCircle(static_cast<int>(bullet.circle.position.x), static_cast<int>(bullet.circle.position.y), bullet.circle.radius, BLUE);
#endif
		drawTexture(bullet.texture, source, dest, { static_cast<float>(bullet.texture.width) / 2.0f,static_cast<float>(bullet.texture.height) / 2.0f }, bullet.rotation, bullet.scale, WHITE);
		}

	}



}