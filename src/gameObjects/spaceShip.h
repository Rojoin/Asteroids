#pragma once
#include <raylib.h>
#include "Bullets.h"

namespace GameObjects
{


	struct SpaceShip
	{
		Vector2 position;
		Bullet bullet[20];
		BulletType bulletType;
		int bulletIndex = 0;
		Vector2 aceleration;
		Texture2D texture;
		int textureIndex;
		float rotation;
		float scale;
		float maxSpeed;
		float score;
		int lives;
		bool isDead;
		Sound deathSound;
		Rectangle source;
		Rectangle dest;
		Circle circle;
		Vector2 direction;
	};

	SpaceShip initSpaceShip( Vector2 position, float rotation, float scale);

	void updateShip();
	void drawShip();
	void changeShipPosition();
	void updateBullet();
	void updateShootTimer();
	void activateBullet();
	void deactivateBullet(GameObjects::Bullet& bullet);
	void resetSpaceShip(SpaceShip& ship, Vector2 position);
	void activatetBulletPowerUp();
	void deActivateBulletPowerUp();
	void initBullets();
	void drawShipDestruction();

}
