#pragma once
#include "raylib.h"
#include "raymath.h"
#include "../gameObjects/spaceShip.h"
#include "../gameLogic/mouseInputs.h"


void moveSpaceShip(SpaceShip& spaceShip);
void warpSpaceShipOutOfBounds(SpaceShip& spaceShip);