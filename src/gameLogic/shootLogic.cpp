#include "shootLogic.h"

#include "mouseInputs.h"


using namespace GameObjects;

void shootBullets(SpaceShip& ship)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		activateBullet();
	}
}
