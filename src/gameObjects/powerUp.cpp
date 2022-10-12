#include <raylib.h>
#include "PowerUp.h"
#include "system/draw.h"

namespace GameObjects
{

	PowerUp createPowerUp(float timer, float timerActive, BulletType type)
	{
		PowerUp powerUp;

		powerUp.circle = { {0,0},50 };
		powerUp.timer = timer;
		powerUp.type = type;
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
		powerUp = createPowerUp(timer, timerActive,powerUp.type);
		powerUp.isSpawned = true;

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

