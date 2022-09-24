#pragma once
#include <raylib.h>


struct SpaceShip
{
	Vector2 position;
	Vector2 aceleration;
	Texture2D texture;
	float rotation;
	float scale;
	float maxSpeed;
	Rectangle source;
	Rectangle dest;


};


SpaceShip initSpaceShip(Texture2D texture, Vector2 position, float rotation, float scale);

void updateShip();
void drawShip();
void changeShipPosition();
 

