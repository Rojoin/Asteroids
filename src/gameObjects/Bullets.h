#pragma once
#include <raylib.h>
#include "../system/circle.h"
#include "GameObjectsEnums.h"
#include "spaceShip.h"

namespace Asteroids
{
	
struct Bullet
{
	Asteroids::BulletType type;
	Texture2D texture;
	Circle circle;
	Vector2 aceleration;
	bool isActive;

};

void moveBullet(Bullet& bullet);

void deactivateBullet(Bullet& bullet);
void activateBullet(Bullet& bullet,SpaceShip ship);
void resetBulletPosition(Bullet& bullet, SpaceShip ship);

}


