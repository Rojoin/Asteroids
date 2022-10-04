#include "shootLogic.h"

#include "mouseInputs.h"
#include "../gameObjects/spaceShip.h"


using namespace GameObjects;


void shootBullets()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		activateBullet();
	}
}
