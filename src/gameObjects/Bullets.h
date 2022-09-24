#pragma once
#include <raylib.h>
#include "../system/circle.h"
#include "GameObjectsEnums.h"
#include "spaceShip.h"

namespace GameObjects
{

	struct Bullet
	{
		GameObjects::BulletType type;
		Texture2D texture;
		Circle circle;
		Vector2 aceleration;
		float rotation;
		bool isActive;

	};
	Bullet createBullet();
	void moveBullet(Bullet& bullet);
	void updateBullet(GameObjects::Bullet& bullet, SpaceShip ship);
	void deactivateBullet(Bullet& bullet);
	void activateBullet(Bullet& bullet, SpaceShip ship);
	void resetBulletPosition(Bullet& bullet, SpaceShip ship);
	void drawBullet(Bullet& bullet);
	const float bulletMaxSpeed = 500.0f;
}


