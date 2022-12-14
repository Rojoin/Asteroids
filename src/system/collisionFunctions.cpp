#include "collisionFunctions.h"

#include <iostream>

#include  "cmath"

bool isCircleCircleColliding(Circle circle1, Circle circle2)
{
	
	float distanceY = circle1.position.y -circle2.position.y;
	float distanceX = circle1.position.x -circle2.position.x;
	float distance = sqrt((distanceX* distanceX) + (distanceY*distanceY));

 	if (distance < circle1.radius + circle2.radius)
	{
		return true;
	}
	return false;
	
}

bool isPointRecColliding(Vector2 mouse, Rectangle rec) //Check if works
{
	float rightEdge = rec.x + rec.width ;
	float leftEdge = rec.x;
	float upEdge = rec.y;
	float downEdge = rec.y + rec.height;

	if (mouse.x <= rightEdge && mouse.x >= leftEdge && mouse.y >= upEdge && mouse.y <= downEdge)
	{
		return true;
	}
	else
	{
		return false;
	}
}
