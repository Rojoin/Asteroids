#pragma once
#include "GameObjectsEnums.h"
#include "../system/circle.h"


namespace GameObjects
{
	struct Asteroid
	{
		GameObjects::AsteroidType type;
		Texture2D texture;
		Circle circle;
		Vector2 aceleration;
		float rotation;
		bool isActive;
	};
}