#include <raylib.h>
#include "powerUp.h"
#include "system/draw.h"


Texture2D powerUpSniperTexture;
Texture2D powerUpPiercingTexture;
namespace GameObjects
{
	
	PowerUp createPowerUpPiercing(float timer)
	{
		PowerUp powerUp;
		powerUp.texture = powerUpPiercingTexture;
		powerUp.circle = { {0,0},20 };
		powerUp.timer = timer;
		powerUp.type = BulletType::Piercing;
		powerUp.scale = 2;
		powerUp.timerActive = DEFAULT_TIMER;
		powerUp.isActive = false;
		powerUp.isSpawned = false;

		return powerUp;
	}
	PowerUp createPowerUpSniper(float timer)
	{
		PowerUp powerUp;
		powerUp.texture = powerUpSniperTexture;
		powerUp.circle = { {0,0},20 };
		powerUp.timer = timer;
		powerUp.type = BulletType::Sniper;
		powerUp.scale = 2;
		powerUp.timerActive = DEFAULT_TIMER;
		powerUp.isActive = false;
		powerUp.isSpawned = false;

		return powerUp;
	}

	void drawPowerUp(PowerUp powerUp)
	{
		float width = static_cast<float>(powerUp.texture.width);
		float height = static_cast<float>(powerUp.texture.height);
		Rectangle source ={0,0,width,height};
		Rectangle dest{ powerUp.circle.position.x  ,powerUp.circle.position.y,width  * powerUp.scale ,height * powerUp.scale  };
		Vector2 pos = { static_cast<float>(powerUp.texture.width) / 2.0f,static_cast<float>(powerUp.texture.height) / 2.0f };
#if _DEBUG
		//DrawCircle(static_cast<int>(powerUp.circle.position.x), static_cast<int>(powerUp.circle.position.y), powerUp.circle.radius, BLUE);
#endif
		drawTexture(powerUp.texture, source, dest, pos, 0, powerUp.scale, WHITE);
	}
	BulletType activatePowerUp(PowerUp& powerUp)
	{
		powerUp.isSpawned = false;
		powerUp.isActive = true;
		return powerUp.type;
	}
	void deactivatePowerUp(PowerUp& powerUp)
	{
		float timer = static_cast<float>(GetRandomValue(20, 40));
		powerUp.isActive = false;
		powerUp.timer = timer;
		powerUp.timerActive = DEFAULT_TIMER;
	}
	void randomSpawn(PowerUp& powerUp)
	{
		int spawn = GetRandomValue(1, 4);
		float width = static_cast<float>(GetScreenWidth());
		float height = static_cast<float>(GetScreenHeight());
		powerUp.isSpawned = true;
		powerUp.timerActive = DEFAULT_TIMER;
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

	



}

