#pragma once
#include "raylib.h"
#include "raymath.h"
#include "../gameObjects/spaceShip.h"
#include "../gameObjects/Asteroid.h"
#include "../gameLogic/mouseInputs.h"

float getSpaceShipRotation(Vector2 direction);
Vector2 getSpaceShipDirection(SpaceShip ship);
void moveSpaceShip(SpaceShip& spaceShip);
void warpOutOfBounds(SpaceShip& spaceShip);
void moveAsteroidAcrossScreen(GameObjects::Asteroid& asteroid);