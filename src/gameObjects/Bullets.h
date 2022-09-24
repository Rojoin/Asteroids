#pragma once
#include <raylib.h>

#include "GameObjectsEnums.h"

struct Bullets
{
	Asteroids::BulletType type;
	Vector2 position;
	float size;
	bool isActive;
	

};

