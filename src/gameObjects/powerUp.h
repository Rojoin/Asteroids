#pragma once
#include <raylib.h>

#include "GameObjectsEnums.h"
#include "system/circle.h"

namespace GameObjects
{

	struct PowerUp
	{
		Circle circle;
		Texture2D texture;
		BulletType type;
		float timer;
		float timerActive;
		float scale;
		bool isActive;
		bool isSpawned;
	};

	PowerUp createPowerUp(float timer, float timerActive,BulletType type);
	void randomSpawn(PowerUp& powerUp, float timer, float timerActive);
	void setPowerUpTimer(PowerUp& powerUp, float timer);
	void drawPowerUp(PowerUp powerUp);
}