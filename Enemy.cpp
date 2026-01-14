#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy()
{
	posX = 400;
	posY = 300;
	speed = 5;
	radius = 20;
	isAlive = true;
	respawnTime = 60;
}

void Enemy::Update()
{
	posX += speed;

	if (posX + radius > 1280)
	{
		speed *= -1;
	}

	if (posX - radius < 0)
	{
		speed *= -1;
	}



}


void Enemy::Draw()
{
	Novice::DrawEllipse(
		posX, posY,
		radius, radius,
		0.0f,
		RED,
		kFillModeSolid
	);
}
