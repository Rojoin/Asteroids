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

	void moveBullet(GameObjects::Bullet& bullet)
	{
		bullet.circle.position.x += bullet.aceleration.x *BULLET_MAX_SPEED* GetFrameTime();
		bullet.circle.position.y += bullet.aceleration.y *BULLET_MAX_SPEED* GetFrameTime();
	}

	//void updateBullet(GameObjects::Bullet& bullet, SpaceShip ship)
	//{
	//
	//	if (!bullet.isActive)
	//	{
	//		bullet.rotation = ship.rotation;
	//		bullet.aceleration = { 0,0 };
	//		bullet.circle.position = { ship.dest.x, ship.dest.y };
	//	}
	//}
	//void deactivateBullet(GameObjects::Bullet& bullet)
	//{
	//	bullet.isActive = false;
	//}
	//void activateBullet(GameObjects::Bullet& bullet, SpaceShip ship)
	//{
	//	if (!bullet.isActive)
	//	{
	//		updateBullet(bullet, ship);
	//	bullet.isActive = true;
	//	Vector2 normalizedVector = Vector2Normalize(GameLogic::getSpaceShipDirection(ship));
	//	bullet.aceleration.x += normalizedVector.x;
	//	bullet.aceleration.y += normalizedVector.y;
	//	}
	//	

	//}
	//void resetBulletPosition(GameObjects::Bullet& bullet, SpaceShip ship)
	//{
	//	deactivateBullet(bullet);
	//	bullet.aceleration = { 0,0 };
	//	bullet.circle.position = { ship.dest.x, ship.dest.y };
	//}
	void drawBullet(GameObjects::Bullet& bullet)
	{

		Rectangle source{0,0,(float)bullet.texture.width,(float)bullet.texture.height};
		Rectangle dest{ bullet.circle.position.x  ,bullet.circle.position.y,(float)bullet.texture.width*2,(float)bullet.texture.height * 2 };
		
		drawTexture(bullet.texture,source,dest	, { bullet.texture.width /2.0f,bullet.texture.height / 2.0f },bullet.rotation,2,WHITE);
		//DrawCircle(bullet.circle.position.x,bullet.circle.position.y,bullet.circle.radius, BLUE);
	}



}