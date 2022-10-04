#include "Bullets.h"
#include "../gameLogic/movementLogic.h"
#include "../system/draw.h"


namespace GameObjects
{
	Bullet createBullet(float x, float y)
	{
		GameObjects::Bullet bullet;
		bullet.type = GameObjects::BulletType::Default;
		bullet.isActive = false;
		bullet.aceleration = { 0,0 };
		bullet.circle.position = { x,y };
		bullet.circle.radius = { 10 };
		bullet.rotation = 0;
		
		return bullet;
	}

	void changeBulletPosition(GameObjects::Bullet& bullet)
	{
		bullet.circle.position.x += bullet.aceleration.x *BULLET_MAX_SPEED* GetFrameTime();
		bullet.circle.position.y += bullet.aceleration.y *BULLET_MAX_SPEED* GetFrameTime();
	}

	
	void drawBullet(GameObjects::Bullet& bullet)
	{

		Rectangle source{0,0,static_cast<float>(bullet.texture.width),static_cast<float>(bullet.texture.height)};
		Rectangle dest{ bullet.circle.position.x  ,bullet.circle.position.y,static_cast<float>(bullet.texture.width),static_cast<float>(bullet.texture.height)  };
		
#if _DEBUG
		DrawCircle(bullet.circle.position.x,bullet.circle.position.y,bullet.circle.radius, BLUE);
#endif
		drawTexture(bullet.texture,source,dest	, { bullet.texture.width /2.0f,bullet.texture.height / 2.0f },bullet.rotation, 1,WHITE);

	}



}