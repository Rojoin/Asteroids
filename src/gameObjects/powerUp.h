#pragma once
#include <raylib.h>

struct PowerUp
{
	Rectangle rec;
	Texture2D texture;
	float timer;
	float timerActive;
	bool isActive;
	bool isSpawned;
};

PowerUp createPowerUp(float timer, float timerActive);
void randomSpawn(PowerUp& powerUp, float timer, float timerActive);
void setPowerUpTimer(PowerUp& powerUp, float timer);
void drawPowerUp(PowerUp powerUp);