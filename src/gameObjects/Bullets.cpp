#include "Bullets.h"
#include "../gameLogic/movementLogic.h"

Asteroids::Bullet createBullet()
{
	Asteroids::Bullet bullet;
	bullet.type = Asteroids::BulletType::Default;
	bullet.isActive = false;
	bullet.aceleration = { 0,0 };
	bullet.circle.position = { 0,0 };
	bullet.circle.radius = { 5 };
	return bullet;
}

void moveBullet(Asteroids::Bullet& bullet)
{
	bullet.circle.position.x += bullet.aceleration.x * GetFrameTime();
	bullet.circle.position.y += bullet.aceleration.y * GetFrameTime();
}

void updateBullet(Asteroids::Bullet& bullet,SpaceShip ship)
{
	if (!bullet.isActive)
	{
		bullet.aceleration = { 0,0 };
		bullet.circle.position = { ship.dest.x, ship.dest.y };
	}
}
void deactivateBullet(Asteroids::Bullet& bullet)
{
	bullet.isActive = false;
}
void activateBullet(Asteroids::Bullet& bullet, SpaceShip ship)
{
	bullet.isActive = true;
	bullet.aceleration()
}
void resetBulletPosition(Asteroids::Bullet& bullet, SpaceShip ship)
{
	
}