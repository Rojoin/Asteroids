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

	PowerUp createPowerUpPiercing(float timer);
	PowerUp createPowerUpSniper(float timer);
	BulletType activatePowerUp(PowerUp& powerUp);
	void deactivatePowerUp(PowerUp& powerUp);
	void randomSpawn(PowerUp& powerUp);
	void drawPowerUp(PowerUp powerUp);
	const float DEFAULT_TIMER = 7.0f;
}