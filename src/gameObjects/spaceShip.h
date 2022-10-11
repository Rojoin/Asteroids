#pragma once
#include <raylib.h>
#include "Bullets.h"



	struct SpaceShip
	{
		Vector2 position;
		GameObjects::Bullet bullet[20];
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

	SpaceShip initSpaceShip(Texture2D texture, Vector2 position, float rotation, float scale, Sound sound);

	void updateShip();
	void drawShip();
	void changeShipPosition();
	void updateBullet();
	void deactivateBullet(GameObjects::Bullet& bullet);
	void activateBullet();
	void resetSpaceShip(SpaceShip& ship, Vector2 position);
	void initBullets(Texture2D bulletTexture, Sound sound);
	void drawShipDestruction();

