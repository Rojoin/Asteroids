#include "PowerUp.h"
#include "system/draw.h"



PowerUp createPowerUp(float timer, float timerActive)
{
	PowerUp powerUp;
	powerUp.rec = { 0, 0, 100, 100 };
	powerUp.timer = timer;
	powerUp.timerActive = timerActive;
	powerUp.isActive = false;
	powerUp.isSpawned = false;
	return powerUp;
}
void drawPowerUp(PowerUp powerUp)
{
	Vector2 pos = { powerUp.rec.x,powerUp.rec.y };
	drawTexture(powerUp.texture,pos,0,1,WHITE);

}
void randomSpawn(PowerUp& powerUp,float timer, float timerActive)
{
	int spawn = GetRandomValue(1, 4);
	float width = static_cast<float>(GetScreenWidth());
	float height = static_cast<float>(GetScreenHeight());
	powerUp = createPowerUp(timer,timerActive);
	powerUp.isSpawned = true;
	switch (spawn)
	{
	case 1:
		powerUp.rec.x = width /4;
		powerUp.rec.y = height /4;
		break;
	case 2:
		powerUp.rec.x = width /4  ;
		powerUp.rec.y = (height / 4) *3;
		break;
	case 3:
		powerUp.rec.x = (width / 4)*3;
		powerUp.rec.y = (height / 4) * 3;
		break;
	case 4:
		powerUp.rec.x = (width / 4 )* 3;
		powerUp.rec.y = (height / 4);
		break;
	}
}

void setPowerUpTimer(PowerUp& powerUp,float timer)
{
	powerUp.timer = timer;
}



