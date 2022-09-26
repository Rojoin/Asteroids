#pragma once
#include <raylib.h>
#include "../system/circle.h"
#include "GameObjectsEnums.h"


namespace GameObjects
{

	struct Bullet
	{
		GameObjects::BulletType type;
		Texture2D texture;
		Circle circle;
		Vector2 aceleration;
		Sound sound;
		float rotation;
		bool isActive;

	};
	Bullet createBullet(float x, float y);
	void changeBulletPosition(Bullet& bullet);
	//void updateBullet(Bullet& bullet,SpaceShip ship);
	//void deactivateBullet(Bullet& bullet);
	//void activateBullet(Bullet& bullet, SpaceShip ship);
	//void resetBulletPosition(Bullet& bullet, SpaceShip ship);
	void drawBullet(Bullet& bullet);
	const float BULLET_MAX_SPEED = 500.0f;
}


