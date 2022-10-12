#include <raylib.h>
#include "PowerUp.h"
#include "system/draw.h"


Texture2D powerUpSniperTexture;
Texture2D powerUpPiercingTexture;
namespace GameObjects
{
	
	PowerUp createPowerUpPiercing(float timer, float timerActive)
	{
		PowerUp powerUp;
		powerUp.texture = powerUpPiercingTexture;
		powerUp.circle = { {0,0},50 };
		powerUp.timer = timer;
		powerUp.type = BulletType::Piercing;
		powerUp.scale = 1;
		powerUp.timerActive = timerActive;
		powerUp.isActive = false;
		powerUp.isSpawned = false;

		return powerUp;
	}
	PowerUp createPowerUpSniper(float timer, float timerActive)
	{
		PowerUp powerUp;
		powerUp.texture = powerUpSniperTexture;
		powerUp.circle = { {0,0},50 };
		powerUp.timer = timer;
		powerUp.type = BulletType::Sniper;
		powerUp.scale = 1;
		powerUp.timerActive = timerActive;
		powerUp.isActive = false;
		powerUp.isSpawned = false;

		return powerUp;
	}

	void drawPowerUp(PowerUp powerUp)
	{
#if _DEBUG
		DrawCircle(static_cast<int>(powerUp.circle.position.x), static_cast<int>(powerUp.circle.position.y), powerUp.circle.radius, BLUE);
#endif
		drawTexture(powerUp.texture, powerUp.circle.position, 0, powerUp.scale, WHITE);
	}

	void randomSpawn(PowerUp& powerUp, float timer, float timerActive)
	{
		int spawn = GetRandomValue(1, 4);
		float width = static_cast<float>(GetScreenWidth());
		float height = static_cast<float>(GetScreenHeight());
		powerUp.isSpawned = true;
		timer = 0;
		timerActive = 0;
		switch (spawn)
		{
		case 1:
			powerUp.circle.position.x = width / 4;
			powerUp.circle.position.y = height / 4;
			break;
		case 2:
			powerUp.circle.position.x = width / 4;
			powerUp.circle.position.y = (height / 4) * 3;
			break;
		case 3:
			powerUp.circle.position.x = (width / 4) * 3;
			powerUp.circle.position.y = (height / 4) * 3;
			break;
		case 4:
			powerUp.circle.position.x = (width / 4) * 3;
			powerUp.circle.position.y = (height / 4);
			break;
		}
	}

	
	void setPowerUpTimer(PowerUp& powerUp, float timer)
	{
		powerUp.timer = timer;
	}


}

